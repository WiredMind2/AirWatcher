/*************************************************************************
tests.cpp  -  Fonctions de test pour valider les différentes fonctionnalités de l'application AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "tests.h"
#include "../couche_metier/processing.h"
#include "../couche_metier/Sensor.h"


//----------------------------------------------------------------- FONCTIONS DE TEST

//----------------------------------------------------- Méthodes publiques

//----------------------------- Algorithme principal de test
// Chaque fonction de test vérifie une fonctionnalité précise de l'application.
// Les résultats sont comparés aux valeurs attendues pour déterminer si les tests réussissent ou échouent.
// Les tests incluent des vérifications pour des entrées valides et des cas limites, assurant ainsi la robustesse de l'application.
void runTests ( )
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
    test_T13(testCount, testPassed, testFailed);

    test_T21(testCount, testPassed, testFailed);
    test_T22(testCount, testPassed, testFailed);
    test_T23(testCount, testPassed, testFailed);
    
    test_T31(testCount, testPassed, testFailed);
    test_T32(testCount, testPassed, testFailed);

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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void test_T11(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
// 
{
    testCount++;

    int k = 4;
    double lat = 45.8;
    double lon = 2.15;
    double expectedValue = 41.75;

    if (abs(AirQualityProcessor::EstimationQualiteAirPos(lat, lon, k, 0, -1) - expectedValue) < 0.01) {
        cout << "\033[1;32mTest T11 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T11 échoué.\033[0m\n";
        testFailed++;
    }
}

void test_T12(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
// 
{
    
    testCount++;

    int k = 4;
    double lat = 400;
    double lon = 400;

    if (isnan(AirQualityProcessor::EstimationQualiteAirPos(lat, lon, k, 0, -1))) {
        cout << "\033[1;32mTest T12 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T12 échoué.\033[0m\n";
        testFailed++;
    }
}

void test_T13(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    
    testCount++;

    int k = 4;
    double lat = -100;
    double lon = -100;
    double expectedValue = 70; 

    if (abs(AirQualityProcessor::EstimationQualiteAirPos(lat, lon, k, 0, -1) - expectedValue) < 0.01) {
        cout << "\033[1;32mTest T13 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T13 échoué.\033[0m\n";
        testFailed++;
    }
}

void test_T21(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//  
{
    
    testCount++;

    int k = 6;
    double lat = 45;
    double lon = 2.5;
    double radius = 10;
    double expectedValue = 54.2618;
    time_t start = 0; 
    time_t stop = -1; 

    if (abs(AirQualityProcessor::EstimationQualiteAirZone(lat, lon, radius, k, start, stop)- expectedValue) < 0.01) {
        cout << "\033[1;32mTest T21 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T21 échoué.\033[0m\n";
        testFailed++;
    }

}

void test_T22(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    
    testCount++;

    int k = 6;
    double lat = 400;
    double lon = 400;
    double radius = 2;
    time_t start = 0;
    time_t stop = -1;

    if (isnan(AirQualityProcessor::EstimationQualiteAirZone(lat, lon, radius, k, start, stop))) {
        cout << "\033[1;32mTest T22 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T22 échoué.\033[0m\n";
        testFailed++;
    }
}

void test_T23(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    
    testCount++;

    int k = 6;
    double lat = -100;
    double lon = -100;
    double radius = 0.1;
    double expectedValue = 70;
    time_t start = 0;
    time_t stop = -1;

    if (abs(AirQualityProcessor::EstimationQualiteAirZone(lat, lon, radius, k, start, stop) - expectedValue) < 0.1) {
        cout << "\033[1;32mTest T23 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T23 échoué.\033[0m\n";
        testFailed++;
    }
}

void test_T31(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    
    testCount++;

    double radius = 10;
    double seuil_limite = 10;
    unsigned int id_ref = 88; // ID du capteur de référence
    int k = 6;

    std::vector<const Sensor *> detournes = AirQualityProcessor::TrouverCapteursDetournes(radius, seuil_limite, k, 0, -1);
    bool capteurTrouve = false;

    for (const Sensor* capteur : detournes) {
        //cout << "Capteur ID: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude() << ", Longitude: " << capteur->GetLongitude() << endl;
        if (capteur->GetSensorID() == id_ref) {
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

void test_T32(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    double radius = 10;
    double seuil_limite = 10;
    unsigned int id_ref = 666;
    int k = 6;
    time_t start = 0;
    time_t stop = -1; 

    std::vector<const Sensor *> detournes = AirQualityProcessor::TrouverCapteursDetournes(radius, seuil_limite, k, start, stop);
    bool capteurTrouve = false;

    for (const Sensor* capteur : detournes) {
        // cout<< "Capteur ID: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude() << ", Longitude: " << capteur->GetLongitude() << endl;
        if (capteur->GetSensorID() == id_ref) {
            capteurTrouve = true;
            break;
        }
    }

    if (capteurTrouve) {
        cout << "\033[1;32mTest T32 réussi.\033[0m\n";
        testPassed++;
    } else {
        cout << "\033[1;31mTest T32 échoué.\033[0m\n";
        testFailed++;
    }
}
