/*************************************************************************
                           PointsUtilisateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PointsUtilisateurs> (fichier PointsUtilisateurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PointsUtilisateurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PointsUtilisateurs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
PointsUtilisateurs & PointsUtilisateurs::operator = ( const PointsUtilisateurs & unPointsUtilisateurs )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PointsUtilisateurs::PointsUtilisateurs ( const PointsUtilisateurs & unPointsUtilisateurs )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PointsUtilisateurs>" << endl;
#endif
} //----- Fin de PointsUtilisateurs (constructeur de copie)


PointsUtilisateurs::PointsUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PointsUtilisateurs>" << endl;
#endif
} //----- Fin de PointsUtilisateurs


PointsUtilisateurs::~PointsUtilisateurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PointsUtilisateurs>" << endl;
#endif
} //----- Fin de ~PointsUtilisateurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

