/*************************************************************************
CSVHandler.h  -  Déclarations pour la gestion des fichiers CSV (import/export de données).
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CSVHandler> (fichier CSVHandler.h) ----------------
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

#include "../couche_metier/Cleaner.h"
#include "../couche_metier/GouvAgency.h"
#include "../couche_metier/Individual.h"
#include "../couche_metier/Measurement.h"
#include "../couche_metier/Provider.h"
#include "../couche_metier/Sensor.h"
#include "../couche_metier/User.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <CSVHandler>
// La classe CSVHandler est responsable de la gestion et de l'extraction des données
// à partir de fichiers CSV. Elle permet de charger les données des capteurs, mesures,
// utilisateurs, et autres entités métier, et de les organiser dans des structures de données
// appropriées pour une utilisation ultérieure.
//------------------------------------------------------------------------

class CSVHandler
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void extractAll(const string &folder);
    // Mode d'emploi :
    // Cette méthode extrait toutes les données des fichiers CSV situés dans le dossier spécifié.
    // Elle appelle les méthodes spécifiques pour extraire les capteurs, les mesures et les utilisateurs.
    //
    // Contrat :
    // Le dossier spécifié doit contenir les fichiers CSV nécessaires au bon fonctionnement.

    static void extractCleaners(const string &folder);
    // Mode d'emploi :
    // Cette méthode extrait les données des nettoyeurs à partir d'un fichier CSV situé dans le dossier spécifié.
    //
    // Contrat :
    // Le fichier CSV des nettoyeurs doit exister dans le dossier spécifié.

    static void extractSensors(const string &folder);
    // Mode d'emploi :
    // Cette méthode extrait les données des capteurs à partir d'un fichier CSV situé dans le dossier spécifié.
    //
    // Contrat :
    // Le fichier CSV des capteurs doit exister dans le dossier spécifié.

    static void extractMeasurements(const string &folder);
    // Mode d'emploi :
    // Cette méthode extrait les données des mesures à partir d'un fichier CSV situé dans le dossier spécifié.
    //
    // Contrat :
    // Le fichier CSV des mesures doit exister dans le dossier spécifié.

    static void extractIndividuals(const string &folder);
    // Mode d'emploi :
    // Cette méthode extrait les données des utilisateurs à partir d'un fichier CSV situé dans le dossier spécifié.
    //
    // Contrat :
    // Le fichier CSV des utilisateurs doit exister dans le dossier spécifié.

    static void addUnreliable(const string &folder, const vector<unsigned int> &unreliableUserIds);
    // Mode d'emploi :
    // Cette méthode ajoute dans la map filtrée des utilisateurs les utilisateurs non fiables
    //
    // Contrat :
    //


    //getters
    static Cleaner getCleaner(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet Cleaner correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un Cleaner existant.

    static Individual getIndividual(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet Individual correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un Individual existant.

    static Provider getProvider(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet Provider correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un Provider existant.

    static User getUser(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet User correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un User existant.

    static Sensor* getSensor(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet Sensor correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un Sensor existant.

    static unsigned int getFilterdUser(unsigned int id);
    // Mode d'emploi :
    // Retourne un objet User correspondant à l'identifiant spécifié.
    //
    // Contrat :
    // L'identifiant doit correspondre à un User existant.

    static vector<Measurement*> getMeasurement(time_t start, time_t stop);
    // Mode d'emploi :
    // Retourne un vecteur contenant les mesures comprises entre les dates de début et de fin spécifiées.
    //
    // Contrat :
    // Les dates de début et de fin doivent être valides et start doit être antérieur ou égal à stop.

//------------------------------------------------------------------ PRIVE

protected:


//----------------------------------------------------- Attributs protégés

    static unordered_map<unsigned int, Cleaner*> cleaners;
    static unordered_map<unsigned int, Individual*> individuals;
    static multimap<time_t, Measurement*> measurements;
    static unordered_map<unsigned int, Provider*> providers;
    static unordered_map<unsigned int, Sensor*> sensors;
    static unordered_map<unsigned int, int> filterdUsers;

};

//-------------------------------- Autres définitions dépendantes de <CSVHandler>

