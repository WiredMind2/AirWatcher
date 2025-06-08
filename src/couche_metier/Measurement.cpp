/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
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
