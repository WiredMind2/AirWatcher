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

    Cleaner(const unsigned int &cleanerID, double latitude, double longitude, const unsigned int &providerID);
    virtual ~Cleaner();

    unsigned int GetCleanerID() const { return cleanerID; }
    double GetLatitude() const { return latitude; }
    double GetLongitude() const { return longitude; }
    time_t GetTimeStart() const { return timeStart; }
    time_t GetTimeStop() const { return timeStop; }
    unsigned int GetProviderID() const { return providerID; }
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unsigned int cleanerID;
    double latitude;
    double longitude;
    time_t timeStart;
    time_t timeStop;
    unsigned int providerID;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // CLEANER_H