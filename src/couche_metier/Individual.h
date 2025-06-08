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
    Individual(unsigned int id): User(id) {};

    // Destructor
    ~Individual() override {};

};

#endif // INDIVIDUAL_H