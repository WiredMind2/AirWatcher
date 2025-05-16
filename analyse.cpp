/*************************************************************************
                           analyse  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <analyse> (fichier analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "analyse.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type analyse::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
analyse::analyse ( const analyse & unanalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <analyse>" << endl;
#endif
} //----- Fin de analyse (constructeur de copie)


analyse::analyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <analyse>" << endl;
#endif
} //----- Fin de analyse


analyse::~analyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <analyse>" << endl;
#endif
} //----- Fin de ~analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

