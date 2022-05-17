//
// Created by alext on 17/05/2022.
//

#include "BanknoteValidator.h"
#include "../Exception.h"

void BanknoteValidator::validate(Banknote banknote) {
    if(banknote.getId() <= 0) {
        throw Exception("Aparatul accepta doar bancnote de tipul: 0.01, 0.05, 0.10, 0.5, 1, 5, 10, 50, 100, 200 sau 500 RON.");
    }
    else if(banknote.getNoOccurrences() < 0) {
        throw Exception("Numarul de aparitii a banilor trebuie sa fie pozitiv!");
    }
}