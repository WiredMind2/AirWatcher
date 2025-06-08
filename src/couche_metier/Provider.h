/*************************************************************************
Provider.h  -  Déclaration de la classe Provider représentant un fournisseur de capteurs.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
#include "User.h"
using std::string;
using std::list;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
// Représente un fournisseur de nettoyeurs.
//------------------------------------------------------------------------

class Cleaner; // Forward declaration

class Provider : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    list<Cleaner> getCleaners();
    // Constructor
    Provider(unsigned int id): User(id) {};

    // Destructor
    ~Provider() override {};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Provider>