#include "processing.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "../couche_acces_aux_donnees/CSVHandler.h"

using namespace std;

double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, int k, time_t start, time_t stop)
{

	vector<Measurement *> measures = GetMeasures(start, stop);

	if (measures.empty())
		return numeric_limits<double>::quiet_NaN();

	vector<pair<double, const Measurement *>> distances;

	for (const Measurement *m : measures)
	{
		double dist = sqrt((lat - m->GetSensor().GetLatitude()) * (lat - m->GetSensor().GetLatitude()) +
						   (lon - m->GetSensor().GetLongitude()) * (lon - m->GetSensor().GetLongitude()));
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

	return (weight_total > 0.0) ? (weighted_sum / weight_total) : numeric_limits<double>::quiet_NaN();
}

double AirQualityProcessor::EstimationQualiteAirZone(double lat, double lon, double radius, int k, time_t start, time_t stop)
{

	double step = 1; // Pas de discrétisation de la zone

	vector<Measurement *> measures = GetMeasures(start, stop);

	vector<double> estimations;
	for (double dlat = -radius; dlat <= radius; dlat += step)
	{
		for (double dlon = -radius; dlon <= radius; dlon += step)
		{
			if (dlat * dlat + dlon * dlon <= radius * radius)
			{
				double est = EstimationQualiteAirPos(lat + dlat, lon + dlon, k, start, stop);
				if (!isnan(est))
				{
					estimations.push_back(est);
				}
			}
		}
	}
	if (estimations.empty())
		return numeric_limits<double>::quiet_NaN();
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

	vector<const Sensor *> capteurs_detournes;
	for (const Measurement *mesure : measures)
	{
		const Sensor &capteur = mesure->GetSensor();

		if (mesure_cache.find(capteur.GetSensorID()) == mesure_cache.end())
		{
			mesure_cache[capteur.GetSensorID()] = mesure->GetValue();
			mesure_count[capteur.GetSensorID()] = 1;
		}
		else
		{
			mesure_cache[capteur.GetSensorID()] += mesure->GetValue();
			mesure_count[capteur.GetSensorID()]++;
		}

		if (estimation_cache.find(capteur.GetSensorID()) == estimation_cache.end())
		{
			double estimation = EstimationQualiteAirZone(capteur.GetLatitude(), capteur.GetLongitude(), radius, k, start, stop);
			estimation_cache[capteur.GetSensorID()] = estimation;
		}
	}

	for (const auto &pair : mesure_cache)
	{
		unsigned int sensor_id = pair.first;
		double mesure_value = pair.second / mesure_count[sensor_id];
		double estimation_value = estimation_cache[sensor_id];

		if (fabs(estimation_value - mesure_value) > seuil_limite)
		{
			const Sensor &capteur = CSVHandler::getSensor(sensor_id);
			capteurs_detournes.push_back(&capteur);
		}
	}

	return capteurs_detournes;
}

vector<const Sensor *> AirQualityProcessor::ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop)
{

	vector<Measurement *> measures = GetMeasures(start, stop);

	vector<const Sensor *> capteurs_similaires;
	if (id_ref >= measures.size())
		return capteurs_similaires;

	unordered_map<unsigned int, double> mesure_cache;
	unordered_map<unsigned int, int> mesure_count;

	for (Measurement *mesure : measures)
	{
		Sensor capteur = mesure->GetSensor();
		if (mesure_cache.find(capteur.GetSensorID()) == mesure_cache.end())
		{
			mesure_cache[capteur.GetSensorID()] = mesure->GetValue();
			mesure_count[capteur.GetSensorID()] = 1;
		}
		else
		{
			mesure_cache[capteur.GetSensorID()] += mesure->GetValue();
			mesure_count[capteur.GetSensorID()]++;
		}
	}

	for (const auto &pair : mesure_cache)
	{
		unsigned int sensor_id = pair.first;
		double mesure_value = pair.second / mesure_count[sensor_id];

	}
	return capteurs_similaires;
}

vector<Measurement *> AirQualityProcessor::GetMeasures(time_t start, time_t stop)
{
	vector<Measurement *> measures = CSVHandler::getMeasurement(start, stop);
	return measures;
}
