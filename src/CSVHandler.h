//
// Created by aaron on 16/05/2025.
//

#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <iostream>

using namespace std;


class CSVHandler {
public:

    void extractSensors();


    // Constructor
    CSVHandler(const string &filePath)
        : filePath(filePath) {}

    // Destructor
    ~CSVHandler() {}
protected:
    string filePath;
};



#endif //CSVHANDLER_H
