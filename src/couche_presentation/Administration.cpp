/*************************************************************************
Administration.cpp  -  Fonctions d'administration pour la gestion des utilisateurs, capteurs, et droits d'accès dans AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Administration> (fichier Administration.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "../couche_metier/processing.h"
#include <vector>
#include "../couche_acces_aux_donnees/CSVHandler.h"


//------------------------------------------------------ Include personnel
#include "Administration.h"
#include "analyse.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Administration::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


void Administration::consulter_capteurs_defaillants()
{
    double seuil_limite, radius;
    int k;

	time_t start = demander_date("début");
	time_t stop = demander_date("fin");


    cout << "Entrez le rayon de la zone (en degrés): ";
    cin >> radius;
    cout << "Entrez le seuil choisi : ";
    cin >> seuil_limite;
    cout << "Entrez le nombre de voisins (k): ";
    cin >> k;

    vector<const Sensor *> capteurs_defaillants = AirQualityProcessor::TrouverCapteursDetournes(radius, seuil_limite, k, start, stop);
    for (const auto &sensor : capteurs_defaillants)
    {
        cout << "Le capteur" << sensor->GetSensorID() << "est défaillant." << "\n";
    }
}

void Administration::marquer_capteur_non_fiable()
{

    // Récupérer la liste des non fiables
    consulter_capteurs_defaillants();

    // Choisir un capteur dans cette liste à marquer comme non fiable
    int sensor_id;
    cout << "Veuillez entrer l'identifiant du capteur à marquer comme non fiable"; // Ajouter gestion de si dans la liste ou non
    cin >> sensor_id;

    // Récupérer le capteur associé à l'id
    Sensor* capteur_non_fiable = CSVHandler::getSensor(sensor_id);

    // TO DO : Marquer le capteur choisi comme non fiable (mettre ses mesures à -1 ? méthode dans GouvAgency?)
    cout << "Le capteur n°" << capteur_non_fiable->GetSensorID() << "a été marqué comme non fiable" << "\n";
}

void Administration::marquer_user_malicieux()
{
    int user_id; // TO DO : changer le type de user_id pour qu'il soit compatible avec le type d'id dans CSVHandler
    cout << "Veuillez entrer l'identifiant de l'utilisateur à signaler";
    cin >> user_id;

    // Récupérer l'user associé à l'id : chercher dans la liste des unreliable users donnée par findUnreliable
    //User user_malicieux = CSVHandler::getUser(user_id); // Problème : les id sont des string, handler à revoir

    // Le classer comme malicieux
    //GouvAgency(4).classifyUnreliable(user_malicieux); // TO DO : revoir avec le bon id, méthodes GouvAgency en static ?
    cout << "L'utilisateur" << user_id << "a été signalé. Il ne pourra plus accumuler de points" << "\n";
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées




