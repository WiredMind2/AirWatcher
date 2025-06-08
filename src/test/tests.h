/*************************************************************************
tests.h  -  Déclaration des fonctions de test pour valider les fonctionnalités de l'application AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

#pragma once
#include <iostream>

//---------- Interface des fonctions de test (fichier tests.h) -----------

//--------------------------------------------------- Interfaces utilisées
#if ! defined ( Tests_H )
#define Tests_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------
// Rôle des fonctions de test
// Permet de vérifier la robustesse et la fiabilité des modules de l'application.
//------------------------------------------------------------------------

void runTests();
void test_T11(int &testCount, int &testPassed, int &testFailed);
void test_T12(int &testCount, int &testPassed, int &testFailed);
void test_T13(int &testCount, int &testPassed, int &testFailed);

void test_T21(int &testCount, int &testPassed, int &testFailed);
void test_T22(int &testCount, int &testPassed, int &testFailed);
void test_T23(int &testCount, int &testPassed, int &testFailed);

void test_T31(int &testCount, int &testPassed, int &testFailed);
void test_T32(int &testCount, int &testPassed, int &testFailed);

//-------------------------------- Autres définitions dépendantes de <Tests>

#endif // Tests_H

