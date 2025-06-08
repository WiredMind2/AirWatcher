/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( SENSOR_H )
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using std::string;
using std::list;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
// Représente un capteur associé à un utilisateur.
//------------------------------------------------------------------------

class Measurement; // Forward declaration

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    list<Measurement> getData();

    Sensor(unsigned int id, double lat, double lon, unsigned int userID): 
        sensorID(id), latitude(lat), longitude(lon), userID(userID) {};
    virtual ~Sensor() {};

    unsigned int GetSensorID() const;
    double GetLatitude() const;
    double GetLongitude() const;
    unsigned int GetUserID() const;

    void SetUserID(unsigned int id);

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