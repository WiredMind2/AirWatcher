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

//-------------------------------------------- Constructeur - destructeur

Sensor::Sensor(unsigned int id, double lat, double lon, unsigned int userID)
// Algorithme :
//
    : sensorID(id), latitude(lat), longitude(lon), userID(userID)
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::~Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


double Sensor::GetLongitude() const {
    return longitude;
}

double Sensor::GetLatitude() const {
    return latitude;
}

unsigned int Sensor::GetSensorID() const {
    return 1; // Placeholder, should return the actual sensor ID
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées