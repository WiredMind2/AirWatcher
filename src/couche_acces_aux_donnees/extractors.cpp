/*************************************************************************
extractors.cpp  -  Fonctions d'extraction de données depuis les fichiers sources pour l'application AirWatcher.
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
time_t stringToTimeT(const string& dateTimeStr) {
    tm tm = {};
    istringstream ss(dateTimeStr);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw runtime_error("Failed to parse date/time string");
    }
    return mktime(&tm);
}

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void CSVHandler::extractAll(const string &folder) {
    extractAttributes(folder);
    extractCleaners(folder);
    extractSensors(folder);
    extractMeasurements(folder);
    extractIndividuals(folder);
}

void CSVHandler::extractCleaners(const string &folder) {
    ifstream file(folder + "/cleaners.csv");
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

            // cout << "ID: " << idStr << ", Latitude: " << latitudeStr << ", Longitude: " << longitudeStr << ", Time Start: " << timeStartStr << ", Time Stop: " << timeStopStr << endl;
            idStr = idStr.substr(7);

            unsigned int id = stoi(idStr);
            double latitude = stod(latitudeStr);
            double longitude = stod(longitudeStr);
            time_t timeStart = stringToTimeT(timeStartStr);
            time_t timeStop = stringToTimeT(timeStopStr);

            Cleaner* cleaner = new Cleaner(id, latitude, longitude, timeStart, timeStop, -1);
            cleaners.emplace(id, cleaner);
        }
        file.close();
    } else {
        cout << "Unable to open file " << folder + "/cleaners.csv" << endl;
    }
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

            Sensor* sensor = new Sensor(id, latitude, longitude, -1);
            sensors.emplace(id, sensor);
            // cout << "Sensor ID: " << id << ", Latitude: " << latitude << ", Longitude: " << longitude << endl;
        }
        file.close();

        // cout << "Sensors loaded:" << endl;
        // for (const auto& pair : sensors) {
        //     Sensor* sensor = pair.second;
        //     cout << "Key: " << pair.first
        //          << ", ID: " << sensor->GetSensorID()
        //          << ", Latitude: " << sensor->GetLatitude()
        //          << ", Longitude: " << sensor->GetLongitude()
        //          << ", UserID: " << sensor->GetUserID()
        //          << endl;
        // }

    } else {
        cout << "Unable to open file " << folder + "/sensors.csv" << endl;
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

            // Parse timestamp in format "YYYY-MM-DD HH:MM:SS"
            tm tm = {};
            istringstream ssTime(timestampStr);
            ssTime >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
            time_t timestamp;
            if (ssTime.fail()) {
                cout << "Invalid timestamp format: " << timestampStr << endl;
                continue;
            } else {
                timestamp = mktime(&tm);
            }

            double value = stod(valueStr);
            sensorIDStr = sensorIDStr.substr(6);
            unsigned int sensorID = stoi(sensorIDStr);
            
            // Vérifier que le sensor existe en mémoire
            auto it = sensors.find(sensorID);
            if (it == sensors.end()) {
                //cout << "Sensor with ID " << sensorID << " not found. Skipping measurement." << endl;
                continue;
            }
            
            string attributeID = attributeIDStr;

            // cout << "Measurement Timestamp: " << put_time(&tm, "%Y-%m-%d %H:%M:%S") 
            //      << ", Value: " << value 
            //      << ", Sensor ID: " << sensorID 
            //      << ", Attribute ID: " << attributeID << endl;

            Measurement* measurement = new Measurement(timestamp, value, sensorID, attributeID);
            measurements.emplace(timestamp, measurement);
        }
        file.close();
    } else {
        cout << "Unable to open file " << folder + "/measurements.csv" << endl;
    }
}

void CSVHandler::extractIndividuals(const string &folder){
   ifstream file(folder + "/users.csv");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string userStr, sensorStr;

            getline(ss, userStr, ';');
            unsigned int userid = stoi(userStr.substr(4));
            getline(ss, sensorStr, ';');
            unsigned int sensorid = stoi(sensorStr.substr(6));

            Individual* individual = new Individual(userid);
            individuals.emplace(userid, individual);

            auto it = sensors.find(sensorid);
            if (it != sensors.end()) {
                Sensor* sensor = it->second;
                sensor->SetUserID(userid);
            } else {
                cout << "Sensor with ID " << sensorid << " not found." << endl;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file " << folder + "/users.csv" << endl;
    }
}

void CSVHandler::extractAttributes(const string &folder) {
    ifstream file(folder + "/attributes.csv");
    string line;

    if (file.is_open()) {
        int attributeID = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, nameStr, descStr;

            getline(ss, idStr, ';');
            getline(ss, nameStr, ';');
            getline(ss, descStr, ';');

            attributes.emplace(attributeID, new Attribute(attributeID, idStr, nameStr, descStr));
            attributeID++;
        }
        file.close();
    } else {
        cout << "Unable to open file " << folder + "/attributes.csv" << endl;
    }
}