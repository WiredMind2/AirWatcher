/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if !defined(MESUREMENT_H)
#define MESUREMENT_H

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

#endif // MESUREMENT_H