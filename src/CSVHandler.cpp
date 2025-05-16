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