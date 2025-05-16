/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if !defined(MESUREMENT_H)
#define MESUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
#include "Sensor.h"
using std::string;

//------------------------------------------------------------- Constantes

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
    Measurement(time_t timestamp, double value, unsigned int sensorID, const string &attributeID);
    virtual ~Measurement();

    Sensor *GetSensor() const { return nullptr; };
    double GetValue() const { return value; };
    time_t GetTimestamp() const { return timestamp; };
    unsigned int GetSensorID() const { return sensorID; };
    string GetAttributeID() const { return attributeID; };

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    time_t timestamp;
    double value;
    unsigned int sensorID;
    string attributeID;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // MESUREMENT_H