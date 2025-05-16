//
// Created by aaron on 16/05/2025.
//

#ifndef MESUREMENT_H
#define MESUREMENT_H

#include "Attribute.h"
#include "Sensor.h"

using namespace std;


class Mesurement {
public:
    // Constructor
    Mesurement(time_t timestamp, double value, const string& sensorID, const string& attributeID)
        : timestamp(timestamp), value(value), sensorID(sensorID), attributeID(attributeID) {}

    // Destructor
    ~Mesurement() {}
protected:
    time_t timestamp;
    double value;
    string sensorID;
    string attributeID;

    Sensor sensor;
    Attribute attribute;
};



#endif //MESUREMENT_H
