/*************************************************************************
 processing.h  -  Déclaration des fonctions de traitement des données de qualité de l'air.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>
#include "Measurement.h"

using namespace std;

class Processing
{
public:
	// Estime la qualité de l'air à une position géographique donnée (lat, lon)
	// lat, lon : coordonnées de la position
	// measures : liste de toutes les mesures disponibles
	// k : nombre de voisins à utiliser (par défaut 4)
	// Retourne la valeur estimée de la qualité de l'air ou NaN si aucune mesure n'est disponible
	static unordered_map<unsigned int, double> EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop, const unordered_map<unsigned int, vector<Measurement *>> *measures);
	static unordered_map<unsigned int, double> EstimationQualiteAirPos(double lat, double lon, time_t start, time_t stop, const vector<Measurement *> *measures);
	static unordered_map<unsigned int, double> EstimationQualiteAirPos(double lat, double lon, time_t start=0, time_t stop=-1);

	// Estime la qualité de l'air sur une zone circulaire (centre lat, lon, rayon en degrés)
	// lat, lon : coordonnées du centre de la zone
	// radius : rayon de la zone en degrés
	// measures : liste de toutes les mesures disponibles
	// k : nombre de voisins à utiliser (par défaut 4)
	// step : pas de discrétisation de la zone (par défaut 1)
	// Retourne la moyenne des estimations dans la zone
	static unordered_map<unsigned int, double> EstimationQualiteAirZone(double lat, double lon, double radius, time_t start=0, time_t stop=-1, bool log=false);

	// Trouve les capteurs détournés (valeur estimée différente de la valeur mesurée)
	// measures : liste de toutes les mesures disponibles
	// radius : rayon de la zone à considérer pour l'estimation (par défaut 0.02)
	// seuil_limite : seuil de différence pour considérer un capteur comme détourné (par défaut 20.0)
	// k : nombre de voisins à utiliser pour l'estimation (par défaut 4)
	// step : pas de discrétisation de la zone (par défaut 1)
	// Retourne une liste de pointeurs vers les capteurs détournés
	static vector<const Sensor *> TrouverCapteursDetournes(double radius = 0.02, unordered_map<unsigned int, double> seuils_limite = {{0, 20.0}}, time_t start=0, time_t stop=-1);

	// Trouve les capteurs similaires à un capteur de référence
	// id_ref : identifiant du capteur de référence
	// measures : liste de toutes les mesures disponibles
	// Retourne une liste de pointeurs vers les capteurs similaires
	static vector<const Sensor *> ListerCapteursSimilaires(unsigned int id_ref, time_t start, time_t stop);

private:
	// Fonction utilitaire pour recuperer la liste de toutes les mesures
	static unordered_map<unsigned int, vector<Measurement *>> GetMeasures(time_t start, time_t stop);

	// Fonction utilitaire pour calculer la distance entre deux points géographiques
	static double GetDistance(double lat1, double lon1, double lat2, double lon2);
	static double GetDistance(const Sensor &s1, const Sensor &s2);
	static double GetDistance(const Measurement &m1, const Measurement &m2);
	static double GetDistance(const Measurement *m1, double lat, double lon);
};