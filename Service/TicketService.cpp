//
// Created by alext on 12/04/2022.
//

#include <cstring>
#include <algorithm>
#include "TicketService.h"
#include "../Domain/Exception.h"
#include <iterator>


TicketService::TicketService(IRepo<Ticket> &repo) : repo(repo) {}

bool TicketService::doesExist(unsigned int id) {
    for(auto &item: repo.getAll()){
        if(item.getId() == id)
            return true;
    }
    return false;
}

void TicketService::create(Ticket ex) {
    if(doesExist(ex.getId())) {
        throw Exception("Exista deja un produs cu ID-ul dat!");
    }
    validator.validate(ex);
    this->repo.create(ex);
}

void TicketService::update(unsigned int id, Ticket newTicket) {
    if(!doesExist(id)) {
        throw Exception("Nu exista un obiect cu ID-ul dat!");
    }
    validator.validate(newTicket);
    this->repo.update(id, newTicket);
}

vector<Ticket> TicketService::getAll() {
    return this->repo.getAll();
}

vector<Ticket> TicketService::deleteTicket(unsigned int id) {
    if(!doesExist(id)) {
        throw Exception("Nu exista un obiect cu ID-ul dat!");
    }
    this->repo.deleteEntity(id);
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