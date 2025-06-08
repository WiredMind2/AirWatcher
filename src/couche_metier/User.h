/*************************************************************************
User.h  -  Déclaration de la classe User représentant un utilisateur de la plateforme AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using std::string;
using std::list;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
// Représente un utilisateur du système.
//------------------------------------------------------------------------

class Sensor; // Forward declaration

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    list<Sensor> getSensors();
    list<Sensor> compareSensor(Sensor sensor);
    double getGeoPoint(double latitude, double longitude);
    double getGeoZoneMean(double latitude, double longitude, double radius);
    int getPoints() const { return points; }
    void addPoints(int _points) { points += _points; }

    static unsigned char GetGlobalUserType() {return userType;};
    static void SetGlobalUserType(unsigned char _userType) { userType = _userType; };

    User(unsigned int id): userID(id) {};
    virtual ~User() {};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unsigned int userID;
    int points = 0;
    static unsigned char userType;
};

//-------------------------------- Autres définitions dépendantes de <User>