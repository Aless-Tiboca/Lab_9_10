//
// Created by alext on 21/04/2022.
//

#include <sstream>
#include <string>
#include <vector>
#include "Ticket.h"

Ticket::Ticket(int id) : id(id) {
    this->pret = 0;
    this->ziua = "Luni";
}

Ticket::Ticket(int id, const string &ziua, const string &cod, double pret) : id(id), ziua(ziua), cod(cod),
                                                                                    pret(pret) {}

Ticket::Ticket(const string& line) {
    vector<string> aux;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        aux.push_back(word);
    }
    this->id = stoi(aux[1]);
    this->pret = stod(aux[7]);
    this->cod = aux[5];
    this->ziua = aux[3];
}

int Ticket::getId() const {
    return id;
}

const string &Ticket::getZiua() const {
    return ziua;
}

const string &Ticket::getCod() const {
    return cod;
}

double Ticket::getPret() const {
    return pret;
}

void Ticket::setZiua(const string &ziua) {
    Ticket::ziua = ziua;
}

void Ticket::setCod(const string &cod) {
    Ticket::cod = cod;
}

void Ticket::setPret(double pret) {
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


Ticket &Ticket::operator=(const Ticket &rhs) {
    this->id = rhs.id;
    this->pret = rhs.pret;
    this->cod = rhs.cod;
    this->ziua = rhs.ziua;
    return *this;
}

