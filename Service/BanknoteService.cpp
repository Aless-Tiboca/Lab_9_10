//
// Created by alext on 17/05/2022.
//

#include "BanknoteService.h"
#include "../Domain/DoubleCompare.h"
#include "../Domain/Exception.h"

BanknoteService::BanknoteService(IRepo<Banknote> &repo):repository(repo) {}

bool BanknoteService::doesExist(unsigned int id) {
    for(auto& item: repository.getAll()){
        if(item.getId() == id)
            return true;
    }
    return false;
}

void BanknoteService::create(Banknote entity) {
    if(doesExist(entity.getId())) {
        throw Exception("Exista deja o bancnota cu valoarea aceasta!");
    }
    validator.validate(entity);
    repository.create(entity);
}

vector<Banknote> BanknoteService::getAll() {
    if(repository.getAll().size() == 0) {
        throw Exception("Nu exista bancnote disponibile!.");
    }
    return repository.getAll();
}

void BanknoteService::update(unsigned int id, Banknote newEntity) {
    if(!doesExist(id)) {
        throw Exception("Nu exista o bancnota cu ID-ul dat");
    }
    validator.validate(newEntity);
    repository.update(id, newEntity);
}

void BanknoteService::deleteBanknote(unsigned int id) {
    if(!doesExist(id)) {
        throw Exception("Nu exista o bancnota cu ID-ul dat");
    }
    repository.deleteEntity(id);
}

void BanknoteService::updateAll(vector<Banknote> newVector) {
    for(auto& item: newVector){
        update(item.getId(), item);
    }
}

vector<Banknote> BanknoteService::change(double productPrice, double insertedAmount) {
    double changeValue = insertedAmount - productPrice;
    vector<Banknote> changeVector;
    changeVector.push_back(Banknote(1, 500, 0));
    changeVector.push_back(Banknote(2, 200, 0));
    changeVector.push_back(Banknote(3, 100, 0));
    changeVector.push_back(Banknote(4, 50, 0));
    changeVector.push_back(Banknote(5, 10, 0));
    changeVector.push_back(Banknote(6, 5, 0));
    changeVector.push_back(Banknote(7, 1, 0));
    changeVector.push_back(Banknote(8, 0.5, 0));
    changeVector.push_back(Banknote(9, 0.1, 0));
    changeVector.push_back(Banknote(10, 0.05, 0));
    changeVector.push_back(Banknote(11, 0.01, 0));

    if(repository.getAll().size() != 11 ||
       (repository.getAll()[0].getNoOccurrences() == 0 &&
        repository.getAll()[1].getNoOccurrences() == 0 &&
        repository.getAll()[2].getNoOccurrences() == 0 &&
        repository.getAll()[3].getNoOccurrences() == 0 &&
        repository.getAll()[4].getNoOccurrences() == 0 &&
        repository.getAll()[5].getNoOccurrences() == 0 &&
        repository.getAll()[6].getNoOccurrences() == 0 &&
        repository.getAll()[7].getNoOccurrences() == 0 &&
        repository.getAll()[8].getNoOccurrences() == 0 &&
        repository.getAll()[9].getNoOccurrences() == 0 &&
        repository.getAll()[10].getNoOccurrences() == 0)) {
        return changeVector;
    }
    else {
        for (int i = 0; i < 11; i++) {
            while (DoubleCompare::greaterOrEqual(changeValue, repository.getAll()[i].getValue()) &&
                   repository.getAll()[i].getNoOccurrences() > 0) {
                changeValue -= repository.getAll()[i].getValue();
                Banknote updatedBanknote(repository.getAll()[i].getId(), repository.getAll()[i].getValue(), repository.getAll()[i].getNoOccurrences() - 1);
                repository.update(repository.getAll()[i].getId(), updatedBanknote);

                Banknote newBanknote(changeVector[i].getId(), changeVector[i].getValue(), changeVector[i].getNoOccurrences() + 1);
                changeVector[i] = newBanknote;
            }
        }
    }

    return changeVector;
}

Banknote BanknoteService::getBanknoteByValue(double value) {
    for(auto& item: repository.getAll()) {
        if(item.getValue() == value) {
            return item;
        }
    }
}

