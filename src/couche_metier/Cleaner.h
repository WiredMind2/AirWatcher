/*************************************************************************
 AirWatcher  -  Ce document présente les exigences détaillées pour l'application AirWatcher, dédiée à l'analyse et à la gestion des données de qualité de l'air recueillies par des capteurs répartis sur un large territoire. L'application soutient l’agence gouvernementale dans ses actions de protection de l'environnement grâce à des fonctionnalités robustes et fiables de surveillance, d'analyse et de rapport.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

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
    void start();
    void stop();

    Cleaner(const unsigned int cleanerID, double latitude, double longitude, time_t timeStart, time_t timeStop, const unsigned int providerID): 
        cleanerID(cleanerID), latitude(latitude), longitude(longitude), timeStart(timeStart), timeStop(timeStop), providerID(providerID) {};
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

#endif // CLEANER_H