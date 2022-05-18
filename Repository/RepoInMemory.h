//
// Created by alext on 21/04/2022.
//

#ifndef LAB_9_10_REPOINMEMORY_H
#define LAB_9_10_REPOINMEMORY_H

#include <bits/stdc++.h>
#include "../Domain/Ticket/Ticket.h"
#include "IRepo.h"
#include <vector>

template <class T> class RepoInMemory: public IRepo<T>{
private:
    vector<T> entities;
public:
    RepoInMemory() = default;

    void create(T t) {
        entities.push_back(t);
    }

    vector<T> getAll() {
        return entities;
    }

    void update(unsigned int id, T newEntity) {
        for(auto &i: entities){
            if (i.getId() == id) i = newEntity;
        }
    }

    void deleteEntity(unsigned int id) {
        for(int i = 0; i < entities.size(); i++) {
            if(entities[i].getId() == id) {
                entities.erase(entities.begin() + i);
            }
        }
    }

};


#endif //LAB_9_10_REPOINMEMORY_H
