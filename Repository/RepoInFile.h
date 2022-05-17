//
// Created by alext on 03/05/2022.
//


#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include "RepoInMemory.h"
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
    explicit RepoInFile(string fileName);
    void create(T p) override;
    void deleteEntity(unsigned int id) override;
    void update(unsigned int id, T p) override;
    vector<T> getAll() override;
    void loadFromFile();
    void saveToFile();
    void clearFile();
};