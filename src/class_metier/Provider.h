//
// Created by aaron on 16/05/2025.
//

#ifndef PROVIDER_H
#define PROVIDER_H

#include "User.h"
#include "Cleaner.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Provider : public User{
public:
    vector<Cleaner> getCleaners();


    // Constructor
    Provider(const std::string &id)
        : User(), providerID(id) {}

    // Destructor
    ~Provider() {}

protected:
    string providerID;
};



#endif //PROVIDER_H
