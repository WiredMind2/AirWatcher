/*************************************************************************
Administration.h  -  Déclaration des fonctions d'administration pour la gestion des utilisateurs, capteurs, et droits d'accès dans AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Administration> (fichier Administration.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Administration>
//
//
//------------------------------------------------------------------------

class Administration 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void consulter_capteurs_defaillants();
    void marquer_capteur_non_fiable();
    void marquer_user_malicieux();


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Administration>


