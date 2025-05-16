//
// Created by aaron on 16/05/2025.
//

#ifndef GOUVAGENCY_H
#define GOUVAGENCY_H

#include "User.h"

class GouvAgency : public User
{
public:
    void classifyUnreliable(User &user);
    void classifyReliable(User &user);
    list<User> getUsers();
    list<User> findUnreliable();
};

#endif //GOUVAGENCY_H
