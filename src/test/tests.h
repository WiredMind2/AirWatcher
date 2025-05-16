/*************************************************************************
                           Tests  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Tests> (fichier Tests.h) ----------------
#if ! defined ( Tests_H )
#define Tests_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Tests>
//
//
//------------------------------------------------------------------------

class Tests
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void runTests ( );
    // Mode d'emploi :
    // Lance tous les Tests unitaires de la classe
    // Contrat :
    // 

//------------------------------------------------- Surcharge d'opérateurs
    Tests & operator = ( const Tests & unTests );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Tests ( const Tests & unTests );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Tests ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Tests ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

void test_T11(int &testCount, int &testPassed, int &testFailed);

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Tests>

#endif // Tests_H

