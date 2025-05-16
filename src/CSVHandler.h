//
// Created by aaron on 16/05/2025.
//

#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <iostream>

using namespace std;
#include <unordered_map>
#include <string>
#include "couche_metier/Cleaner.h"
#include "couche_metier/GouvAgency.h"
#include "couche_metier/Individual.h"
#include "couche_metier/Mesurement.h"
#include "couche_metier/Provider.h"
#include "couche_metier/Sensor.h"
#include "couche_metier/User.h"
#include <map>

using namespace std;

class CSVHandler {
public:

    void extractSensors();

    //getters
    Cleaner getCleaner(unsigned int id) const;
    Individual getIndividual(unsigned int id) const;
    Provider getProvider(unsigned int id) const;
    Sensor getSensor(unsigned int id) const;
    User getUser(unsigned int id) const;

    vector<Mesurement*> getMeasurement(time_t start, time_t stop) const;

    // Constructor
    CSVHandler(const string &filePath)
        : filePath(filePath) {}

    // Destructor
    ~CSVHandler() {}

private:
    // Links objects together using ids
    void linkAllObjects();
    void linkUsers();

protected:
    string filePath;

    unordered_map<unsigned int, Cleaner> cleaners;
    unordered_map<unsigned int, Individual> individuals;
    multimap<time_t, Mesurement*> mesurements;
    unordered_map<unsigned int, Provider> providers;
    unordered_map<unsigned int, Sensor> sensors;
    unordered_map<unsigned int, User> users;
};

#endif //CSVHANDLER_H