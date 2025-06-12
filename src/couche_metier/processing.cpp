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
unordered_map<unsigned int, double> Processing::EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop, const unordered_map<unsigned int, vector<Measurement *>> *measures)
{
    int k = 3; // Nombre de voisins à utiliser pour l'estimation locale.
    double max_dist = 10.0;
    // Calcule la distance de chaque mesure à la position cible et ne garde que celles dans un rayon de 10 unités.

    unordered_map<unsigned int, double> estimations;

    for (const auto &mpair : *measures)
    {
        vector<pair<double, const Measurement *>> distances;
        for (const Measurement *m : mpair.second)
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
                estimations[mpair.first] = value;
            }
            double weight = 1.0 / (dist + epsilon);
            weighted_sum += value * weight;
            weight_total += weight;
        }
        // Si aucune mesure n'est disponible, retourne NaN.
        if (weight_total == 0.0)
        {
            estimations[mpair.first] = numeric_limits<double>::quiet_NaN();
        }
        else
        {
            estimations[mpair.first] = weighted_sum / weight_total;
        }
    }
    return estimations;
}

// Surcharge : estime la qualité de l'air à une position (lat, lon) en récupérant les mesures depuis les CSV.
unordered_map<unsigned int, double> Processing::EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop)
{
    auto measures = GetMeasures(start, stop);
    return EstimationQualiteAirPos(lat, lon, start, stop, &measures);
}

unordered_map<unsigned int, double> Processing::EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop, const vector<Measurement *> *measures)
{
    unordered_map<unsigned int, vector<Measurement *>> measures_map;
    // Regroupe les mesures par attributeId.
    for (const Measurement *m : *measures)
    {
        measures_map[m->GetAttributeID()].push_back(const_cast<Measurement *>(m));
    }
    return EstimationQualiteAirPos(lat, lon, start, stop, &measures_map);
}

// Estime la qualité de l'air sur une zone circulaire centrée en (lat, lon) de rayon 'radius',
// en discrétisant la zone et en moyennant les estimations locales.
unordered_map<unsigned int, double> Processing::EstimationQualiteAirZone(double lat, double lon, double radius, time_t start, time_t stop, bool log)
{

    if (radius <= 0.0)
    {
        // Si le rayon est négatif ou nul, retourne NaN.
        return unordered_map<unsigned int, double>{};
    }

    // Définit le pas de discrétisation en fonction du rayon, avec une valeur minimale de 0.5 et maximale de 10.0.
    double step = std::max(0.5, std::min(radius / 10.0, 10.0));

    if (log)
    {
        cout << "Estimation de la qualité de l'air sur la zone centrée à (" << lat << ", " << lon << ") avec un rayon de " << radius << "\n";
        cout << "Pas de discrétisation : " << step << "\n";
    }

    // Récupère les mesures dans l'intervalle [start, stop].
    auto measures = GetMeasures(start, stop);
    unordered_map<unsigned int, vector<Measurement *>> measures_map;

    // Filtre les mesures dans le rayon spécifié.
    for (const auto &pair : measures)
    {
        for (const Measurement *m : pair.second)
        {
            if (GetDistance(m, lat, lon) <= radius)
            {
                measures_map[m->GetAttributeID()].push_back(const_cast<Measurement *>(m));
            }
        }
    }

    // Si aucune mesure n'est disponible, retourne un map vide.
    if (measures_map.empty())
    {
        return unordered_map<unsigned int, double>{};
    }

    // Pour chaque point de la grille dans le cercle, effectue une estimation locale.
    unordered_map<unsigned int, vector<double>> estimations_map;
    for (double dlat = -radius; dlat <= radius; dlat += step)
    {
        for (double dlon = -radius; dlon <= radius; dlon += step)
        {
            if (dlat * dlat + dlon * dlon <= radius * radius)
            {
                if (log)
                    cout << "\rEstimation à la position (" << lat + dlat << ", " << lon + dlon << ")   " << flush;

                auto est = EstimationQualiteAirPos(lat + dlat, lon + dlon, start, stop, &measures_map);
                for (const auto &pair : est)
                {
                    unsigned int attr_id = pair.first;
                    double value = pair.second;
                    if (estimations_map.find(attr_id) == estimations_map.end())
                    {
                        estimations_map[attr_id] = vector<double>{value};
                    }
                    else
                    {
                        estimations_map[attr_id].push_back(value);
                    }
                }
            }
        }
    }

    if (log)
        cout << "\n";

    // Calcule la moyenne des estimations locales pour chaque attribut.
    unordered_map<unsigned int, double> estimations;
    for (const auto &pair : estimations_map)
    {
        const vector<double> &values = pair.second;
        if (!values.empty())
        {
            double sum = 0.0;
            for (double v : values)
                sum += v;
            estimations[pair.first] = sum / values.size();
        }
    }

    // Si aucune estimation n'est possible, retourne un map vide.
    if (estimations.empty())
    {
        return unordered_map<unsigned int, double>{};
    }

    return estimations;
}

