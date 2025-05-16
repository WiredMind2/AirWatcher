/*************************************************************************
                           User  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
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

//-------------------------------------------- Constructeur - destructeur

User::User(const string &id, int points)
// Algorithme :
//
    : userID(id), points(points)
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User

User::~User()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées