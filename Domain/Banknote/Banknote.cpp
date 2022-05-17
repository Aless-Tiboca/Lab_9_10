//
// Created by alext on 17/05/2022.
//

#include "Banknote.h"

Banknote::Banknote() = default;



Banknote::Banknote(const string& line) {
    vector<string> aux;
    stringstream ss(line);
    std::string word;
    while (ss >> word) {
        aux.push_back(word);
    }
    this->id = stoi(aux[1]);
    this->noOccurrences = stod(aux[3]);
}

double Banknote::getValue() const {
    return value;
}

void Banknote::setValue(double value) {
    Banknote::value = value;
}

unsigned int Banknote::getId() const {
    return id;
}

unsigned int Banknote::getNoOccurrences() const {
    return noOccurrences;
}

void Banknote::setNoOccurrences(unsigned int noOccurrences) {
    Banknote::noOccurrences = noOccurrences;
}

Banknote::~Banknote() {}

bool Banknote::operator==(const Banknote &rhs) const {
    return id == rhs.id;
}

bool Banknote::operator!=(const Banknote &rhs) const {
    return !(rhs == *this);
}

ostream &operator<<(ostream &os, const Banknote &banknote) {
    os << " id: " << banknote.id << "value: " << banknote.value  << " noOccurrences: " << banknote.noOccurrences;
    return os;
}

Banknote::Banknote(unsigned int id, double value, unsigned int noOccurrences) : value(value), id(id),
                                                                                noOccurrences(noOccurrences) {}

Banknote &Banknote::operator=(const Banknote &banknote) {
    this->id = banknote.id;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
    return *this;
}
