//
// Created by alext on 03/05/2022.
//


#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include "RepoInMemory.h"
#include "IRepo.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

template <class T>
class RepoInFile: public RepoInMemory<T> {
private:
    string fileName;
public:
    RepoInFile(string filename) {
        this->fileName = filename;
        this->loadFromFile();
    }

    void loadFromFile() {
        if(!this->fileName.empty()) {
            string line;
            ifstream f(this->fileName);
            while (getline(f, line)) {
                T object(line);
                RepoInMemory<T>::create(object);
            }
        }
    }

    void saveToFile() {

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

    void create(T p) {
        RepoInMemory<T>::create(p);
        saveToFile();
    }

    void deleteEntity(unsigned int id){
        RepoInMemory<T>::deleteEntity(id);
        saveToFile();
    }


    void update(unsigned int id, T p) {
        RepoInMemory<T>::update(id, p);
        saveToFile();
    }

    vector<T> getAll() {
        return RepoInMemory<T>::getAll();
    }

    void clearFile() {
        ofstream f(this->fileName);
        f<<"";
    }

};

