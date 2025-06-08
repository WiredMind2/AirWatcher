/*************************************************************************
GouvAgency.h  -  Déclaration de la classe GouvAgency représentant une agence gouvernementale dans AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GouvAgency> (fichier GouvAgency.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "User.h"
using std::list;

//------------------------------------------------------------------------
// Rôle de la classe <GouvAgency>
//
// Représente une agence gouvernementale.
//------------------------------------------------------------------------

class GouvAgency : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void classifyUnreliable(User &user);
    void classifyReliable(User &user);
    list<User> getUsers();
    list<User> findUnreliable();

    // Constructor
    GouvAgency(unsigned int id) : User(id) {};

    // Destructor
    ~GouvAgency() override {};

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GouvAgency>