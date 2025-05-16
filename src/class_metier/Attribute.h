/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined ( ATTRIBUTE_H )
#define ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using std::string;

//------------------------------------------------------------- Constantes

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
    Attribute(int id, const string &unit, const string &description);
    // Mode d'emploi :
    //  Initialise un attribut avec un identifiant, une unité et une description.
    //
    // Contrat :
    //

    // Destructeur
    virtual ~Attribute();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int attributeID;
    string unit;
    string description;

};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // ATTRIBUTE_H