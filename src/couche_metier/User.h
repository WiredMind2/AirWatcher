//
// Created by aaron on 16/05/2025.
//

#ifndef SENSOR_H
#define SENSOR_H

class User
{
public:
    list<Sensor> getSensors();
    list<Sensor> compareSensor(Sensor sensor);
    double getGeoPoint(double latitude, double longitude);
    double getGeoZoneMean(double latitude, double longitude, double radius);
    // Constructor
    User(const string &id, int points)
        : userID(id), points(points) {}

    // Destructor
    ~User() {}

protected:
    String userID;
    int points;
};



#endif //SENSOR_H