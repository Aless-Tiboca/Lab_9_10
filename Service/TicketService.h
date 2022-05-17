//
// Created by alext on 12/04/2022.
//

#ifndef LAB_7_8_SERVICE_H
#define LAB_7_8_SERVICE_H

#include "../Repository/IRepo.h"
#include "../Repository/RepoInMemory.h"
#include "../Domain/Ticket/TicketValidator.h"

class TicketService {
private:
    IRepo<Ticket>& repo;
    TicketValidator validator;

    bool doesExist(unsigned int id);

public:
    TicketService(IRepo<Ticket> &repo);

    void create(Ticket ex);
    void update(unsigned int id, Ticket newTicket);
    vector<Ticket> getAll();
    vector<Ticket> deleteTicket(unsigned int id);
    int getSumOfTicketsFromADay(string day);

};


#endif //LAB_7_8_SERVICE_H
