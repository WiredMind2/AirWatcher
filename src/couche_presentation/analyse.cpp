#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "../couche_metier/Measurement.h"
#include "../couche_metier/Cleaner.h"
#include "../processing.h"
#include "analyse.h"

using namespace std;

void analyse_donnees_capteurs()
{
	cout << "\033[1;32mAnalyse des données des capteurs.\033[0m" << endl;

	double latitude = demander_coord("latitude");
	double longitude = demander_coord("longitude");

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	// Appel à la fonction de traitement pour analyser les données
	double qualiteAir = AirQualityProcessor::EstimationQualiteAirPos(latitude, longitude, dateDebut, dateFin);
	cout << "Qualité de l'air estimée à la position (" << latitude << ", " << longitude << ") : " << qualiteAir << endl;
};

void identifier_capteurs_non_fiables()
{
	cout << "\033[1;31mAnalyse des capteurs non fiables.\033[0m" << endl;
	// Appel à la fonction de traitement pour trouver les capteurs non fiables
	vector<const Sensor *> capteurs_non_fiables = AirQualityProcessor::TrouverCapteursDetournes();

	// Affichage des capteurs non fiables
	if (capteurs_non_fiables.empty())
	{
		cout << "Aucun capteur non fiable trouvé." << endl;
	}
	else
	{
		cout << "Capteurs non fiables trouvés : " << endl;
		for (const Sensor *capteur : capteurs_non_fiables)
		{
			cout << "Capteur ID: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude() << ", Longitude: " << capteur->GetLongitude() << endl;
		}
	}
};

void analyser_impact_purificateurs()
{
	cout << "\033[1;33mAnalyse de l'impact des purificateurs.\033[0m" << endl;

	Cleaner cleaner = Cleaner(1, 48.8566, 2.3522, 123); // TODO - Choisir un vrai purificateur
	cout << "ID du purificateur : " << cleaner.GetCleanerID() << endl;

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	const int dayInSeconds = 86400; // Nombre de secondes dans un jour

	// Appel à la fonction de traitement pour analyser l'impact
	double qualiteAvant = AirQualityProcessor::EstimationQualiteAirPos(cleaner.GetLatitude(), cleaner.GetLongitude(), dateDebut, dateDebut + dayInSeconds);
	cout << "Qualité de l'air avant nettoyage : " << qualiteAvant << endl;

	double qualiteApres = AirQualityProcessor::EstimationQualiteAirPos(cleaner.GetLatitude(), cleaner.GetLongitude(), dateFin, dateFin + dayInSeconds);
	cout << "Qualité de l'air après nettoyage : " << qualiteApres << endl;
};

time_t demander_date(const string &desc)
{
	struct tm tm = {};

	while (true)
	{
		cout << "Veuillez entrer la date de " << desc << " (YYYY-MM-DD): ";
		string date;
		cin >> date;
		std::istringstream ss(date);
		ss >> std::get_time(&tm, "%Y-%m-%d");

		if (ss.fail())
		{
			std::cerr << "Erreur de format de date. Format attendu : YYYY-MM-DD" << std::endl;
		}
		else
		{
			break;
		}
	}

	cout << "Date entrée : " << std::put_time(&tm, "%Y-%m-%d") << std::endl;
	time_t time = mktime(&tm);
	return time;
}

double demander_coord(const string &desc)
{
	double coord;
	while (true)
	{
		cout << "Veuillez entrer la " << desc << ": ";
		cin >> coord;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrée invalide. Veuillez entrer un nombre valide." << endl;
		}
		else
		{
			break;
		}
	}
	return coord;
}