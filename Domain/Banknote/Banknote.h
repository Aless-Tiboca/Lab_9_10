//
// Created by alext on 17/05/2022.
//

#ifndef LAB_9_10_BANKNOTE_H
#define LAB_9_10_BANKNOTE_H

#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Banknote {
private:
    double value;
    int id, noOccurrences;
public:
    Banknote();

    Banknote(int id, double value, int noOccurrences);

    Banknote(const string& line);

    ~Banknote();

    double getValue() const;

    void setValue(double value);

    int getId() const;

    int getNoOccurrences() const;

    void setNoOccurrences(int noOccurrences);

    Banknote& operator=(const Banknote &banknote);

    bool operator==(const Banknote &rhs) const;

    bool operator!=(const Banknote &rhs) const;

    friend ostream &operator<<(ostream &os, const Banknote &banknote);
};

#endif //LAB_9_10_BANKNOTE_H
