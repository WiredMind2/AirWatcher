/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
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