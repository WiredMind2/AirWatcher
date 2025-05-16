//
// Created by aaron on 16/05/2025.
//

#pragma once
#include <string>
#include <list>

using namespace std;

class Sensor {
public:
    // Constructor
    Sensor() {}
    Sensor(const string &id, double lat, double lon, const string &userID)
        : sensorID(id), latitude(lat), longitude(lon) {}

    // Destructor
    ~Sensor() {}

protected:
    string sensorID;
    double latitude;
    double longitude;
};
