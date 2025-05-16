//
// Created by aaron on 16/05/2025.
//

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


unordered_map<unsigned int, Cleaner> CSVHandler::cleaners;
unordered_map<unsigned int, Individual> CSVHandler::individuals;
multimap<time_t, Measurement*> CSVHandler::measurements;
unordered_map<unsigned int, Provider> CSVHandler::providers;
unordered_map<unsigned int, Sensor> CSVHandler::sensors;
unordered_map<unsigned int, User> CSVHandler::users;

void CSVHandler::extractAll(const string &folder) {
    extractSensors(folder);
    extractMeasurements(folder);
}

void CSVHandler::extractSensors(const string &folder) {
    ifstream file(folder + "/sensors.csv");
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
            sensors.emplace(id, sensor);
            cout << "Sensor ID: " << id << ", Latitude: " << latitude << ", Longitude: " << longitude << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void CSVHandler::extractMeasurements(const string &folder) {
    ifstream file(folder + "/measurements.csv");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string timestampStr, valueStr, sensorIDStr, attributeIDStr;

            getline(ss, timestampStr, ';');
            getline(ss, sensorIDStr, ';');
            getline(ss, attributeIDStr, ';');
            getline(ss, valueStr, ';');

            sensorIDStr = sensorIDStr.substr(6);

            time_t timestamp = stoi(timestampStr);
            double value = stod(valueStr);
            unsigned int sensorID = stoi(sensorIDStr);
            string attributeID = attributeIDStr;

            Measurement* measurement = new Measurement(timestamp, value, sensorID, attributeID);
            measurements.emplace(timestamp, measurement);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

// Getters
Cleaner CSVHandler::getCleaner(unsigned int id) {
    auto it = cleaners.find(id);
    if (it != cleaners.end()) {
        return it->second;
    }
    throw std::runtime_error("Cleaner not found");
}
Individual CSVHandler::getIndividual(unsigned int id) {
    auto it = individuals.find(id);
    if (it != individuals.end()) {
        return it->second;
    }
    throw std::runtime_error("Individual not found");
}
Provider CSVHandler::getProvider(unsigned int id) {
    auto it = providers.find(id);
    if (it != providers.end()) {
        return it->second;
    }
    throw std::runtime_error("Provider not found");
}
Sensor CSVHandler::getSensor(unsigned int id) {
    auto it = sensors.find(id);
    if (it != sensors.end()) {
        return it->second;
    }
    throw std::runtime_error("Sensor not found");
}
User CSVHandler::getUser(unsigned int id) {
    auto it = users.find(id);
    if (it != users.end()) {
        return it->second;
    }
    throw std::runtime_error("User not found");
}

vector<Measurement*> CSVHandler::getMeasurement(time_t start, time_t stop) {
    auto itLow = measurements.lower_bound(start);
    auto itHigh = measurements.upper_bound(stop);

    vector<Measurement*> results;
    for (auto it = itLow; it != itHigh; ++it) {
        results.push_back(it->second);
        cout << "Measurement ID: " << it->second->GetSensor()->GetSensorID() << ", Value: " << it->second->GetValue();
        cout << ", Timestamp: " << it->second->GetTimestamp() << endl;
    }
    return results;
}