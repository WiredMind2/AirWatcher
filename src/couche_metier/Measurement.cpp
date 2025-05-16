/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Measurement::Measurement(time_t timestamp, double value, unsigned int sensorID, const string& attributeID)
// Algorithme :
//
    : timestamp(timestamp), value(value), sensorID(sensorID), attributeID(attributeID)
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement

Measurement::~Measurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées