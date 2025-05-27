/*************************************************************************
                           Presentation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Presentation> (fichier Presentation.h) ----------------
#if ! defined ( Presentation_H )
#define Presentation_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Presentation>
//
//
//------------------------------------------------------------------------

class Presentation
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Menu_principal ( );
    // Mode d'emploi :
    // Affiche le menu principal.
    // Contrat :
    // Aucun.

    void Menu_analyse ( );
    // Mode d'emploi :
    // Affiche le menu d'analyse.
    // Contrat :
    // Aucun.

    void Menu_statistiques ( );
    // Mode d'emploi :
    // Affiche le menu de statistiques.
    // Contrat :
    // Aucun.

    void Menu_points_utilisateurs ( );
    // Mode d'emploi :
    // Affiche le menu des points utilisateurs.
    // Contrat :
    // Aucun.

    void Menu_administration ( );
    // Mode d'emploi :
    // Affiche le menu d'administration.
    // Contrat :
    // Aucun.

//-------------------------------------------- Constructeurs - destructeur
    Presentation ( const Presentation & unPresentation );
    // Mode d'emploi (constructeur de copie) :
    // Copie un objet Presentation.
    // Contrat :
    // Aucun.

    Presentation ( );
    // Mode d'emploi :
    // Initialise un objet Presentation.
    // Contrat :
    // Aucun.

    virtual ~Presentation ( );
    // Mode d'emploi :
    // Détruit un objet Presentation.
    // Contrat :
    // Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Presentation>

#endif // Presentation_H
