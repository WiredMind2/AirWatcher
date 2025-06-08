/*************************************************************************
 presentation.h  -  Déclare les fonctions de gestion de l'affichage, de l'interface utilisateur et de l'interaction avec l'utilisateur dans AirWatcher.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface des fonctions d'affichage (fichier presentation.h) -----------

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------
// Rôle des fonctions d'affichage
// Permet de gérer l'affichage et l'interface utilisateur de l'application.
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
