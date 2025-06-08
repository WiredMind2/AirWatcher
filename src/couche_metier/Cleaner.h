/*************************************************************************
Cleaner.h  -  Déclaration de la classe Cleaner représentant un dispositif de nettoyage avec position et fournisseur.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
using std::string;

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
    Cleaner(const unsigned int cleanerID, double latitude, double longitude, time_t timeStart, time_t timeStop, const unsigned int providerID)
        : cleanerID(cleanerID), latitude(latitude), longitude(longitude), providerID(providerID), timeStart(timeStart), timeStop(timeStop) {};
    virtual ~Cleaner() {};

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
    unsigned int providerID;
    time_t timeStart;
    time_t timeStop;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>