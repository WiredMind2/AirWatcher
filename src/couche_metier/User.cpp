/*************************************************************************
User.cpp  -  Implémentation des méthodes de la classe User pour la gestion des utilisateurs.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <list>
using namespace std;

//------------------------------------------------------ Include personnel
#include "User.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// list<Sensor> User::getSensors()
// // Algorithme :
// //
// {
//     return ;
// } //----- Fin de getSensors

// list<Sensor> User::compareSensor(Sensor sensor)
// // Algorithme :
// //
// {

//     list<Sensor> result;
//     for (Sensor s : sensors) {
//         if (s.getID() == sensor.getID()) {
//             result.push_back(s);
//         }
//     }
//     return result;
// } //----- Fin de compareSensor

double User::getGeoPoint(double latitude, double longitude)
// Algorithme :
//
{
    return 0.0;
} //----- Fin de getGeoPoint

double User::getGeoZoneMean(double latitude, double longitude, double radius)
// Algorithme :
//
{
    return 0.0;
} //----- Fin de getGeoZoneMean


//------------------------------------------------------------------ PRIVE

unsigned char User::userType = 0; // Initialisation du type d'utilisateur global
//----------------------------------------------------- Méthodes protégées