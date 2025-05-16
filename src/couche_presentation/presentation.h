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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Menu_principal ( );
    // Mode d'emploi :
    // Affiche le menu principal de l'application
    // Contrat :
    //

    void Menu_analyse ( );
    // Mode d'emploi :
    // Affiche le menu d'analyse de l'application
    // Contrat :
    //

    void Menu_statistiques ( );
    // Mode d'emploi :
    // Affiche le menu de statistiques de l'application
    // Contrat :
    //

    void Menu_points_utilisateurs ( );
    // Mode d'emploi :
    // Affiche le menu de points utilisateurs de l'application
    // Contrat :
    //

    void Menu_administration ( );
    // Mode d'emploi :
    // Affiche le menu d'administration de l'application
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Presentation & operator = ( const Presentation & unPresentation );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Presentation ( const Presentation & unPresentation );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Presentation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Presentation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Presentation>

#endif // Presentation_H

