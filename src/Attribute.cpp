//
// Created by aaron on 16/05/2025.
//

#include "Attribute.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Attribute::Attribute(int id, const string &unit, const string &description)
    : attributeID(id), unit(unit), description(description) {}

//Destructor
Attribute::~Attribute() {}