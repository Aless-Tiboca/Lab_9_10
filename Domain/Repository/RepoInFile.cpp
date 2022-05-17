//
// Created by alext on 04/05/2022.
//

#include "RepoInFile.h"

template <class T>
RepoInFile<T>::RepoInFile(string filename) {
    this->fileName = filename;
    this->loadFromFile();
}

template <class T>
void RepoInFile<T>::loadFromFile() {
    if(!this->fileName.empty()) {
        string line;
        ifstream f(this->fileName);
        while (getline(f, line)) {
            T object(line);
            RepoInMemory<T>::create(object);
        }
    }
}

template <class T>
void RepoInFile<T>::saveToFile() {

    if (!this->fileName.empty())
    {
        ofstream f(this->fileName);
        for(auto& a: this->getAll())
        {
            f << a;
        }
        f.close();
    }
}

template <class T>
void RepoInFile<T>::create(T p) {
    RepoInMemory<T>::create(p);
    saveToFile();
}

template <class T>
void RepoInFile<T>::deleteEntity(unsigned int id){
    RepoInMemory<T>::deleteEntity(id);
    saveToFile();
}

template <class T>
void RepoInFile<T>::update(unsigned int id, T p) {
    RepoInMemory<T>::update(id, p);
    saveToFile();
}

template <class T>
vector<T> RepoInFile<T>::getAll() {
    return RepoInMemory<T>::getAll();
}

template <class T>
void RepoInFile<T>::clearFile() {
    ofstream f(this->fileName);
    f<<"";
}
