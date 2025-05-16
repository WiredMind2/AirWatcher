#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "Mesurement.h"

class AirQualityProcessor
{
public:
	// Estime la qualité de l'air à une position géographique donnée (lat, lon)
	// lat, lon : coordonnées de la position
	// measures : liste de toutes les mesures disponibles
	// k : nombre de voisins à utiliser (par défaut 4)
	// Retourne la valeur estimée de la qualité de l'air ou NaN si aucune mesure n'est disponible
	static double EstimationQualiteAirPos(double lat, double lon, int k = 4);

	// Estime la qualité de l'air sur une zone circulaire (centre lat, lon, rayon en degrés)
	// lat, lon : coordonnées du centre de la zone
	// radius : rayon de la zone en degrés
	// measures : liste de toutes les mesures disponibles
	// k : nombre de voisins à utiliser (par défaut 4)
	// step : pas de discrétisation de la zone (par défaut 0.01)
	// Retourne la moyenne des estimations dans la zone
	static double EstimationQualiteAirZone(double lat, double lon, double radius, int k = 4, double step = 0.01);

	// Trouve les capteurs détournés (valeur estimée différente de la valeur mesurée)
	// measures : liste de toutes les mesures disponibles
	// radius : rayon de la zone à considérer pour l'estimation (par défaut 0.02)
	// seuil_limite : seuil de différence pour considérer un capteur comme détourné (par défaut 20.0)
	// k : nombre de voisins à utiliser pour l'estimation (par défaut 4)
	// step : pas de discrétisation de la zone (par défaut 0.01)
	// Retourne une liste de pointeurs vers les capteurs détournés
	static std::vector<const Mesurement *> TrouverCapteursDetournes(double radius = 0.02, double seuil_limite = 20.0, int k = 4, double step = 0.01);

	// Trouve les capteurs similaires à un capteur de référence
	// id_ref : identifiant du capteur de référence
	// measures : liste de toutes les mesures disponibles
	// Retourne une liste de pointeurs vers les capteurs similaires
	static std::vector<const Mesurement *> TrouverCapteursSimilaires(int id_ref);

private:
	// Fonction utilitaire pour recuperer la liste de toutes les mesures
	static std::vector<Mesurement> GetAllMeasures();
};