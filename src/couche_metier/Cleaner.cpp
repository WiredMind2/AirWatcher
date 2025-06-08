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
