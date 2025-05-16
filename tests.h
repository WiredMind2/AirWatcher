/*************************************************************************
                           tests  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <tests> (fichier tests.h) ----------------
#if ! defined ( tests_H )
#define tests_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <tests>
//
//
//------------------------------------------------------------------------

class tests
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool runTests ( );
    // Mode d'emploi :
    // Lance tous les tests unitaires de la classe
    // Contrat :
    // 

//------------------------------------------------- Surcharge d'opérateurs
    tests & operator = ( const tests & untests );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    tests ( const tests & untests );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    tests ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~tests ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

void test_fct1(int &testCount, int &testPassed, int &testFailed);

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <tests>

#endif // tests_H

