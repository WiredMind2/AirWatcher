/*************************************************************************
processing.cpp  -  Implémente les fonctions de traitement des données de qualité de l'air.
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

// Estime la qualité de l'air à une position (lat, lon) en utilisant les k mesures les plus proches dans l'intervalle [start, stop].
// Si un pointeur vers un vecteur de mesures est fourni, il est utilisé, sinon on récupère les mesures depuis les CSV.
double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop, const vector<Measurement *> *measures)
{
    int k = 3; // Nombre de voisins à utiliser pour l'estimation locale.
    // Calcule la distance de chaque mesure à la position cible et ne garde que celles dans un rayon de 10 unités.
    vector<pair<double, const Measurement *>> distances;
    double max_dist = 10.0;
    for (const Measurement *m : *measures)
    {
        double dist = GetDistance(m, lat, lon);
        if (dist > max_dist)
            continue;
        distances.push_back({dist, m});
    }
    // Trie les mesures par distance croissante.
    sort(distances.begin(), distances.end(),
         [](const pair<double, const Measurement *> &a, const pair<double, const Measurement *> &b)
         { return a.first < b.first; });
    // Prend les k plus proches et fait une moyenne pondérée par l'inverse de la distance.
    int count = min(k, static_cast<int>(distances.size()));
    double weighted_sum = 0.0;
    double weight_total = 0.0;
    const double epsilon = 1e-8;
    for (int i = 0; i < count; ++i)
    {
        double dist = distances[i].first;
        double value = distances[i].second->GetValue();
        if (dist == 0.0)
        {
            // Exact match found, return its value directly
            return value;
        }
        double weight = 1.0 / (dist + epsilon);
        weighted_sum += value * weight;
        weight_total += weight;
    }
    // Si aucune mesure n'est disponible, retourne NaN.
    if (weight_total == 0.0)
    {
        return numeric_limits<double>::quiet_NaN();
    }
    return weighted_sum / weight_total;
}

// Surcharge : estime la qualité de l'air à une position (lat, lon) en récupérant les mesures depuis les CSV.
double AirQualityProcessor::EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop)
{
    vector<Measurement *> measures = GetMeasures(start, stop);
    return EstimationQualiteAirPos(lat, lon, start, stop, &measures);
}

// Estime la qualité de l'air sur une zone circulaire centrée en (lat, lon) de rayon 'radius',
// en discrétisant la zone et en moyennant les estimations locales.
double AirQualityProcessor::EstimationQualiteAirZone(double lat, double lon, double radius, time_t start, time_t stop)
{
    if (radius <= 0.0)
    {
        // Si le rayon est négatif ou nul, retourne NaN.
        return numeric_limits<double>::quiet_NaN();
    }
    // Adapt the discretization step to the radius: e.g., 1/10th of the radius, with a minimum of 0.05 and a maximum of 1.0
    double step = std::max(0.05, std::min(radius / 10.0, 1.0));
    vector<Measurement *> measures = GetMeasures(start, stop);
    vector<Measurement *> valid_measures;
    // Filtre les mesures dans le rayon spécifié.
    for (const Measurement *m : measures)
    {
        if (GetDistance(m, lat, lon) <= radius)
        {
            valid_measures.push_back(const_cast<Measurement *>(m));
        }
    }
    // Pour chaque point de la grille dans le cercle, effectue une estimation locale.
    vector<double> estimations;
    for (double dlat = -radius; dlat <= radius; dlat += step)
    {
        for (double dlon = -radius; dlon <= radius; dlon += step)
        {
            if (dlat * dlat + dlon * dlon <= radius * radius)
            {
                double est = EstimationQualiteAirPos(lat + dlat, lon + dlon, start, stop, &valid_measures);
                if (!isnan(est))
                {
                    estimations.push_back(est);
                }
            }
        }
    }
    // Si aucune estimation n'est possible, tente une estimation centrale.
    if (estimations.empty())
    {
        double est = EstimationQualiteAirPos(lat, lon, start, stop, &valid_measures);
        if (!isnan(est))
        {
            estimations.push_back(est);
        }
        else
        {
            return numeric_limits<double>::quiet_NaN();
        }
    }
    // Retourne la moyenne des estimations locales.
    double sum = 0.0;
    for (double v : estimations)
        sum += v;
    return sum / estimations.size();
}

// Détecte les capteurs potentiellement détournés :
// Pour chaque capteur, compare la valeur mesurée à une estimation locale sur la même période.
// Si l'écart dépasse le seuil, le capteur est considéré comme détourné.
vector<const Sensor *> AirQualityProcessor::TrouverCapteursDetournes(double radius, double seuil_limite, time_t start, time_t stop)
{
    vector<Measurement *> measures = GetMeasures(start, stop);
    unordered_map<unsigned int, double> estimation_cache;
    unordered_map<unsigned int, double> mesure_cache;
    unordered_map<unsigned int, int> mesure_count;
    // Agrège les mesures et calcule les estimations pour chaque capteur.
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
            double estimation = EstimationQualiteAirZone(capteur->GetLatitude(), capteur->GetLongitude(), radius, start, stop);
            estimation_cache[capteur->GetSensorID()] = estimation;
        }
    }
    vector<const Sensor *> capteurs_detournes;
    // Compare la valeur mesurée et l'estimation pour chaque capteur.
    for (const auto &pair : mesure_cache)
    {
        unsigned int sensor_id = pair.first;
        double mesure_value = pair.second / mesure_count[sensor_id];
        double estimation_value = estimation_cache[sensor_id];
        if (fabs(estimation_value - mesure_value) > seuil_limite)
        {
            try
            {
                const Sensor *capteur = CSVHandler::getSensor(sensor_id);
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

// Liste les capteurs dont la valeur moyenne sur la période [start, stop] est similaire à celle d'un capteur de référence (id_ref).
// Deux capteurs sont considérés similaires si leur valeur moyenne diffère de moins de 10%.
vector<const Sensor *> AirQualityProcessor::ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop)
{
    vector<Measurement *> measures = GetMeasures(start, stop);
    vector<const Sensor *> capteurs_similaires;
    if (measures.empty())
    {
        return capteurs_similaires;
    }
    unordered_map<unsigned int, double> mesure_cache;
    unordered_map<unsigned int, int> mesure_count;
    // Agrège les mesures par capteur.
    for (Measurement *mesure : measures)
    {
        Sensor *capteur = mesure->GetSensor();
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
    }
    // Vérifie que le capteur de référence existe dans le cache et a au moins une mesure.
    if (mesure_cache.find(id_ref) == mesure_cache.end() || mesure_count.find(id_ref) == mesure_count.end() || mesure_count[id_ref] == 0)
    {
        // Capteur de référence absent ou aucune mesure, retourne la liste vide.
        return capteurs_similaires;
    }
    // Calcule la valeur moyenne du capteur de référence.
    double ref_value = mesure_cache[id_ref] / mesure_count[id_ref];
    // Cherche les capteurs dont la valeur moyenne est proche de celle du capteur de référence.
    for (const auto &pair : mesure_cache)
    {
        unsigned int sensor_id = pair.first;
        double mesure_value = pair.second / mesure_count[sensor_id];
        if (sensor_id == id_ref)
            continue;
        if (fabs(mesure_value - ref_value) < 0.1 * ref_value)
        {
            const Sensor *capteur = CSVHandler::getSensor(sensor_id);
            capteurs_similaires.push_back(capteur);
        }
    }
    // Trie les capteurs similaires par ID croissant.
    sort(capteurs_similaires.begin(), capteurs_similaires.end(),
         [](const Sensor *a, const Sensor *b)
         { return a->GetSensorID() < b->GetSensorID(); });
    return capteurs_similaires;
}

// Récupère toutes les mesures comprises entre deux timestamps.
vector<Measurement *> AirQualityProcessor::GetMeasures(time_t start, time_t stop)
{
    return CSVHandler::getMeasurement(start, stop);
}

// Calcule la distance euclidienne entre deux points géographiques (lat1, lon1) et (lat2, lon2).
double AirQualityProcessor::GetDistance(double lat1, double lon1, double lat2, double lon2)
{
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    return sqrt(dlat * dlat + dlon * dlon);
}

// Calcule la distance entre deux capteurs.
double AirQualityProcessor::GetDistance(const Sensor &sensor1, const Sensor &sensor2)
{
    return GetDistance(sensor1.GetLatitude(), sensor1.GetLongitude(), sensor2.GetLatitude(), sensor2.GetLongitude());
}

// Calcule la distance entre deux mesures (via leurs capteurs).
double AirQualityProcessor::GetDistance(const Measurement &measurement1, const Measurement &measurement2)
{
    return GetDistance(measurement1.GetSensor()->GetLatitude(), measurement1.GetSensor()->GetLongitude(),
                       measurement2.GetSensor()->GetLatitude(), measurement2.GetSensor()->GetLongitude());
}

// Calcule la distance entre une mesure et une position géographique.
double AirQualityProcessor::GetDistance(const Measurement *measurement, double lat, double lon)
{
    return GetDistance(measurement->GetSensor()->GetLatitude(), measurement->GetSensor()->GetLongitude(), lat, lon);
}