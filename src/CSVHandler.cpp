//
// Created by aaron on 16/05/2025.
//

#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

time_t stringToTimeT(const string& dateTimeStr) {
    tm tm = {};
    istringstream ss(dateTimeStr);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw runtime_error("Failed to parse date/time string");
    }
    return mktime(&tm);
}

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

void CSVHandler::extractCleaners() {
    ifstream file(filePath);
    string line;

    //unordered_map<unsigned int, Cleaner> cleaners;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, latitudeStr, longitudeStr, timeStartStr, timeStopStr;

            getline(ss, idStr, ';');
            getline(ss, latitudeStr, ';');
            getline(ss, longitudeStr, ';');
            getline(ss, timeStartStr, ';');
            getline(ss, timeStopStr, ';');

            cout << "ID: " << idStr << ", Latitude: " << latitudeStr << ", Longitude: " << longitudeStr << ", Time Start: " << timeStartStr << ", Time Stop: " << timeStopStr << endl;
            idStr = idStr.substr(7);

            unsigned int id = stoi(idStr);
            double latitude = stod(latitudeStr);
            double longitude = stod(longitudeStr);
            time_t timeStart = stringToTimeT(timeStartStr);
            time_t timeStop = stringToTimeT(timeStopStr);

            Cleaner cleaner(id, latitude, longitude, timeStart, timeStop, -1);
            cleaners.emplace(id, cleaner);
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