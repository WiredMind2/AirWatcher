/*************************************************************************
                           analyse  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <analyse> (fichier analyse.h) ----------------
#if ! defined ( analyse_H )
#define analyse_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <analyse>
//
//
//------------------------------------------------------------------------

class analyse
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
    analyse & operator = ( const analyse & unanalyse );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    analyse ( const analyse & unanalyse );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <analyse>

#endif // analyse_H

