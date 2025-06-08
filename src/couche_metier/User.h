/*************************************************************************
                           User  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
using std::string;
using std::list;

//------------------------------------------------------------- Constantes

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

#endif // USER_H