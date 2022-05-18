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

public:
    TicketService(IRepo<Ticket> &repo);
    bool doesExist(int id);
    void create(Ticket ex);
    void update(int id, Ticket newTicket);
    vector<Ticket> getAll();
    vector<Ticket> deleteTicket(int id);
    int getSumOfTicketsFromADay(string day);
    Ticket getById(int id);
};


#endif //LAB_7_8_SERVICE_H
