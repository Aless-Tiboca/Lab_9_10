//
// Created by alext on 17/05/2022.
//

#include "BanknoteValidator.h"
#include "../Exception.h"
#include "../DoubleCompare.h"

void BanknoteValidator::validate(Banknote banknote) {
    vector<double> vecOfNums = { 0.01, 0.05, 0.10, 0.5, 1, 5, 10, 50, 100, 200, 500 };
    bool ok = false;
    for(auto item: vecOfNums){
        if(DoubleCompare::equal(item, banknote.getValue()))
            ok = true;
    }
    if(banknote.getId() < 0 || banknote.getId() > INT_MAX) {
        throw Exception("ID-ul trebuie sa fie un numar pozitiv!");
    }
    else if(banknote.getValue() <= 0 || banknote.getValue() > INT_MAX || !ok) {
        throw Exception("Aparatul accepta doar bancnote de tipul: 0.01, 0.05, 0.10, 0.5, 1, 5, 10, 50, 100, 200 sau 500 RON.");
    }
    else if(banknote.getNoOccurrences() <= 0 || banknote.getNoOccurrences() > INT_MAX) {
        throw Exception("Numarul de aparitii a banilor trebuie sa fie pozitiv!");
    }
}