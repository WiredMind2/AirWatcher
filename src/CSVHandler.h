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
#include "couche_metier/Measurement.h"
#include "couche_metier/Provider.h"
#include "couche_metier/Sensor.h"
#include "couche_metier/User.h"
#include <map>
#include <vector>

using namespace std;

class CSVHandler {
public:

    static void extractAll(const string &folder);
    static void extractSensors(const string &folder);
    static void extractMeasurements(const string &folder);

    //getters
    static Cleaner getCleaner(unsigned int id);
    static Individual getIndividual(unsigned int id);
    static Provider getProvider(unsigned int id);
    static Sensor getSensor(unsigned int id);
    static User getUser(unsigned int id);

    static vector<Measurement*> getMeasurement(time_t start, time_t stop);

private:
    // Links objects together using ids
    void linkAllObjects();
    void linkUsers();

protected:
    static unordered_map<unsigned int, Cleaner> cleaners;
    static unordered_map<unsigned int, Individual> individuals;
    static multimap<time_t, Measurement*> measurements;
    static unordered_map<unsigned int, Provider> providers;
    static unordered_map<unsigned int, Sensor> sensors;
    static unordered_map<unsigned int, User> users;
};

#endif //CSVHANDLER_H