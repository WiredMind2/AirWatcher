/*************************************************************************
Cleaner.cpp  -  Implémentation des méthodes de la classe Cleaner pour la gestion des dispositifs de nettoyage.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
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
