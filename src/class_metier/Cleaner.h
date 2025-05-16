//
// Created by aaron on 16/05/2025.
//

#ifndef CLEANER_H
#define CLEANER_H


using namespace std;

class Cleaner {
public:
    void start();
    void stop();

    // Constructor
    Cleaner(const string &cleanerID, double latitude, double longitude,const string &providerID)
        : cleanerID(cleanerID), latitude(latitude), longitude(longitude), providerID(providerID) {}

    // Destructor
    ~Cleaner() {}
protected:
    string cleanerID;
    double latitude;
    double longitude;
    time_t timeStart;
    time_t timeStop;
    string providerID;
    Cleaner *cleaner;
};



#endif //CLEANER_H
