#include <iostream>
#include "processing.h"

void MenuStatistiques(){
	int choice;
	do {
		std::cout << "Menu Statistiques:\n";
		std::cout << "1. Calculer la qualité d'air pour une position\n";
		std::cout << "2. Calculer la qualité d'air médiane sur une zone\n";
		std::cout << "3. Classer les capteurs similaires\n";
		std::cout << "5. Quitter\n";
		std::cout << "Veuillez entrer votre choix (1-5): ";
		std::cin >> choice;

		switch (choice) {
			case 1:
				calculQualiteAirPos();
				break;
			case 2:
				calculQualiteAirZone();
				break;
			case 3:
				classerCapteursSimilaires();
				break;
			case 5:
				break;
			default:
				std::cout << "Choix invalide. Veuillez réessayer.\n";
				break;
		}
	} while (choice != 5);
}

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
	std::vector<const Measure *> capteurs_similaires = AirQualityProcessor::TrouverCapteursSimilaires(id_ref);
	if (capteurs_similaires.empty()) {
		std::cout << "Aucun capteur similaire trouvé.\n";
	} else {
		std::cout << "Capteurs similaires au capteur " << id_ref << ":\n";
		for (const auto &capteur : capteurs_similaires) {
			std::cout << "Capteur ID: " << capteur->id << ", Valeur: " << capteur->value << "\n";
		}
	}
}