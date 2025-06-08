/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

#include "processing.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "../couche_acces_aux_donnees/CSVHandler.h"

using namespace std;

double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, int k, time_t start, time_t stop, const vector<Measurement *> *measures)
{

	vector<pair<double, const Measurement *>> distances;

	double max_dist = 10.0;
	for (const Measurement *m : *measures)
	{
		double dist = GetDistance(m, lat, lon);
		if (dist > max_dist)
			continue; // Ignore les mesures trop éloignées
		distances.push_back({dist, m});
	}

	sort(distances.begin(), distances.end(),
		 [](const pair<double, const Measurement *> &a, const pair<double, const Measurement *> &b)
		 { return a.first < b.first; });

	int count = min(k, static_cast<int>(distances.size()));
	double weighted_sum = 0.0;
	double weight_total = 0.0;

	for (int i = 0; i < count; ++i)
	{
		double dist = distances[i].first;
		double value = distances[i].second->GetValue();
		double weight = (dist == 0.0) ? 1e9 : 1.0 / dist;
		weighted_sum += value * weight;
		weight_total += weight;
	}

	if (weight_total == 0.0)
	{
		return numeric_limits<double>::quiet_NaN();
	}
	return weighted_sum / weight_total;
}

double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, int k, time_t start, time_t stop)
{

	vector<Measurement *> measures = GetMeasures(start, stop);
	return EstimationQualiteAirPos(lat, lon, k, start, stop, &measures);
}

double AirQualityProcessor::EstimationQualiteAirZone(double lat, double lon, double radius, int k, time_t start, time_t stop)
{

	double step = 1; // Pas de discrétisation de la zone

	vector<Measurement *> measures = GetMeasures(start, stop);
	vector<Measurement *> valid_measures;

	for (const Measurement *m : measures)
	{
		if (GetDistance(m, lat, lon) <= radius)
		{
			valid_measures.push_back(const_cast<Measurement *>(m));
		}
	}

	vector<double> estimations;
	for (double dlat = -radius; dlat <= radius; dlat += step)
	{
		for (double dlon = -radius; dlon <= radius; dlon += step)
		{
			if (dlat * dlat + dlon * dlon <= radius * radius)
			{
				double est = EstimationQualiteAirPos(lat + dlat, lon + dlon, k, start, stop, &valid_measures);
				if (!isnan(est))
				{
					estimations.push_back(est);
				}
			}
		}
	}

	if (estimations.empty())
	{
		// Radius trop petit, faire une estimation à la position centrale
		double est = EstimationQualiteAirPos(lat, lon, k, start, stop, &valid_measures);
		if (!isnan(est))
		{
			estimations.push_back(est);
		}
		else
		{
			return numeric_limits<double>::quiet_NaN();
		}
	}

	double sum = 0.0;
	for (double v : estimations)
		sum += v;
	return sum / estimations.size();
}

vector<const Sensor *> AirQualityProcessor::TrouverCapteursDetournes(double radius, double seuil_limite, int k, time_t start, time_t stop)
{

	vector<Measurement *> measures = GetMeasures(start, stop);
	unordered_map<unsigned int, double> estimation_cache;
	unordered_map<unsigned int, double> mesure_cache;
	unordered_map<unsigned int, int> mesure_count;

	for (const Measurement *mesure : measures)
	{
		const Sensor *capteur = mesure->GetSensor();

		if (mesure_cache.find(capteur->GetSensorID()) == mesure_cache.end())
		{
			mesure_cache[capteur->GetSensorID()] = mesure->GetValue();
			mesure_count[capteur->GetSensorID()] = 1;
		}
		else
		{
			mesure_cache[capteur->GetSensorID()] += mesure->GetValue();
			mesure_count[capteur->GetSensorID()]++;
		}

		if (estimation_cache.find(capteur->GetSensorID()) == estimation_cache.end())
		{
			double estimation = EstimationQualiteAirZone(capteur->GetLatitude(), capteur->GetLongitude(), radius, k, start, stop);
			estimation_cache[capteur->GetSensorID()] = estimation;
		}
	}

	vector<const Sensor *> capteurs_detournes;
	for (const auto &pair : mesure_cache)
	{
		unsigned int sensor_id = pair.first;
		double mesure_value = pair.second / mesure_count[sensor_id];
		double estimation_value = estimation_cache[sensor_id];

		// cout << "Capteur ID: " << sensor_id << ", Estimation: " << estimation_value
		// 	 << ", Mesure: " << mesure_value << ", Différence: " << fabs(estimation_value - mesure_value) << endl;
		if (fabs(estimation_value - mesure_value) > seuil_limite)
		{
			try
			{
				const Sensor *capteur = CSVHandler::getSensor(sensor_id);
				// cout << "Capteur détourné trouvé: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude()
				// 	 << ", Longitude: " << capteur->GetLongitude() << endl;
				capteurs_detournes.push_back(capteur);
			}
			catch (const std::runtime_error &e)
			{
				continue;
			}
		}
	}

	return capteurs_detournes;
}

