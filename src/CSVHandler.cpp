//
// Created by aaron on 16/05/2025.
//

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void CSVHandler::extractSensors() {
    ifstream file(filePath);
    string line;

    unordered_map<unsigned int, Sensor> sensors;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, latitudeStr, longitudeStr;

            getline(ss, idStr, ';');
            getline(ss, latitudeStr, ';');
            getline(ss, longitudeStr, ';');

            idStr = idStr.substr(6);

            unsigned int id = stoi(idStr);
            double latitude = stod(latitudeStr);
            double longitude = stod(longitudeStr);

            Sensor sensor(id, latitude, longitude, -1);
            sensors.emplace(id, sensor);
        }
        this->sensors = sensors;
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void CSVHandler::extractUsers(){
   ifstream file(filePath);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string user, sensor;

            getline(ss, user, ';');
            unsigned int userid = static_cast<unsigned int>(stoi(user.substr(4)));
            getline(ss, sensor, ';');
            unsigned int sensorid = static_cast<unsigned int>(stoi(sensor.substr(6)));

            auto it = sensors.find(sensorid);
            if (it != sensors.end()) {
                Sensor &sensor = it->second;
                sensor.SetUserID(userid);
            } else {
                cout << "Sensor with ID " << sensorid << " not found." << endl;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

// Getters
Cleaner CSVHandler::getCleaner(unsigned int id) const {
    auto it = cleaners.find(id);
    if (it != cleaners.end()) {
        return it->second;
    }
    throw std::runtime_error("Cleaner not found");
}
Individual CSVHandler::getIndividual(unsigned int id) const {
    auto it = individuals.find(id);
    if (it != individuals.end()) {
        return it->second;
    }
    throw std::runtime_error("Individual not found");
}
Provider CSVHandler::getProvider(unsigned int id) const {
    auto it = providers.find(id);
    if (it != providers.end()) {
        return it->second;
    }
    throw std::runtime_error("Provider not found");
}
Sensor CSVHandler::getSensor(unsigned int id) const {
    auto it = sensors.find(id);
    if (it != sensors.end()) {
        return it->second;
    }
    throw std::runtime_error("Sensor not found");
}
User CSVHandler::getUser(unsigned int id) const {
    auto it = users.find(id);
    if (it != users.end()) {
        return it->second;
    }
    throw std::runtime_error("User not found");
}

