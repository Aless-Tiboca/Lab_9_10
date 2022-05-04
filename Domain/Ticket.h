//
// Created by alext on 21/04/2022.
//

#ifndef LAB_9_10_CURSA_H
#define LAB_9_10_CURSA_H

#include <string>
#include <ostream>

using namespace std;

class Ticket {
private:
    string id, ziua, cod;
    int pret;
public:
    Ticket(const string &id);

    Ticket(const string &id, const string &ziua, const string &cod, int pret);

    const string &getId() const;

    const string &getZiua() const;

    const string &getCod() const;

    int getPret() const;

    void setZiua(const string &ziua);

    void setCod(const string &cod);

    void setPret(int pret);

    bool operator==(const Ticket &rhs) const;

    bool operator!=(const Ticket &rhs) const;

    Ticket& operator=(const Ticket& rhs);

    friend ostream &operator<<(ostream &os, const Ticket &ticket);

};


#endif //LAB_9_10_CURSA_H
