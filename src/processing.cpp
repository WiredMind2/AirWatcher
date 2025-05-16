#include "processing.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "CSVHandler.h"

using namespace std;

double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, int k, time_t start, time_t stop)
{

	std::vector<Measurement> measures = GetMeasures(start, stop);

	if (measures.empty())
		return std::numeric_limits<double>::quiet_NaN();

	std::vector<std::pair<double, const Measurement *>> distances;
	for (const auto &m : measures)
	{
		double dist = std::sqrt((lat - m.GetSensor()->GetLatitude()) * (lat - m.GetSensor()->GetLatitude()) +
								(lon - m.GetSensor()->GetLongitude()) * (lon - m.GetSensor()->GetLongitude()));
		distances.push_back({dist, &m});
	}

	std::sort(distances.begin(), distances.end(),
			  [](const std::pair<double, const Measurement *> &a, const std::pair<double, const Measurement *> &b)
			  { return a.first < b.first; });

	int count = std::min(k, static_cast<int>(distances.size()));
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

	return (weight_total > 0.0) ? (weighted_sum / weight_total) : std::numeric_limits<double>::quiet_NaN();
}

double AirQualityProcessor::EstimationQualiteAirZone(double lat, double lon, double radius, int k, double step, time_t start, time_t stop)
{

	std::vector<Measurement> measures = GetMeasures(start, stop);

	std::vector<double> estimations;
	for (double dlat = -radius; dlat <= radius; dlat += step)
	{
		for (double dlon = -radius; dlon <= radius; dlon += step)
		{
			if (dlat * dlat + dlon * dlon <= radius * radius)
			{
				double est = EstimationQualiteAirPos(lat + dlat, lon + dlon, k);
				if (!std::isnan(est))
				{
					estimations.push_back(est);
				}
			}
		}
	}
	if (estimations.empty())
		return std::numeric_limits<double>::quiet_NaN();
	double sum = 0.0;
	for (double v : estimations)
		sum += v;
	return sum / estimations.size();
}

std::vector<const Sensor *> AirQualityProcessor::TrouverCapteursDetournes(double radius, double seuil_limite, int k, double step, time_t start, time_t stop)
{

	std::vector<Measurement> measures = GetMeasures(start, stop);

	std::vector<const Sensor *> capteurs_detournes;
	for (const auto &mesure : measures)
	{
		const Sensor &capteur = *mesure.GetSensor();
		double estimation = EstimationQualiteAirZone(capteur.GetLatitude(), capteur.GetLongitude(), radius, k, step);
		if (!std::isnan(estimation) && std::abs(estimation - mesure.GetValue()) > seuil_limite)
		{
			capteurs_detournes.push_back(&capteur);
		}
	}
	return capteurs_detournes;
}

std::vector<const Measurement *> AirQualityProcessor::ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop)
{

	std::vector<Measurement> measures = GetMeasures(start, stop);

	std::vector<const Measurement *> capteurs_similaires;
	for (const auto &capteur : measures)
	{
		if (capteur.GetSensor()->GetSensorID() == id_ref)
			continue; // Ignore le capteur de référence
		double dist = std::sqrt(
			(capteur.GetSensor()->GetLatitude() - measures[id_ref].GetSensor()->GetLatitude()) *
			(capteur.GetSensor()->GetLatitude() - measures[id_ref].GetSensor()->GetLatitude()) +
			(capteur.GetSensor()->GetLongitude() - measures[id_ref].GetSensor()->GetLongitude()) *
			(capteur.GetSensor()->GetLongitude() - measures[id_ref].GetSensor()->GetLongitude()));
		if (dist < 0.01) // Seuil de proximité
		{
			capteurs_similaires.push_back(&capteur);
		}
	}
	return capteurs_similaires;
}

std::vector<Measurement> AirQualityProcessor::GetMeasures(time_t start, time_t stop)
{
	// vector<Measurement> measures = CSVHandler::getMeasurement(start, stop);
	return vector<Measurement>(); // Placeholder
}
