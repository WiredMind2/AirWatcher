/*************************************************************************
 Individual.h  -  Déclare les structures et fonctions liées aux entités individuelles dans AirWatcher.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Individual> (fichier Individual.h) ----------------
#if ! defined ( INDIVIDUAL_H )
#define INDIVIDUAL_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

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