vector<const Sensor *> AirQualityProcessor::ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop)
{

	vector<Measurement *> measures = GetMeasures(start, stop);

	vector<const Sensor *> capteurs_similaires;
	if (measures.empty())
	{
		return capteurs_similaires; // Retourne une liste vide si aucune mesure n'est trouvée
	}
	unordered_map<unsigned int, double> mesure_cache;
	unordered_map<unsigned int, int> mesure_count;

	for (Measurement *mesure : measures)
	{
		Sensor *capteur = mesure->GetSensor();
		if (mesure_cache.find(capteur->GetSensorID()) == mesure_cache.end()) // Si le capteur n'est pas encore dans le cache
		{
			mesure_cache[capteur->GetSensorID()] = mesure->GetValue();
			mesure_count[capteur->GetSensorID()] = 1;
		}
		else // Si le capteur est déjà dans le cache
		{
			mesure_cache[capteur->GetSensorID()] += mesure->GetValue();
			mesure_count[capteur->GetSensorID()]++;
		}
	}

	// cout << "Nombre de capteurs trouvés : " << mesure_cache.size() << endl;
	// cout << "Capteurs trouvés :" << endl;
	// for (const auto &pair : mesure_cache)
	// {
	// 	cout << "Capteur ID: " << pair.first << ", Valeur moyenne: " << pair.second / mesure_count[pair.first] << endl;
	// }

	// if (mesure_cache.find(id_ref) == mesure_cache.end())
	// {
	// 	cerr << "Capteur de référence non trouvé dans les mesures." << endl;
	// 	return capteurs_similaires; // Retourne une liste vide si le capteur de référence n'est pas trouvé
	// }

	double ref_value = mesure_cache[id_ref] / mesure_count[id_ref];

	for (const auto &pair : mesure_cache)
	{
		unsigned int sensor_id = pair.first;
		double mesure_value = pair.second / mesure_count[sensor_id];

		if (sensor_id == id_ref)
			continue; // Ignore le capteur de référence

		if (fabs(mesure_value - ref_value) < 0.1 * ref_value) // Seuil de similarité de 10%
		{
			const Sensor *capteur = CSVHandler::getSensor(sensor_id);
			capteurs_similaires.push_back(capteur);
		}
	}

	// Trie les capteurs similaires par ID
	sort(capteurs_similaires.begin(), capteurs_similaires.end(),
		 [](const Sensor *a, const Sensor *b)
		 { return a->GetSensorID() < b->GetSensorID(); });

	return capteurs_similaires;
}

vector<Measurement *> AirQualityProcessor::GetMeasures(time_t start, time_t stop)
{
	vector<Measurement *> measures = CSVHandler::getMeasurement(start, stop);
	return measures;
}

double AirQualityProcessor::GetDistance(double lat1, double lon1, double lat2, double lon2)
{
	double dlat = lat2 - lat1;
	double dlon = lon2 - lon1;
	return sqrt(dlat * dlat + dlon * dlon);
}

double AirQualityProcessor::GetDistance(const Sensor &sensor1, const Sensor &sensor2)
{
	return GetDistance(sensor1.GetLatitude(), sensor1.GetLongitude(), sensor2.GetLatitude(), sensor2.GetLongitude());
}

double AirQualityProcessor::GetDistance(const Measurement &measurement1, const Measurement &measurement2)
{
	return GetDistance(measurement1.GetSensor()->GetLatitude(), measurement1.GetSensor()->GetLongitude(),
					   measurement2.GetSensor()->GetLatitude(), measurement2.GetSensor()->GetLongitude());
}

double AirQualityProcessor::GetDistance(const Measurement *measurement, double lat, double lon)
{
	return GetDistance(measurement->GetSensor()->GetLatitude(), measurement->GetSensor()->GetLongitude(), lat, lon);
}