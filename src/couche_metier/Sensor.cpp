/*************************************************************************
Sensor.cpp  -  Implémentation des méthodes de la classe Sensor pour la gestion des capteurs de qualité de l'air.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Sensor.h"
#include "Measurement.h"

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