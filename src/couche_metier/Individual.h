/*************************************************************************
                           Individual  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Individual> (fichier Individual.h) ----------------
#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Individual>
//
// Représente un utilisateur individuel.
//------------------------------------------------------------------------

class Individual : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Constructor
    Individual(const string &id, int points);

    // Destructor
    ~Individual() override;
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Individual>

#endif // INDIVIDUAL_H