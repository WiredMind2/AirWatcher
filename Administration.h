/*************************************************************************
                           Administration  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Administration> (fichier Administration.h) ----------------
#if ! defined ( Administration_H )
#define Administration_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

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


//------------------------------------------------- Surcharge d'opérateurs
    Administration & operator = ( const Administration & unAdministration );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Administration ( const Administration & unAdministration );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Administration ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Administration ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées


//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Administration>

#endif // Administration_H

