/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
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

//------------------------------------------------------------- Constantes

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

    Provider(const string &id);
    virtual ~Provider();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string providerID;
};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // PROVIDER_H