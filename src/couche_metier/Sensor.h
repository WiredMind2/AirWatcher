/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using std::string;
using std::list;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
// Représente un capteur associé à un utilisateur.
//------------------------------------------------------------------------

class Mesurement; // Forward declaration

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    list<Mesurement> getData();

    Sensor(unsigned int id, double lat, double lon, unsigned int userID);
    virtual ~Sensor();

    unsigned int GetSensorID() const;
    double GetLatitude() const;
    double GetLongitude() const;
    unsigned int GetUserID() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unsigned int sensorID;
    double latitude;
    double longitude;
    unsigned int userID;
};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // SENSOR_H