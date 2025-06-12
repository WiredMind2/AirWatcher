/*************************************************************************
Measurement.h  -  Déclaration de la classe Measurement représentant une mesure de qualité de l'air.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
#include "Sensor.h"
using std::string;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
// Représente une mesure prise par un capteur.
//------------------------------------------------------------------------

class Measurement
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    Measurement(time_t timestamp, double value, unsigned int sensorID, const string &attributeID): 
        timestamp(timestamp), value(value), sensorID(sensorID), attributeID(attributeID) {};
    virtual ~Measurement() {};

    Sensor* GetSensor() const;
    double GetValue() const { return value; };
    time_t GetTimestamp() const { return timestamp; };
    unsigned int GetSensorID() const { return sensorID; };
    string GetAttributeID() const { return attributeID; };

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    time_t timestamp;
    double value;
    unsigned int sensorID;
    string attributeID;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>