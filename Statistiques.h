/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if ! defined ( Statistiques_H )
#define Statistiques_H
#include <list>

using namespace std;
#include "Sensor.h"
#include "Measurement.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
//
//
//------------------------------------------------------------------------

class Statistiques 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Statistiques & operator = ( const Statistiques & unStatistiques );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( const Statistiques & unStatistiques );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

std::list<Sensor> getSensors();
// fonctions William;

//----------------------------------------------------- Attributs protégés

std::list<Sensor> sensors;
std::list<Measurement> measures;

};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // Statistiques_H

