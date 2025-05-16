/*************************************************************************
                           GouvAgency  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <GouvAgency> (fichier GouvAgency.h) ----------------
#if ! defined ( GOUVAGENCY_H )
#define GOUVAGENCY_H

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "User.h"
using std::list;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    GouvAgency(const string &id, int points);

    // Destructor
    ~GouvAgency() override;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GouvAgency>

#endif // GOUVAGENCY_H