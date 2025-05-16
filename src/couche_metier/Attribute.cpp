/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Constructeur
Attribute::Attribute(int id, const string &unit, const string &description)
// Algorithme :
// Initialise les attributs de la classe avec les valeurs fournies.
//
    : attributeID(id), unit(unit), description(description)
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
} //----- Fin de Attribute

// Destructeur
Attribute::~Attribute()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées