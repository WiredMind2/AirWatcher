#include <iostream>
#include <vector>
#include "../couche_metier/Mesurement.h"
#include "../couche_metier/Cleaner.h"
#include "../processing.h"

using namespace std;

void analyse_donnees_capteurs(){
	cout << "\033[1;32mAnalyse des données des capteurs.\033[0m" << endl;
	
	double latitude = 48.8566; // TODO - Choisir une vraie latitude
	double longitude = 2.3522; // TODO - Choisir une vraie longitude
	// TODO - Choisir une vraie date

	// Appel à la fonction de traitement pour analyser les données
	double qualiteAir = AirQualityProcessor::EstimationQualiteAirPos(latitude, longitude);
	cout << "Qualité de l'air estimée à la position (" << latitude << ", " << longitude << ") : " << qualiteAir << endl;

};

void identifier_capteurs_non_fiables(){
	cout << "\033[1;31mAnalyse des capteurs non fiables.\033[0m" << endl;
	// Appel à la fonction de traitement pour trouver les capteurs non fiables
	vector<const Sensor *> capteurs_non_fiables = AirQualityProcessor::TrouverCapteursDetournes();

	// Affichage des capteurs non fiables
	if (capteurs_non_fiables.empty()) {
		cout << "Aucun capteur non fiable trouvé." << endl;
	} else {
		cout << "Capteurs non fiables trouvés : " << endl;
		for (const Sensor *capteur : capteurs_non_fiables) {
			cout << "Capteur ID: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude() << ", Longitude: " << capteur->GetLongitude() << endl;
		}
	}

};

void analyser_impact_purificateurs(){
	cout << "\033[1;33mAnalyse de l'impact des purificateurs.\033[0m" << endl;

	Cleaner cleaner = Cleaner(1, 48.8566, 2.3522, 123); // TODO - Choisir un vrai purificateur
	cout << "ID du purificateur : " << cleaner.GetCleanerID() << endl;
	
	// TODO - Utiliser les dates de début et de fin

	// Appel à la fonction de traitement pour analyser l'impact
	double qualiteAvant = AirQualityProcessor::EstimationQualiteAirPos(cleaner.GetLatitude(), cleaner.GetLongitude());
	cout << "Qualité de l'air avant nettoyage : " << qualiteAvant << endl;


	double qualiteApres = AirQualityProcessor::EstimationQualiteAirPos(cleaner.GetLatitude(), cleaner.GetLongitude());
	cout << "Qualité de l'air après nettoyage : " << qualiteApres << endl;
};