/*************************************************************************
                           PointsUtilisateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PointsUtilisateurs> (fichier PointsUtilisateurs.h) ----------------
#if ! defined ( PointsUtilisateurs_H )
#define PointsUtilisateurs_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PointsUtilisateurs>
//
//
//------------------------------------------------------------------------

class PointsUtilisateurs 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    PointsUtilisateurs & operator = ( const PointsUtilisateurs & unPointsUtilisateurs );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PointsUtilisateurs ( const PointsUtilisateurs & unPointsUtilisateurs );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PointsUtilisateurs ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PointsUtilisateurs ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <PointsUtilisateurs>

#endif // PointsUtilisateurs_H

