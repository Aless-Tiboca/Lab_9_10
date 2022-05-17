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

    for(int i = 0; i < repository.getAll().size(); i++) {
        while(DoubleCompare::greaterOrEqual(changeValue, repository.getAll()[i].getValue()) && repository.getAll()[i].getNoOccurrences()> 0) {
            changeValue -= repository.getAll()[i].getValue();
            repository.getAll()[i].setNoOccurrences(repository.getAll()[i].getNoOccurrences() - 1);
            changeVector[i].setNoOccurrences(changeVector[i].getNoOccurrences() + 1);
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

