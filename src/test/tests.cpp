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
#include <map>
#include <iomanip>
#include <chrono>

//------------------------------------------------------ Include personnel
#include "tests.h"
#include "../couche_metier/processing.h"
#include "../couche_metier/Sensor.h"
#include "../couche_acces_aux_donnees/CSVHandler.h"

//----------------------------------------------------------------- FONCTIONS DE TEST

//----------------------------------------------------- Méthodes publiques

//----------------------------- Algorithme principal de test
// Chaque fonction de test vérifie une fonctionnalité précise de l'application.
// Les résultats sont comparés aux valeurs attendues pour déterminer si les tests réussissent ou échouent.
// Les tests incluent des vérifications pour des entrées valides et des cas limites, assurant ainsi la robustesse de l'application.
void runTests()
{
    // Initialisation des variables
    int testCount = 0;
    int testPassed = 0;
    int testFailed = 0;
    cout << "\033[1;32mdébut des Tests... \033[0m\n";
    cout << endl;

    // Test cases
    test_T11(testCount, testPassed, testFailed);
    test_T12(testCount, testPassed, testFailed);
    test_T13(testCount, testPassed, testFailed);

    test_T21(testCount, testPassed, testFailed);
    test_T22(testCount, testPassed, testFailed);
    test_T23(testCount, testPassed, testFailed);

    test_T31(testCount, testPassed, testFailed);
    test_T32(testCount, testPassed, testFailed);

    // results
    cout << endl;
    cout << "\033[1;32mTests terminés.\033[0m\n";
    cout << "\033[1;32mNombre total de Tests : " << testCount << "\033[0m\n";
    cout << "\033[1;32mNombre de Tests réussis : " << testPassed << "\033[0m\n";
    cout << "\033[1;31mNombre de Tests échoués : " << testFailed << "\033[0m\n";
    if (testFailed == 0)
    {
        cout << "\033[1;32mTous les Tests ont réussi.\033[0m\n";
    }
    else
    {
        cout << "\033[1;31m" << testFailed << " test(s) ont échoué.\033[0m\n";
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

// Helper function to map category name to its ID
unsigned int getCategoryIdByName(const string &name)
{
    return CSVHandler::getAttributeID(name);
}

// Helper function to compare expected and actual values for categories
bool compareCategoryResults(const map<string, double> &expectedValues, const unordered_map<unsigned int, double> &result, double tolerance = 0.01)
{
    bool allMatch = true;
    for (const auto &exp : expectedValues)
    {
        unsigned int cat = getCategoryIdByName(exp.first);
        double expected = exp.second;
        auto found = result.find(cat);
        if (found == result.end() || abs(found->second - expected) >= tolerance)
        {
            allMatch = false;
            cout << "Échec pour l'attribut " << exp.first << ": attendu " << expected
                 << ", obtenu " << (found != result.end() ? to_string(found->second) : "non trouvé") << "\n";
        }
    }
    return allMatch;
}

void test_T11(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double lat = 45.8;
    double lon = 2.15;

    map<string, double> expectedValues = {
        {"O3", 41.75},
        {"NO2", 38.36},
        {"SO2", 43.10},
        {"PM10", 46.18}};

    auto result = Processing::EstimationQualiteAirPos(lat, lon, 0, -1);

    bool allMatch = true;
    for (const auto &exp : expectedValues)
    {
        unsigned int catId = getCategoryIdByName(exp.first);
        auto found = result.find(catId);
        if (found == result.end() || abs(found->second - exp.second) >= 0.01)
        {
            allMatch = false;
            cout << "Échec pour l'attribut " << exp.first << ": attendu " << exp.second << ", obtenu "
                 << (found != result.end() ? to_string(found->second) : "non trouvé") << "\n";
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T11 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T11 échoué.\033[0m Durée : " << elapsed_time << " secondes.\n";
        testFailed++;
    }
}

void test_T12(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double lat = 400;
    double lon = 400;

    auto result = Processing::EstimationQualiteAirPos(lat, lon, 0, -1);

    bool allMatch = true;
    for (const auto &pair : result)
    {
        if (!isnan(pair.second))
        {
            allMatch = false;
            cout << "Échec pour l'attribut ID " << pair.first << ": valeur estimée non NaN.\n";
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T12 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T12 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T13(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double lat = -100;
    double lon = -100;
    map<string, double> expectedValues = {
        {"O3", 70},
        {"NO2", 0},
        {"SO2", 0},
        {"PM10", 0}};
    auto result = Processing::EstimationQualiteAirPos(lat, lon, 0, -1);
    bool allMatch = compareCategoryResults(expectedValues, result);

    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T13 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T13 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T21(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double lat = 45;
    double lon = 2.5;
    double radius = 10.0;
    map<string, double> expectedValues = {
        {"O3", 57.92},
        {"NO2", 56.64},
        {"SO2", 52.96},
        {"PM10", 52.57}};
    time_t start = 0;
    time_t stop = -1;
    auto result = Processing::EstimationQualiteAirZone(lat, lon, radius, start, stop);
    bool allMatch = compareCategoryResults(expectedValues, result);
    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T21 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T21 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T22(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double lat = 400;
    double lon = 400;
    double radius = 2;
    time_t start = 0;
    time_t stop = -1;

    auto result = Processing::EstimationQualiteAirZone(lat, lon, radius, start, stop);

    bool allMatch = true;
    for (const auto &exp : result)
    {
        if (!isnan(exp.second))
        {
            allMatch = false;
            cout << "Échec pour l'attribut ID " << exp.first << ": valeur estimée non NaN.\n";
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T22 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T22 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T23(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;
    auto start_time = chrono::high_resolution_clock::now();

    double lat = -100;
    double lon = -100;
    double radius = 1;
    map<string, double> expectedValues = {
        {"O3", 70}
    };
    time_t start = 0;
    time_t stop = -1;
    auto result = Processing::EstimationQualiteAirZone(lat, lon, radius, start, stop);
    bool allMatch = compareCategoryResults(expectedValues, result, 0.1);
    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count();
    if (allMatch)
    {
        cout << "\033[1;32mTest T23 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T23 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T31(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{

    testCount++;

    auto start_time = chrono::high_resolution_clock::now();

    double radius = 10;
    unordered_map<string, double> seuils_limite = {
        {"O3", 20.0},
        {"NO2", 20.0},
        {"SO2", 20.0},
        {"PM10", 20.0}
    };
    // Convert string keys to unsigned int keys
    unordered_map<unsigned int, double> seuils_limite_id;
    for (const auto& pair : seuils_limite) {
        seuils_limite_id[getCategoryIdByName(pair.first)] = pair.second;
    }
    unsigned int id_ref = 88; // ID du capteur de référence

    vector<const Sensor *> detournes = Processing::TrouverCapteursDetournes(radius, seuils_limite_id, 0, -1);
    bool capteurTrouve = false;

    for (const Sensor *capteur : detournes)
    {
        if (capteur->GetSensorID() == id_ref)
        {
            capteurTrouve = true;
            break;
        }
    }

    int iterationCount = 11; // Nombre d'itérations effectuees pour ce test
    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count() / iterationCount;
    if (!capteurTrouve)
    {
        cout << "\033[1;32mTest T31 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T31 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}

void test_T32(int &testCount, int &testPassed, int &testFailed)
// Algorithme :
//
{
    testCount++;
    auto start_time = chrono::high_resolution_clock::now();

    double radius = 10;
    unordered_map<string, double> seuils_limite = {
        {"O3", 20.0},
        {"NO2", 20.0},
        {"SO2", 20.0},
        {"PM10", 20.0}
    };
    unsigned int id_ref = 666;
    time_t start = 0;
    time_t stop = -1;

    unordered_map<unsigned int, double> seuils_limite_id;
    for (const auto &pair : seuils_limite)
    {
        seuils_limite_id[getCategoryIdByName(pair.first)] = pair.second;
    }

    vector<const Sensor *> detournes = Processing::TrouverCapteursDetournes(radius, seuils_limite_id, start, stop);
    bool capteurTrouve = false;

    for (const Sensor *capteur : detournes)
    {
        // cout<< "Capteur ID: " << capteur->GetSensorID() << ", Latitude: " << capteur->GetLatitude() << ", Longitude: " << capteur->GetLongitude() << endl;
        if (capteur->GetSensorID() == id_ref)
        {
            capteurTrouve = true;
            break;
        }
    }

    int iterationCount = 11; // Nombre d'itérations effectuees pour ce test
    auto end_time = chrono::high_resolution_clock::now();
    double elapsed_time = chrono::duration<double>(end_time - start_time).count() / iterationCount;
    if (capteurTrouve)
    {
        cout << "\033[1;32mTest T32 réussi.\033[0m (" << elapsed_time << " sec)\n";
        testPassed++;
    }
    else
    {
        cout << "\033[1;31mTest T32 échoué.\033[0m (" << elapsed_time << " sec)\n";
        testFailed++;
    }
}
