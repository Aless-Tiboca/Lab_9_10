//
// Created by alext on 12/04/2022.
//

#include <cstring>
#include <algorithm>
#include "TicketService.h"


TicketService::TicketService(IRepo &repo) : repo(repo) {}

void TicketService::create(Ticket ex) {
    this->repo.create(ex);
}

void TicketService::update(string id, Ticket newTicket) {
    this->repo.update(id, newTicket);
}

vector<Ticket> TicketService::getAll() {
    return this->repo.getAll();
}

vector<Ticket> TicketService::deleteTicket(string id) {
    this->repo.deleteTicket(id);
    return this->repo.getAll();
}

int TicketService::getSumOfTicketsFromADay(string day) {
    int sum = 0;
    for(auto &item: repo.getAll()){
        if(item.getZiua() == day){
            sum += item.getPret();
        }
    }
    return sum;
}







