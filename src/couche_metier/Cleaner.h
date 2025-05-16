/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par aaron
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
// Représente un dispositif de nettoyage avec position et fournisseur.
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void start();
    void stop();

    Cleaner(const string &cleanerID, double latitude, double longitude, const string &providerID);
    virtual ~Cleaner();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string cleanerID;
    double latitude;
    double longitude;
    time_t timeStart;
    time_t timeStop;
    string providerID;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H