/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <CSVHandler> (fichier CSVHandler.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip> // For get_time

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Variables

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
CSVHandler::CSVHandler ( const CSVHandler & unCSVHandler )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CSVHandler>" << endl;
#endif
} //----- Fin de CSVHandler (constructeur de copie)


CSVHandler::CSVHandler ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CSVHandler>" << endl;
#endif
} //----- Fin de CSVHandler


CSVHandler::~CSVHandler ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CSVHandler>" << endl;
#endif
} //----- Fin de ~CSVHandler


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

