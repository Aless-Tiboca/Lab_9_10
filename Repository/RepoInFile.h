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

class RepoInFile: public RepoInMemory {
private:
    string fileName;
public:
    explicit RepoInFile(string fileName);
    void create(Ticket p) override;
    void deleteTicket(string id) override;
    void update(string id, Ticket p) override;
    vector<Ticket> getAll() override;
    void loadFromFile();
    void saveToFile();
    void clearFile();
};