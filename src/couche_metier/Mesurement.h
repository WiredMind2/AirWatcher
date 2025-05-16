/*************************************************************************
                           Mesurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Mesurement> (fichier Mesurement.h) ----------------
#if ! defined ( MESUREMENT_H )
#define MESUREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
#include "Sensor.h"
using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesurement>
//
// Représente une mesure prise par un capteur.
//------------------------------------------------------------------------

class Mesurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Mesurement(time_t timestamp, double value, const string& sensorID, const string& attributeID);
    virtual ~Mesurement();

    Sensor * GetSensor() const;
    double GetValue() const;

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    time_t timestamp;
    double value;
    string sensorID;
    string attributeID;

};

//-------------------------------- Autres définitions dépendantes de <Mesurement>

#endif // MESUREMENT_H