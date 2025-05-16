/*************************************************************************
                           Mesurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Mesurement> (fichier Mesurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Mesurement::Mesurement(time_t timestamp, double value, const string& sensorID, const string& attributeID)
// Algorithme :
//
    : timestamp(timestamp), value(value), sensorID(sensorID), attributeID(attributeID)
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesurement>" << endl;
#endif
} //----- Fin de Mesurement

Mesurement::~Mesurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesurement>" << endl;
#endif
} //----- Fin de ~Mesurement

Sensor* Mesurement::GetSensor() const {
    return nullptr;
}

double Mesurement::GetValue() const {
    return value;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées