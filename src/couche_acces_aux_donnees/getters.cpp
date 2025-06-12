/*************************************************************************
getters.cpp  -  Fonctions d'accès aux données extraites pour l'application AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <CSVHandler> (fichier CSVHandler.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip> // For get_time

//------------------------------------------------------------------ Variables

unordered_map<unsigned int, Cleaner*> CSVHandler::cleaners;
unordered_map<unsigned int, Individual*> CSVHandler::individuals;
multimap<time_t, Measurement*> CSVHandler::measurements;
unordered_map<unsigned int, Provider*> CSVHandler::providers;
unordered_map<unsigned int, Sensor*> CSVHandler::sensors;
unordered_map<unsigned int, int> CSVHandler::filterdUsers;
unordered_map<unsigned int, Attribute*> CSVHandler::attributes;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CSVHandler::addUnreliable(const string &folder, const vector<unsigned int> &unreliableUserIds) {
    for (const auto& userId : unreliableUserIds) {
        auto it = individuals.find(userId);
        if (it != individuals.end()) {
            filterdUsers.emplace(userId, -1);
        } else {
            cout << "User with ID " << userId << " not found." << endl;
        }
    }
}

// Getters
Cleaner* CSVHandler::getCleaner(unsigned int id) {
    auto it = cleaners.find(id);
    if (it != cleaners.end()) {
        return it->second;
    }
    throw runtime_error("Cleaner not found");
}

Individual* CSVHandler::getIndividual(unsigned int id) {
    auto it = individuals.find(id);
    if (it != individuals.end()) {
        return it->second;
    }
    throw runtime_error("Individual not found");
}

Provider* CSVHandler::getProvider(unsigned int id) {
    auto it = providers.find(id);
    if (it != providers.end()) {
        return it->second;
    }
    throw runtime_error("Provider not found");
}

Sensor* CSVHandler::getSensor(unsigned int id) {
    auto it = sensors.find(id);
    if (it != sensors.end()) {
        if (it->second->GetSensorID() != id) {
            cout << "Warning: Sensor ID mismatch. Expected: " << id << ", Found: " << it->second->GetSensorID() << endl;
        }
        return it->second;
    }
    throw runtime_error("Sensor not found");
}

unsigned int CSVHandler::getFilterdUser(unsigned int id) {
    auto it = filterdUsers.find(id);
    if (it != filterdUsers.end()) {
        return it->first;
    }
    throw runtime_error("User not found");
}

vector<Measurement*> CSVHandler::getMeasurement(time_t start, time_t stop) {
    if(stop == -1){
        stop = time(nullptr);
    }

    if (start > stop) {
        cout << "Invalid time range." << start << " > " << stop << endl;
        return {};
    }

    auto itLow = measurements.lower_bound(start);
    auto itHigh = measurements.upper_bound(stop);

    if (itLow == measurements.end()) {
        cout << "No measurements found in the specified range: " << start << " to " << stop << endl;
        return {};
    }


    vector<Measurement*> results;
    for (auto it = itLow; it != itHigh; ++it) {
        results.push_back(it->second);
        // cout << "Measurement ID: " << it->second->GetSensor().GetSensorID() << ", Value: " << it->second->GetValue();
        // cout << ", Timestamp: " << it->second->GetTimestamp() << endl;
    }
    return results;
}

int CSVHandler::getAttributeID(const string &attribute)
{
    for (const auto &pair : attributes) {
        if (pair.second->GetAttributeID() == attribute) {
            return pair.first;
        }
    }
    throw runtime_error("Attribute not found: " + attribute);
}

Attribute* CSVHandler::getAttribute(unsigned int id) {
    auto it = attributes.find(id);
    if (it != attributes.end()) {
        return it->second;
    }
    throw runtime_error("Attribute not found: " + to_string(id));
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

