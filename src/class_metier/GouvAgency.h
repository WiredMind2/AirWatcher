//
// Created by aaron on 16/05/2025.
//

#ifndef GOUVAGENCY_H
#define GOUVAGENCY_H

#include "User.h"
#include "Provider.h"
#include <iostream>
#include <string>
#include <vector>

class GouvAgency : public User
{
public:
    void classifyUnreliable(User &user);
    void classifyReliable(User &user);
    vector<User> getUsers();
    vector<User> findUnreliable();
};

#endif //GOUVAGENCY_H
