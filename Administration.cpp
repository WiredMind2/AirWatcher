/*************************************************************************
                           Administration  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Administration> (fichier Administration.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Administration.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Administration::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Administration & Administration::operator = ( const Administration & unAdministration )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Administration::Administration ( const Administration & unAdministration )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administration>" << endl;
#endif
} //----- Fin de Administration (constructeur de copie)


Administration::Administration ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Administration>" << endl;
#endif
} //----- Fin de Administration


Administration::~Administration ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Administration>" << endl;
#endif
} //----- Fin de ~Administration


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

