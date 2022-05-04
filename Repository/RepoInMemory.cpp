//
// Created by alext on 21/04/2022.
//

#include "RepoInMemory.h"

RepoInMemory::RepoInMemory() {
    tickets = vector<Ticket>();
}

void RepoInMemory::create(Ticket t) {
    vector<string> myList = {"Luni", "Marti", "Miercuri", "Joi", "Vineri", "Sambata", "Duminica"};
    bool ok = true;
    for(auto &i: tickets){
        if(t.getId() == i.getId())
            ok = false;
    }
    if(find(myList.begin(), myList.end(), t.getZiua()) != myList.end() && ok){
        tickets.push_back(t);
        }
    else if(!ok){
        cout<<"Id-ul exista deja!"<<endl;
    }
}

vector<Ticket> RepoInMemory::getAll() {
    return tickets;
}

void RepoInMemory::update(string id, Ticket newTicket) {
    for(auto &i: tickets){
        if (i.getId() == id) i = newTicket;
    }
}

void RepoInMemory::deleteTicket(string id) {
    for(auto i: tickets) {
        if (i.getId() == id){
            tickets.erase(find(tickets.begin(), tickets.end(), i));
        }
    }
}
