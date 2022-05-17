//
// Created by alext on 21/04/2022.
//

#include "RepoInMemory.h"

template<class T>
RepoInMemory<T>::RepoInMemory() = default;

template<class T>
void RepoInMemory<T>::create(T t) {
    tickets.push_back(t);
}

template<class T>
vector<T> RepoInMemory<T>::getAll() {
    return tickets;
}

template<class T>
void RepoInMemory<T>::update(unsigned int id, T newEntity) {
    for(auto &i: tickets){
        if (i.getId() == id) i = newEntity;
    }
}

template<class T>
void RepoInMemory<T>::deleteEntity(unsigned int id) {
    for(auto i: tickets) {
        if (i.getId() == id){
            tickets.erase(find(tickets.begin(), tickets.end(), i));
        }
    }
}
