/*************************************************************************
                           presentation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <presentation> (fichier presentation.h) ----------------
#if ! defined ( presentation_H )
#define presentation_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <presentation>
//
//
//------------------------------------------------------------------------

class presentation
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
    presentation & operator = ( const presentation & unpresentation );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    presentation ( const presentation & unpresentation );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    presentation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~presentation ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <presentation>

#endif // presentation_H

