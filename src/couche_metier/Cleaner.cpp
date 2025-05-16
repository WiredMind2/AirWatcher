/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Cleaner::start()
// Algorithme :
// Démarre le nettoyeur et enregistre l'heure de début.
//
{
    timeStart = time(nullptr);
    cout << "Cleaner started at: " << ctime(&timeStart) << endl;
} //----- Fin de start

void Cleaner::stop()
// Algorithme :
// Arrête le nettoyeur et enregistre l'heure de fin.
//
{
    timeStop = time(nullptr);
    cout << "Cleaner stopped at: " << ctime(&timeStop) << endl;
} //----- Fin de stop

//-------------------------------------------- Constructeur - destructeur

Cleaner::Cleaner(const unsigned int &cleanerID, double latitude, double longitude, const unsigned int &providerID)
// Algorithme :
// Initialise les attributs du nettoyeur.
//
    : cleanerID(cleanerID), latitude(latitude), longitude(longitude), providerID(providerID)
{
    this->timeStart = 0;
    this->timeStop = 0;
    cout << "Cleaner created with ID: " << cleanerID << endl;
} //----- Fin de Cleaner

Cleaner::~Cleaner()
// Algorithme :
//
{
    cout << "Cleaner with ID: " << cleanerID << " destroyed." << endl;
} //----- Fin de ~Cleaner

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées