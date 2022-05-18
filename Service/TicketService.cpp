//
// Created by alext on 12/04/2022.
//

#include <cstring>
#include <algorithm>
#include "TicketService.h"
#include "../Domain/Exception.h"
#include <iterator>


TicketService::TicketService(IRepo<Ticket> &repo) : repo(repo) {}

bool TicketService::doesExist(int id) {
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

void TicketService::update(int id, Ticket newTicket) {
    if(!doesExist(id)) {
        throw Exception("Nu exista un obiect cu ID-ul dat!");
    }
    validator.validate(newTicket);
    this->repo.update(id, newTicket);
}

vector<Ticket> TicketService::getAll() {
    if(repo.getAll().size() == 0) {
        throw Exception("Nu sunt bilete disponibile!.");
    }
    return this->repo.getAll();
}

vector<Ticket> TicketService::deleteTicket(int id) {
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

Ticket TicketService::getById(int id) {
    for (auto &item: repo.getAll()) {
        if (item.getId() == id) {
            return item;
        }
    }
    throw Exception("Nu exista un bilet cu ID-ul dat!");
}