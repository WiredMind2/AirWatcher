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

using namespace std;

class CSVHandler {
public:

    void extractSensors();

    //setters
    void setCleaners(const unordered_map<unsigned int, Cleaner> &cleaners) {
        this->cleaners = cleaners;
    }
    void setGouvAgencies(const unordered_map<unsigned int, GouvAgency> &gouvAgencies) {
        this->gouvAgencies = gouvAgencies;
    }
    void setIndividuals(const unordered_map<unsigned int, Individual> &individuals) {
        this->individuals = individuals;
    }
    void setMesurements(const unordered_map<unsigned int, Mesurement> &mesurements) {
        this->mesurements = mesurements;
    }
    void setProviders(const unordered_map<unsigned int, Provider> &providers) {
        this->providers = providers;
    }
    void setSensors(const unordered_map<unsigned int, Sensor> &sensors) {
        this->sensors = sensors;
    }
    void setUsers(const unordered_map<unsigned int, User> &users) {
        this->users = users;
    }

    //getters
    unordered_map<unsigned int, Cleaner> getCleaners() const {
        return cleaners;
    }
    unordered_map<unsigned int, GouvAgency> getGouvAgencies() const {
        return gouvAgencies;
    }
    unordered_map<unsigned int, Individual> getIndividuals() const {
        return individuals;
    }
    unordered_map<unsigned int, Mesurement> getMesurements() const {
        return mesurements;
    }
    unordered_map<unsigned int, Provider> getProviders() const {
        return providers;
    }
    unordered_map<unsigned int, Sensor> getSensors() const {
        return sensors;
    }
    unordered_map<unsigned int, User> getUsers() const {
        return users;
    }



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
    unordered_map<unsigned int, GouvAgency> gouvAgencies;
    unordered_map<unsigned int, Individual> individuals;
    unordered_map<unsigned int, Mesurement> mesurements;
    unordered_map<unsigned int, Provider> providers;
    unordered_map<unsigned int, Sensor> sensors;
    unordered_map<unsigned int, User> users;
};

#endif //CSVHANDLER_H