/*************************************************************************
                           Tests  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Tests> (fichier Tests.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "tests.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Tests::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Tests::runTests ( )
// Algorithme :
//
{
    // Initialisation des variables
    int testCount = 0;
    int testPassed = 0;
    int testFailed = 0;
    cout << "\033[1;32mdébut des Tests... \033[0m\n";

    // Test cases
    test_fct1(testCount, testPassed, testFailed);
    //...

    //results
    cout << "\033[1;32mTests terminés.\033[0m\n";
    cout << "\033[1;32mNombre total de Tests : " << testCount << "\033[0m\n";
    cout << "\033[1;32mNombre de Tests réussis : " << testPassed << "\033[0m\n";
    cout << "\033[1;31mNombre de Tests échoués : " << testFailed << "\033[0m\n";
    if (testFailed == 0) {
        cout << "\033[1;32mTous les Tests ont réussi.\033[0m\n";
    } else {
        cout << "\033[1;31m"<< testFailed << "ont échoué.\033[0m\n";
    }
}


//------------------------------------------------- Surcharge d'opérateurs
Tests & Tests::operator = ( const Tests & unTests )
// Algorithme :
//
{
    return *this; //to avoid warning
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Tests::Tests ( const Tests & unTests )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Tests>" << endl;
#endif
} //----- Fin de Tests (constructeur de copie)


Tests::Tests ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Tests>" << endl;
#endif
} //----- Fin de Tests


Tests::~Tests ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Tests>" << endl;
#endif
} //----- Fin de ~Tests


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Tests::test_fct1(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
// 
{
    testCount++;

    // Simulate a test case
    // Replace this with actual test logic
    bool result = true;

    if (result) {
        testPassed++;
    } else {
        testFailed++;
    }
}

