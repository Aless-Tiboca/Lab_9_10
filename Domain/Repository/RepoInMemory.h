//
// Created by alext on 21/04/2022.
//

#ifndef LAB_9_10_REPOINMEMORY_H
#define LAB_9_10_REPOINMEMORY_H

#include <bits/stdc++.h>
#include "../Domain/Ticket/Ticket.h"
#include "IRepo.h"
#include <vector>

template <class T> class RepoInMemory: public IRepo<T>{
private:
    vector<T> entities;
public:
    /**
     * Constructor
     */
    RepoInMemory();

    /**
     * Adauga o entitate in repository
     * @param e entitatea de adaugat
     */
    void create(T t) override;

    /**
     * Returneaza toate entitatile intr-un vector
     * @return un vector cu toate entitatile
     */
    vector<T> getAll() override;

    void update(unsigned int id, T newEntity) override;

    void deleteEntity(unsigned int id) override;

};


#endif //LAB_9_10_REPOINMEMORY_H
