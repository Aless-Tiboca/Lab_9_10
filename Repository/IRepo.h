//
// Created by alext on 03/05/2022.
//

#ifndef LAB_9_10_IREPO_H
#define LAB_9_10_IREPO_H

#include <iostream>
#include <vector>
#include "../Domain/Ticket.h"

using namespace std;

class IRepo{
public:

    virtual void create(Ticket) = 0;

    virtual vector<Ticket> getAll() = 0;

    virtual void update(string, Ticket) = 0;

    virtual void deleteTicket(string) = 0;
};

#endif //LAB_9_10_IREPO_H
