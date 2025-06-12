/*************************************************************************
statistiques.cpp  -  Fonctions de calcul et d'affichage des statistiques sur la qualité de l'air et l'utilisation de l'application.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE
#include "statistiques.h"
#include <iostream>
#include <iomanip>
#include "../couche_metier/processing.h"
#include "analyse.h"

//----------------------------------------------------------------- FONCTIONS STATISTIQUES
// Chaque fonction calcule ou affiche une statistique sur la qualité de l'air ou l'utilisation.

void calculQualiteAirPos() {
	double lat, lon;

	std::cout << "Entrez la latitude: ";
	std::cin >> lat;
	std::cout << "Entrez la longitude: ";
	std::cin >> lon;

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	// Appel à la fonction de traitement pour estimer la qualité de l'air
	auto estimation = Processing::EstimationQualiteAirPos(lat, lon, dateDebut, dateFin);
	if (estimation.empty()) {
		std::cout << "Aucune mesure disponible pour cette position.\n";
	} else {
		std::cout << "Estimation de la qualité de l'air à (" << lat << ", " << lon << ") : " << std::endl;
		for (const auto &pair : estimation) {
			std::cout << "Attribut ID: " << pair.first << ", Valeur estimée: " << fixed << setprecision(2) << pair.second << std::endl;
		}
	}
}

void calculQualiteAirZone() {
	double lat, lon, radius;

	std::cout << "Entrez la latitude du centre de la zone: ";
	std::cin >> lat;
	std::cout << "Entrez la longitude du centre de la zone: ";
	std::cin >> lon;
	std::cout << "Entrez le rayon de la zone (en degrés): ";
	std::cin >> radius;

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");


	// Appel à la fonction de traitement pour estimer la qualité de l'air sur la zone
	auto estimation = Processing::EstimationQualiteAirZone(lat, lon, radius, dateDebut, dateFin, true);
	if (estimation.empty()) {
		std::cout << "Aucune mesure disponible pour cette zone.\n";
	} else {
		std::cout << "Estimation de la qualité de l'air sur la zone centrée à (" << lat << ", " << lon << ") : " << std::endl;
		for (const auto &pair : estimation) {
			std::cout << "Attribut ID: " << pair.first << ", Valeur estimée: " << fixed << setprecision(2) << pair.second << std::endl;
		}
	}
}

void classerCapteursSimilaires() {
	int id_ref;
	std::cout << "Entrez l'identifiant du capteur de référence': ";

	std::cin >> id_ref;

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	std::cout << "Recherche des capteurs similaires au capteur ID " << id_ref << "...\n";

	// Appel à la fonction de traitement pour trouver les capteurs similaires
	std::vector<const Sensor *> capteurs_similaires = Processing::ListerCapteursSimilaires(id_ref, dateDebut, dateFin);
	if (capteurs_similaires.empty()) {
		std::cout << "Aucun capteur similaire trouvé.\n";
	} else {
		std::cout << "Capteurs similaires au capteur " << id_ref << ":\n";
		for (const Sensor* capteur : capteurs_similaires) {
			std::cout << "Capteur ID: " << capteur->GetSensorID() << "\n";
		}
	}
}