//
// Created by aaron on 16/05/2025.
//

#include "User.h"
#include "Sensor.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;


vector<Sensor> User::getSensors() {
    return sensors;
}

vector<Sensor> User::compareSensor(Sensor sensor) {
    vector<Sensor> result;
    for (Sensor s : sensors) {
        if (s.getID() == sensor.getID()) {
            result.push_back(s);
        }
    }
    return result;
}

double User::getGeoPoint(double latitude, double longitude) {
    return 0.0;
}

double User::getGeoZoneMean(double latitude, double longitude, double radius) {
    return 0.0;
}

// Constructor
User::User(const string &id, int points)
    : userID(id), points(points) {}

// Destructor
User::~User() {}