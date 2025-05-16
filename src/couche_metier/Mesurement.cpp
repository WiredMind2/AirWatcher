//
// Created by aaron on 16/05/2025.
//

#include "Mesurement.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Mesurement::Mesurement(time_t timestamp, double value, const string& sensorID, const string& attributeID)
    : timestamp(timestamp), value(value), sensorID(sensorID), attributeID(attributeID) {}

// Destructor
Mesurement::~Mesurement() {}