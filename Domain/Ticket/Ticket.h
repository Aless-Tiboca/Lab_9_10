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
    string ziua, cod;
    int id;
    double pret;
public:
    Ticket(int id);

    Ticket(const string& line);

    Ticket(int id, const string &ziua, const string &cod, double pret);

    int getId() const;

    const string &getZiua() const;

    const string &getCod() const;

    double getPret() const;

    void setZiua(const string &ziua);

    void setCod(const string &cod);

    void setPret(double pret);

    bool operator==(const Ticket &rhs) const;

    bool operator!=(const Ticket &rhs) const;

    Ticket& operator=(const Ticket& rhs);

    friend ostream &operator<<(ostream &os, const Ticket &ticket);

};


#endif //LAB_9_10_CURSA_H
