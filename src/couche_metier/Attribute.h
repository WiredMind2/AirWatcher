//
// Created by aaron on 16/05/2025.
//

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

class Attribute {
public:
    // Constructor
    Attribute(int id, const string &unit, const string &description)
        : attributeID(id), unit(unit), description(description) {}

    // Destructor
    ~Attribute() {}
protected:
    int attributeID;
    string unit;
    string description;
};



#endif //ATTRIBUTE_H
