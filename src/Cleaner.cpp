//
// Created by aaron on 16/05/2025.
//

#include "Cleaner.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void Cleaner::start() {
    timeStart = time(nullptr);
    cout << "Cleaner started at: " << ctime(&timeStart) << endl;
}

void Cleaner::stop() {
    timeStop = time(nullptr);
    cout << "Cleaner stopped at: " << ctime(&timeStop) << endl;
}

// Constructor
Cleaner::Cleaner(const string &cleanerID, double latitude, double longitude, const string &providerID)
        : cleanerID(cleanerID), latitude(latitude), longitude(longitude), providerID(providerID) {
    this->timeStart = nullptr;
    this->timeStop = nullptr;
    cout << "Cleaner created with ID: " << cleanerID << endl;
}

// Destructor
Cleaner::~Cleaner() {
    cout << "Cleaner with ID: " << cleanerID << " destroyed." << endl;
}