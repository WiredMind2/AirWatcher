//
// Created by aaron on 16/05/2025.
//

#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    list<Mesurement> getData();

    // Constructor
    Sensor(const string &id, double lat, double lon, const string &userID)
        : sensorID(id), latitude(lat), longitude(lon), userID(userID) {}

    // Destructor
    ~Sensor() {}

protected:
    String sensorID;
    double latitude;
    double longitude;
    string userID;
};



#endif //SENSOR_H
