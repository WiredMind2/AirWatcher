#include "statistiques.h"
#include <iostream>
#include "../processing.h"

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
	double step;

	std::cout << "Entrez la latitude du centre de la zone: ";
	std::cin >> lat;
	std::cout << "Entrez la longitude du centre de la zone: ";
	std::cin >> lon;
	std::cout << "Entrez le rayon de la zone (en degrés): ";
	std::cin >> radius;
	std::cout << "Entrez le nombre de voisins (k): ";
	std::cin >> k;
	std::cout << "Entrez le pas de discrétisation (step): ";
	std::cin >> step;

	// Appel à la fonction de traitement pour estimer la qualité de l'air sur la zone
	double estimation = AirQualityProcessor::EstimationQualiteAirZone(lat, lon, radius, k, step);
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

	// Appel à la fonction de traitement pour trouver les capteurs similaires
	std::vector<const Measurement *> capteurs_similaires = AirQualityProcessor::ListerCapteursSimilaires(id_ref, 0, -1);
	if (capteurs_similaires.empty()) {
		std::cout << "Aucun capteur similaire trouvé.\n";
	} else {
		std::cout << "Capteurs similaires au capteur " << id_ref << ":\n";
		for (const auto &capteur : capteurs_similaires) {
			std::cout << "Capteur ID: " << capteur->GetSensor()->GetSensorID()  << ", Valeur: " << capteur->GetValue() << "\n";
		}
	}
}