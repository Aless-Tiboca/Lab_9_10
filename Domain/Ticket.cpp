//
// Created by alext on 21/04/2022.
//

#include "Ticket.h"

Ticket::Ticket(const string &id) : id(id) {
    this->pret = 0;
    this->ziua = "Luni";
}

Ticket::Ticket(const string &id, const string &ziua, const string &cod, int pret) : id(id), ziua(ziua), cod(cod),
                                                                                    pret(pret) {}

const string &Ticket::getZiua() const {
    return ziua;
}

const string &Ticket::getCod() const {
    return cod;
}

int Ticket::getPret() const {
    return pret;
}

void Ticket::setZiua(const string &ziua) {
    Ticket::ziua = ziua;
}

void Ticket::setCod(const string &cod) {
    Ticket::cod = cod;
}

void Ticket::setPret(int pret) {
    Ticket::pret = pret;
}

bool Ticket::operator==(const Ticket &rhs) const {
    return (id == rhs.id);
}

bool Ticket::operator!=(const Ticket &rhs) const {
    return !(rhs == *this);
}



ostream &operator<<(ostream &os, const Ticket &ticket) {
    os << "id: " << ticket.id << " ziua: " << ticket.ziua << " cod: " << ticket.cod << " pret: " << ticket.pret <<endl;
    return os;
}

const string &Ticket::getId() const {
    return id;
}

Ticket &Ticket::operator=(const Ticket &rhs) {
    this->id = rhs.id;
    this->pret = rhs.pret;
    this->cod = rhs.cod;
    this->ziua = rhs.ziua;
}
