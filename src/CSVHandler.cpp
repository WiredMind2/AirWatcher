//
// Created by aaron on 16/05/2025.
//

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void CSVHandler::extractSensors() {
    ifstream file(filePath);
    string line;

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
            this->sensors.emplace(id, sensor);
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

vector<Mesurement*> CSVHandler::getMeasurement(time_t start, time_t stop) const {
    auto itLow = mesurements.lower_bound(start);
    auto itHigh = mesurements.upper_bound(stop);

    vector<Mesurement*> results;
    for (auto it = itLow; it != itHigh; ++it) {
        results.push_back(it->second);
    }
    return results;
}