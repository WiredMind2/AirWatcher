/*************************************************************************
analyse.cpp  -  Fonctions d'analyse des données de qualité de l'air (statistiques, anomalies, etc.).
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "../couche_metier/Measurement.h"
#include "../couche_metier/Cleaner.h"
#include "../couche_metier/processing.h"
#include "analyse.h"
#include "../couche_acces_aux_donnees/CSVHandler.h"

using namespace std;

//----------------------------------------------------------------- FONCTIONS D'ANALYSE
// Chaque fonction analyse les données de qualité de l'air pour extraire des informations utiles.

void analyse_donnees_capteurs()
{
	cout << "\033[1;32mAnalyse des données des capteurs.\033[0m" << endl;

	double latitude = demander_coord("latitude");
	double longitude = demander_coord("longitude");

	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	cout << "Analyse de la qualité de l'air à la position (" << latitude << ", " << longitude << ") entre " << put_time(localtime(&dateDebut), "%Y-%m-%d") << " et " << put_time(localtime(&dateFin), "%Y-%m-%d") << endl;

	// Appel à la fonction de traitement pour analyser les données
	auto qualiteAir = Processing::EstimationQualiteAirPos(latitude, longitude, dateDebut, dateFin);
	if (qualiteAir.empty())
	{
		cout << "Aucune donnée de qualité de l'air disponible pour cette position et cette période." << endl;
		return;
	}

	// cout << "Qualité de l'air estimée à la position (" << latitude << ", " << longitude << ") : " << endl;
	for (const auto &pair : qualiteAir)
	{
		cout << "	" << CSVHandler::getAttribute(pair.first)->GetAttributeID() << ": Valeur estimée: " << fixed << setprecision(2) << pair.second << endl;
	}
};

void identifier_capteurs_non_fiables()
{
	// Appel à la fonction de traitement pour trouver les capteurs non fiables
	time_t dateDebut = demander_date("début");
	time_t dateFin = demander_date("fin");

	cout << "\033[1;31mAnalyse des capteurs non fiables.\033[0m" << endl;

	unordered_map<string, double> seuils_limite = {
		{"O3", 20.0},
		{"NO2", 20.0},
		{"SO2", 20.0},
		{"PM10", 20.0}
	};

	unordered_map<unsigned int, double> seuils_limite_id;
	for (const auto &pair : seuils_limite)
	{
		seuils_limite_id[CSVHandler::getAttributeID(pair.first)] = pair.second;
	}

	vector<const Sensor *> capteurs_non_fiables = Processing::TrouverCapteursDetournes(1.0, seuils_limite_id, dateDebut, dateFin);

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

	int cleanerID;
	cout << "Veuillez entrer l'ID du purificateur à analyser : ";
	cin >> cleanerID;

	Cleaner* cleaner = CSVHandler::getCleaner(cleanerID);
	if (cleaner->GetCleanerID() == 0)
	{
		cerr << "Purificateur non trouvé." << endl;
		return;
	}

	cout << "ID du purificateur : " << cleanerID << endl;

	// time_t dateDebut = demander_date("début");
	// time_t dateFin = demander_date("fin");

	// const int dayInSeconds = 86400; // Nombre de secondes dans un jour

	// Appel à la fonction de traitement pour analyser l'impact sur une zone autour du purificateur
	auto qualiteAvant = Processing::EstimationQualiteAirZone(cleaner->GetLatitude(), cleaner->GetLongitude(), 10.0, 0, cleaner->GetTimeStart());
	cout << "Qualité de l'air avant nettoyage : " << endl;
	for (const auto &pair : qualiteAvant)
	{
		cout << "	" << CSVHandler::getAttribute(pair.first)->GetAttributeID() << ": Valeur estimée: " << fixed << setprecision(2) << pair.second << endl;
	}

	auto qualiteApres = Processing::EstimationQualiteAirZone(cleaner->GetLatitude(), cleaner->GetLongitude(), 10.0, cleaner->GetTimeStop(), -1);
	cout << "Qualité de l'air après nettoyage : " << endl;
	for (const auto &pair : qualiteApres)
	{
		cout << "	" << CSVHandler::getAttribute(pair.first)->GetAttributeID() << ": Valeur estimée: " << fixed << setprecision(2) << pair.second << endl;
	}
};

time_t demander_date(const string &desc)
{
	struct tm tm = {};

	while (true)
	{
		cout << "Veuillez entrer la date de " << desc << " (YYYY-MM-DD): ";
		string date;
		cin >> date;
		istringstream ss(date);
		ss >> get_time(&tm, "%Y-%m-%d");

		if (ss.fail())
		{
			cerr << "Erreur de format de date. Format attendu : YYYY-MM-DD" << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Date entrée : " << put_time(&tm, "%Y-%m-%d") << endl;
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