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
#include "../processing.h"


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
    cout<<endl;

    // Test cases
    test_T11(testCount, testPassed, testFailed);
    test_T12(testCount, testPassed, testFailed);
    //...

    //results
    cout<<endl;
    cout << "\033[1;32mTests terminés.\033[0m\n";
    cout << "\033[1;32mNombre total de Tests : " << testCount << "\033[0m\n";
    cout << "\033[1;32mNombre de Tests réussis : " << testPassed << "\033[0m\n";
    cout << "\033[1;31mNombre de Tests échoués : " << testFailed << "\033[0m\n";
    if (testFailed == 0) {
        cout << "\033[1;32mTous les Tests ont réussi.\033[0m\n";
    } else {
        cout << "\033[1;31m"<< testFailed << " test(s) ont échoué.\033[0m\n";
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

void Tests::test_T11(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
// 
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;
    double expectedValue = 0.5;

    if (AirQualityProcessor.EstimationQualiteAirPos(lat, lon, k) == expectedValue) {
        cout << "\033[1;32mTest T11 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T11 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T12(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
// 
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;

    if (AirQualityProcessor.EstimationQualiteAirPos(lat, lon, k) == std::numeric_limits<double>::quiet_NaN()) {
        cout << "\033[1;32mTest T12 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T12 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T13(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;
    double expectedValue = 0.5;

    if (AirQualityProcessor.EstimationQualiteAirPos(lat, lon, k) == expectedValue) {
        cout << "\033[1;32mTest T11 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T11 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T21(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//  
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;
    double radius = 10;
    double step = 0.1;
    double expectedValue = 0.5;

    if (AirQualityProcessor.EstimationQualiteAirZone(lat, lon, radius, k, step) == expectedValue) {
        cout << "\033[1;32mTest T21 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T21 échoué.\033[0m\n";
        testFailed++;
    }

}

void Tests::test_T22(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;
    double radius = 10;
    double step = 0.1;

    if (AirQualityProcessor.EstimationQualiteAirZone(lat, lon, radius, k, step) == std::numeric_limits<double>::quiet_NaN()) {
        cout << "\033[1;32mTest T22 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T22 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T23(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    int k = 4;
    double lat = 44;
    double lon = 1.1;
    double radius = 10;
    double step = 0.1;
    double expectedValue = 0.5;

    if (AirQualityProcessor.EstimationQualiteAirZone(lat, lon, radius, k, step) == expectedValue) {
        cout << "\033[1;32mTest T21 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T21 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T31(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    double lat = 44;
    double lon = 1.1;
    int k = 4;
    double tolerance = 0.1;

    std::vector<const Mesurement *> detournes = AirQualityProcessor.TrouverCapteursDetournes(10.0, 0.5, k, tolerance);
    bool capteurTrouve = false;

    for (const auto &mesurement : detournes) {
        if (mesurement->GetSensor()->GetLatitude() == lat && mesurement->GetSensor()->GetLongitude() == lon) {
            capteurTrouve = true;
            break;
        }
    }

    if (!capteurTrouve) {
        cout << "\033[1;32mTest T31 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T31 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T32(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    double lat = 44;
    double lon = 1.1;
    int k = 4;
    double tolerance = 0.1;

    std::vector<const Mesurement *> detournes = AirQualityProcessor.TrouverCapteursDetournes(10.0, 0.5, k, tolerance);
    bool capteurTrouve = false;

    for (const auto &mesurement : detournes) {
        if (mesurement->GetSensor()->GetLatitude() == lat && mesurement->GetSensor()->GetLongitude() == lon) {
            capteurTrouve = true;
            break;
        }
    }

    if (capteurTrouve) {
        cout << "\033[1;32mTest T31 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T31 échoué.\033[0m\n";
        testFailed++;
    }
}

void Tests::test_T33(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    AirQualityProcessor AirQualityProcessor;
    testCount++;

    double lat = 44;
    double lon = 1.1;
    int k = 4;
    double tolerance = 0.1;

    std::vector<const Mesurement *> detournes = AirQualityProcessor.TrouverCapteursDetournes(10.0, 0.5, k, tolerance);
    bool capteurTrouve = false;

    for (const auto &mesurement : detournes) {
        if (mesurement->GetSensor()->GetLatitude() == lat && mesurement->GetSensor()->GetLongitude() == lon) {
            capteurTrouve = true;
            break;
        }
    }

    if (capteurTrouve) {
        cout << "\033[1;32mTest T31 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T31 échoué.\033[0m\n";
        testFailed++;
    }
}