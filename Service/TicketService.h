//
// Created by alext on 12/04/2022.
//

#ifndef LAB_7_8_SERVICE_H
#define LAB_7_8_SERVICE_H

#include "../Repository/IRepo.h"
#include "../Repository/RepoInMemory.h"

class TicketService {
private:
    IRepo& repo;

public:
    TicketService(IRepo &repo);

    void create(Ticket ex);
    void update(string id, Ticket newTicket);
    vector<Ticket> getAll();
    vector<Ticket> deleteTicket(string id);
    int getSumOfTicketsFromADay(string day);

};


#endif //LAB_7_8_SERVICE_H
