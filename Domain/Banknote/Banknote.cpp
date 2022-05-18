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
    this->value = stod(aux[3]);
    this->noOccurrences = stoi(aux[5]);
}

double Banknote::getValue() const {
    return value;
}

void Banknote::setValue(double value) {
    Banknote::value = value;
}

int Banknote::getId() const {
    return id;
}

int Banknote::getNoOccurrences() const {
    return noOccurrences;
}

void Banknote::setNoOccurrences(int noOccurrences) {
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
    os << "id: " << banknote.id << " value: " << banknote.value  << " noOccurrences: " << banknote.noOccurrences <<endl;
    return os;
}

Banknote::Banknote(int id, double value, int noOccurrences) : value(value), id(id),
                                                                                noOccurrences(noOccurrences) {}

Banknote &Banknote::operator=(const Banknote &banknote) {
    this->id = banknote.id;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
    return *this;
}
