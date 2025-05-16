#include "processing.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, int k)
{

	std::vector<Measure> measures = GetAllMeasures();

	if (measures.empty())
		return std::numeric_limits<double>::quiet_NaN();

	std::vector<std::pair<double, const Measure *>> distances;
	for (const auto &m : measures)
	{
		double dist = std::sqrt((lat - m.latitude) * (lat - m.latitude) +
								(lon - m.longitude) * (lon - m.longitude));
		distances.push_back({dist, &m});
	}

	std::sort(distances.begin(), distances.end(),
			  [](const std::pair<double, const Measure *> &a, const std::pair<double, const Measure *> &b)
			  { return a.first < b.first; });

	int count = std::min(k, static_cast<int>(distances.size()));
	double weighted_sum = 0.0;
	double weight_total = 0.0;

	for (int i = 0; i < count; ++i)
	{
		double dist = distances[i].first;
		double value = distances[i].second->value;
		double weight = (dist == 0.0) ? 1e9 : 1.0 / dist;
		weighted_sum += value * weight;
		weight_total += weight;
	}

	return (weight_total > 0.0) ? (weighted_sum / weight_total) : std::numeric_limits<double>::quiet_NaN();
}

double AirQualityProcessor::EstimationQualiteAirZone(double lat, double lon, double radius, int k, double step)
{

	std::vector<Measure> measures = GetAllMeasures();

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

std::vector<const Measure *> AirQualityProcessor::TrouverCapteursDetournes(double radius, double seuil_limite, int k, double step)
{

	std::vector<Measure> measures = GetAllMeasures();

	std::vector<const Measure *> capteurs_detournes;
	for (const auto &capteur : measures)
	{
		double estimation = EstimationQualiteAirZone(capteur.latitude, capteur.longitude, radius, k, step);
		if (!std::isnan(estimation) && std::abs(estimation - capteur.value) > seuil_limite)
		{
			capteurs_detournes.push_back(&capteur);
		}
	}
	return capteurs_detournes;
}

std::vector<const Measure *> AirQualityProcessor::TrouverCapteursSimilaires(int id_ref)
{

	std::vector<Measure> measures = GetAllMeasures();

	std::vector<const Measure *> capteurs_similaires;
	for (const auto &capteur : measures)
	{
		if (capteur.id == id_ref)
			continue; // Ignore le capteur de référence
		double dist = std::sqrt((capteur.latitude - measures[id_ref].latitude) * (capteur.latitude - measures[id_ref].latitude) +
								(capteur.longitude - measures[id_ref].longitude) * (capteur.longitude - measures[id_ref].longitude));
		if (dist < 0.01) // Seuil de proximité
		{
			capteurs_similaires.push_back(&capteur);
		}
	}
	return capteurs_similaires;
}

std::vector<Measure> AirQualityProcessor::GetAllMeasures()
{
	// Cette fonction devrait récupérer toutes les mesures disponibles
	// Pour l'instant, on retourne une liste vide
	return std::vector<Measure>();
}