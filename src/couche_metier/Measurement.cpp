/*************************************************************************
Measurement.cpp  -  Implémentation des méthodes de la classe Measurement pour la gestion des mesures de qualité de l'air.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"
#include "../couche_acces_aux_donnees/CSVHandler.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Sensor* Measurement::GetSensor() const
{
    return CSVHandler::getSensor(sensorID);
}
