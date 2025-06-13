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
#include "../couche_metier/analyse.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Administration::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void consulter_capteurs_defaillants()
{
    double seuil_limite, radius;
    string attribute;

    time_t start = demander_date("début");
    time_t stop = demander_date("fin");

    cout << "Entrez le rayon de la zone à analyser (en degrés): ";
    cin >> radius;

    while (radius <= 0)
    {
        cout << "Le rayon doit être supérieur à 0. Veuillez réessayer : ";
        cin >> radius;
    }

    cout << "Entrez l'attribut à analyser (O3, NO2, SO2, PM10) : ";
    unsigned int attribute_id = 0;
    // Convertit l'attribut en ID
    while (attribute_id == 0)
    {
        cin >> attribute;

        try
        {
            attribute_id = CSVHandler::getAttributeID(attribute);
        }
        catch (const exception &e)
        {
            cerr << "Attribut invalide. Veuillez entrer O3, NO2, SO2 ou PM10 : ";
        }
    }

    cout << "Entrez le seuil choisi : ";
    cin >> seuil_limite;

    vector<const Sensor *> capteurs_defaillants = Processing::TrouverCapteursDetournes(radius, {{attribute_id, seuil_limite}}, start, stop);

    if (capteurs_defaillants.empty())
    {
        cout << "Aucun capteur défaillant trouvé.\n";
    }

    else
    {
        cout << "Capteurs défaillants détectés :\n";
        for (const auto &sensor : capteurs_defaillants)
        {
            cout << "Capteur d'identifiant" << sensor->GetSensorID() << " " << "\n";
        }
    }
}

void marquer_capteur_non_fiable()
{

    // Récupérer la liste des non fiables

    // Choisir un capteur dans cette liste à marquer comme non fiable
    int sensor_id;
    cout << "Veuillez entrer l'identifiant du capteur à marquer comme non fiable: " << "\n";
    cin >> sensor_id;

    // Récupérer le capteur associé à l'id
    Sensor *capteur_non_fiable = CSVHandler::getSensor(sensor_id);

    // Marquer le capteur choisi comme non fiable : fonctionnalité non implémentée dans cette version

    cout << "Le capteur n°" << capteur_non_fiable->GetSensorID() << "a été marqué comme non fiable." << "\n";
}

void marquer_user_malicieux()
{
    unsigned int user_malicieux;
    cout << "Veuillez entrer l'identifiant de l'utilisateur à signaler: " << "\n";
    cin >> user_malicieux;

    // Vérifie si l'utilisateur existe parmi les individus (utilisateurs privés uniquement)

    try
    {
        CSVHandler::getIndividual(user_malicieux); // Lève une exception si non trouvé
        CSVHandler::addUnreliable("", {user_malicieux});
        cout << "L'utilisateur " << user_malicieux << " a été signalé. Il ne pourra plus accumuler de points.\n";
    }
    catch (const exception &e)
    {
        cerr << "Erreur : utilisateur introuvable ou non individuel.\n";
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
