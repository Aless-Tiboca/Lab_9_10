//
// Created by alext on 21/04/2022.
//

#include "RepoInMemory.h"

template<class T>
RepoInMemory<T>::RepoInMemory() = default;

template<class T>
void RepoInMemory<T>::create(T t) {
    entities.push_back(t);
}

template<class T>
vector<T> RepoInMemory<T>::getAll() {
    return entities;
}

template<class T>
void RepoInMemory<T>::update(unsigned int id, T newEntity) {
    for(auto &i: entities){
        if (i.getId() == id) i = newEntity;
    }
}

template<class T>
void RepoInMemory<T>::deleteEntity(unsigned int id) {
    for(auto i: entities) {
        if (i.getId() == id){
            entities.erase(find(entities.begin(), entities.end(), i));
        }
    }
}
