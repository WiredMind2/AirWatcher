/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

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

#endif // PROVIDER_H