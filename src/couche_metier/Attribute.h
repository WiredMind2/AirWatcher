/*************************************************************************
Attribute.h  -  Déclaration des structures et fonctions liées aux attributs de mesure dans AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
using std::string;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
// Représente un attribut mesuré par un capteur (ex : CO2, température, etc.)
//------------------------------------------------------------------------

class Attribute
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Constructeur
    Attribute(int id, const string &unit, const string &description): 
        attributeID(id), unit(unit), description(description) {};

    // Destructeur
    virtual ~Attribute() {};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int attributeID;
    string unit;
    string description;

};

//-------------------------------- Autres définitions dépendantes de <Attribute>