//
// Created by alext on 21/04/2022.
//

#ifndef LAB_9_10_REPOINMEMORY_H
#define LAB_9_10_REPOINMEMORY_H

#include <bits/stdc++.h>
#include "../Domain/Ticket.h"
#include "IRepo.h"
#include <vector>

class RepoInMemory: public IRepo{
private:
    vector<Ticket> tickets;
public:
    /**
     * Constructor
     */
    RepoInMemory();

    /**
     * Adauga o entitate in repository
     * @param e entitatea de adaugat
     */
    void create(Ticket t) override;

    /**
     * Returneaza toate entitatile intr-un vector
     * @return un vector cu toate entitatile
     */
    vector<Ticket> getAll() override;

    void update(string id, Ticket newTicket) override;

    void deleteTicket(string id) override;

};


#endif //LAB_9_10_REPOINMEMORY_H