// Détecte les capteurs potentiellement détournés :
// Pour chaque capteur, compare la valeur mesurée à une estimation locale sur la même période.
// Si l'écart dépasse le seuil, le capteur est considéré comme détourné.
vector<const Sensor *> Processing::TrouverCapteursDetournes(double radius, unordered_map<unsigned int, double> seuils_limite, time_t start, time_t stop)
{
    auto measures = GetMeasures(start, stop);
    vector<const Sensor *> capteurs_detournes;
    if (measures.empty())
    {
        // Si aucune mesure n'est disponible, retourne une liste vide.
        return capteurs_detournes;
    }
    unordered_map<unsigned int, unordered_map<unsigned int, double>> estimation_cache;
    // Agrège les mesures et calcule les estimations pour chaque capteur.
    for (const auto &pair : measures)
    {
        unsigned int attribute_id = pair.first;

        if (seuils_limite.find(attribute_id) == seuils_limite.end())
        {
            // Si l'attribut n'a pas de seuil défini, on le saute.
            continue;
        }

        unordered_map<unsigned int, double> mesure_cache;
        unordered_map<unsigned int, int> mesure_count;

        for (const Measurement *mesure : pair.second)
        {
            const Sensor *capteur = mesure->GetSensor();
            if (mesure_cache.find(capteur->GetSensorID()) == mesure_cache.end())
            {
                mesure_cache[capteur->GetSensorID()] = 0.0;
                mesure_count[capteur->GetSensorID()] = 0;
            }
            mesure_cache[capteur->GetSensorID()] += mesure->GetValue();
            mesure_count[capteur->GetSensorID()] += 1;

            if (estimation_cache.find(capteur->GetSensorID()) == estimation_cache.end())
            {
                auto estimation = EstimationQualiteAirZone(capteur->GetLatitude(), capteur->GetLongitude(), radius, start, stop);
                estimation_cache[capteur->GetSensorID()] = estimation;
            }
        }

        // Compare la valeur mesurée et l'estimation pour chaque capteur.
        for (const auto &mpair : mesure_cache)
        {
            unsigned int sensor_id = mpair.first;
            double mesure_value = mpair.second / mesure_count[sensor_id];
            double estimation_value = estimation_cache[sensor_id][attribute_id];
            if (fabs(estimation_value - mesure_value) > seuils_limite[attribute_id])
            {
                // cout << "Capteur détourné détecté : ID " << sensor_id
                //         << ", Attribut ID: " << attribute_id
                //      << ", Mesure: " << mesure_value
                //      << ", Estimation: " << estimation_value
                //      << ", Écart: " << fabs(estimation_value - mesure_value) << "\n";
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
    }

    return capteurs_detournes;
}

// Liste les capteurs dont la valeur moyenne sur la période [start, stop] est similaire à celle d'un capteur de référence (id_ref).
// Deux capteurs sont considérés similaires si leur valeur moyenne diffère de moins de 10%.
vector<const Sensor *> Processing::ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop)
{

    double precision = 0.1; // 10% de tolérance pour la similarité des valeurs.

    auto measures = GetMeasures(start, stop);
    vector<const Sensor *> capteurs_similaires;
    if (measures.empty())
        return capteurs_similaires;

    // Agrège les mesures par capteur.
    for (const auto &pair : measures)
    {
        unordered_map<unsigned int, double> mesure_cache;
        unordered_map<unsigned int, int> mesure_count;

        for (Measurement *mesure : pair.second)
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
            continue;

        // Calcule la valeur moyenne du capteur de référence.
        double ref_value = mesure_cache[id_ref] / mesure_count[id_ref];

        // Cherche les capteurs dont la valeur moyenne est proche de celle du capteur de référence.
        for (const auto &pair : mesure_cache)
        {
            unsigned int sensor_id = pair.first;
            if (sensor_id == id_ref)
                continue;

            // Calcule la valeur moyenne pour le capteur actuel.
            double mesure_value = pair.second / mesure_count[sensor_id];

            if (fabs(mesure_value - ref_value) < precision)
            {
                const Sensor *capteur = CSVHandler::getSensor(sensor_id);
                capteurs_similaires.push_back(capteur);
            }
        }
    }

    // Trie les capteurs similaires par ID croissant.
    sort(capteurs_similaires.begin(), capteurs_similaires.end(),
         [](const Sensor *a, const Sensor *b)
         { return a->GetSensorID() < b->GetSensorID(); });

    // Supprime les doublons en utilisant un set.
    auto last = unique(capteurs_similaires.begin(), capteurs_similaires.end(),
                       [](const Sensor *a, const Sensor *b)
                       { return a->GetSensorID() == b->GetSensorID(); });
    capteurs_similaires.erase(last, capteurs_similaires.end());

    // Renvoie seulement les premiers 10 capteurs similaires.
    if (capteurs_similaires.size() > 10)
    {
        capteurs_similaires.resize(10);
    }

    return capteurs_similaires;
}

// Récupère toutes les mesures comprises entre deux timestamps, groupées par attributeId.
unordered_map<unsigned int, vector<Measurement *>> Processing::GetMeasures(time_t start, time_t stop)
{
    vector<Measurement *> allMeasures = CSVHandler::getMeasurement(start, stop);
    unordered_map<unsigned int, vector<Measurement *>> groupedMeasures;
    for (Measurement *m : allMeasures)
    {
        unsigned int attrId = m->GetAttributeID();
        groupedMeasures[attrId].push_back(m);
    }
    return groupedMeasures;
}

// Calcule la distance euclidienne entre deux points géographiques (lat1, lon1) et (lat2, lon2).
double Processing::GetDistance(double lat1, double lon1, double lat2, double lon2)
{
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    return sqrt(dlat * dlat + dlon * dlon);
}

// Calcule la distance entre deux capteurs.
double Processing::GetDistance(const Sensor &sensor1, const Sensor &sensor2)
{
    return GetDistance(sensor1.GetLatitude(), sensor1.GetLongitude(), sensor2.GetLatitude(), sensor2.GetLongitude());
}

// Calcule la distance entre deux mesures (via leurs capteurs).
double Processing::GetDistance(const Measurement &measurement1, const Measurement &measurement2)
{
    return GetDistance(measurement1.GetSensor()->GetLatitude(), measurement1.GetSensor()->GetLongitude(),
                       measurement2.GetSensor()->GetLatitude(), measurement2.GetSensor()->GetLongitude());
}

// Calcule la distance entre une mesure et une position géographique.
double Processing::GetDistance(const Measurement *measurement, double lat, double lon)
{
    return GetDistance(measurement->GetSensor()->GetLatitude(), measurement->GetSensor()->GetLongitude(), lat, lon);
}