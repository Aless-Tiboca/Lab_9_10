//
// Created by alext on 17/05/2022.
//

#ifndef LAB_9_10_BANKNOTESERVICE_H
#define LAB_9_10_BANKNOTESERVICE_H


#include "../Domain/Banknote/Banknote.h"
#include "../Domain/Banknote/BanknoteValidator.h"
#include "../Repository/IRepo.h"

class BanknoteService {
private:
    BanknoteValidator validator;
    IRepo<Banknote>& repository;

    bool doesExist(unsigned int id);
public:

    BanknoteService(IRepo<Banknote> &repo);

    void create(Banknote entity);
    vector<Banknote> getAll();
    void update(unsigned int id, Banknote newEntity);
    void deleteBanknote(unsigned int id);
    void updateAll(vector<Banknote> newVector);
    Banknote getBanknoteByValue(double value);
    vector<Banknote> change(double productPrice, double insertedAmount);
};

#endif //LAB_9_10_BANKNOTESERVICE_H
