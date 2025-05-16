//
// Created by aaron on 16/05/2025.
//

#include "Sensor.h"
#include "Mesurement.h"
#include <iostream>
#include <string>

vector<Mesurement> Sensor::getData() {
    return data;
}

// Constructor
Sensor::Sensor(const string &id, double lat, double lon, const string &userID)
    : sensorID(id), latitude(lat), longitude(lon), userID(userID) {}

// Destructor
Sensor::~Sensor() {}