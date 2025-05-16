//
// Created by aaron on 16/05/2025.
//

#pragma once
#include <iostream>

#include <string>
#include <vector>

class User
{
public:
    // vector<Sensor> getSensors();
    // vector<Sensor> compareSensor(Sensor sensor);
    double getGeoPoint(double latitude, double longitude);
    double getGeoZoneMean(double latitude, double longitude, double radius);
    // Constructor
    User(){}

    User(const string &id, int points)
        : userID(id), points(points) {}

    // Destructor
    ~User() {}

protected:
    string userID;
    int points;
};