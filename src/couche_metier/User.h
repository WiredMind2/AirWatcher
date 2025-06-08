/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( USER_H )
#define USER_H

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

#endif // USER_H