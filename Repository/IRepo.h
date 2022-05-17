//
// Created by alext on 03/05/2022.
//

#ifndef LAB_9_10_IREPO_H
#define LAB_9_10_IREPO_H

#include <iostream>
#include <vector>
#include "../Domain/Ticket/Ticket.h"

using namespace std;

template <class T>
class IRepo{
public:

    virtual void create(T) = 0;

    virtual vector<T> getAll() = 0;

    virtual void update(unsigned int, T) = 0;

    virtual void deleteEntity(unsigned int) = 0;
};

#endif //LAB_9_10_IREPO_H
