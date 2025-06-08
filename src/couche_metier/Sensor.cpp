/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Sensor.h"
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Sensor::GetLongitude() const {
    return longitude;
}

double Sensor::GetLatitude() const {
    return latitude;
}

unsigned int Sensor::GetSensorID() const {
    return sensorID;
}

unsigned int Sensor::GetUserID() const {
    return userID;
}

void Sensor::SetUserID(unsigned int id) {
    userID = id;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées