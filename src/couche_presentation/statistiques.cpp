/*************************************************************************
 statistiques.cpp  -  Implémente les fonctions de calcul et d'affichage des statistiques sur la qualité de l'air et l'utilisation de l'application.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE
#include "statistiques.h"
#include <iostream>
#include "../couche_metier/processing.h"

//----------------------------------------------------------------- FONCTIONS STATISTIQUES
// Chaque fonction calcule ou affiche une statistique sur la qualité de l'air ou l'utilisation.

void calculQualiteAirPos() {
	double lat, lon;
	int k;

	std::cout << "Entrez la latitude: ";
	std::cin >> lat;
	std::cout << "Entrez la longitude: ";
	std::cin >> lon;
	std::cout << "Entrez le nombre de voisins (k): ";
	std::cin >> k;

	// Appel à la fonction de traitement pour estimer la qualité de l'air
	double estimation = AirQualityProcessor::EstimationQualiteAirPos(lat, lon, k);
	if (std::isnan(estimation)) {
		std::cout << "Aucune mesure disponible pour cette position.\n";
	} else {
		std::cout << "Estimation de la qualité de l'air à (" << lat << ", " << lon << ") : " << estimation << "\n";
	}
}

void calculQualiteAirZone() {
	double lat, lon, radius;
	int k;

	std::cout << "Entrez la latitude du centre de la zone: ";
	std::cin >> lat;
	std::cout << "Entrez la longitude du centre de la zone: ";
	std::cin >> lon;
	std::cout << "Entrez le rayon de la zone (en degrés): ";
	std::cin >> radius;
	std::cout << "Entrez le nombre de voisins (k): ";
	std::cin >> k;

	// Appel à la fonction de traitement pour estimer la qualité de l'air sur la zone
	double estimation = AirQualityProcessor::EstimationQualiteAirZone(lat, lon, radius, k);
	if (std::isnan(estimation)) {
		std::cout << "Aucune mesure disponible pour cette zone.\n";
	} else {
		std::cout << "Estimation de la qualité de l'air sur la zone centrée à (" << lat << ", " << lon << ") : " << estimation << "\n";
	}
}

void classerCapteursSimilaires() {
	int id_ref;
	std::cout << "Entrez l'identifiant du capteur de référence': ";

	std::cin >> id_ref;

	std::cout << "Recherche des capteurs similaires au capteur ID " << id_ref << "...\n";

	// Appel à la fonction de traitement pour trouver les capteurs similaires
	std::vector<const Sensor *> capteurs_similaires = AirQualityProcessor::ListerCapteursSimilaires(id_ref, 0, -1);
	if (capteurs_similaires.empty()) {
		std::cout << "Aucun capteur similaire trouvé.\n";
	} else {
		std::cout << "Capteurs similaires au capteur " << id_ref << ":\n";
		for (const Sensor* capteur : capteurs_similaires) {
			std::cout << "Capteur ID: " << capteur->GetSensorID() << "\n";
		}
	}
}