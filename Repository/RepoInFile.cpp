//
// Created by alext on 04/05/2022.
//

#include "RepoInFile.h"

RepoInFile::RepoInFile(string filename) {
    this->fileName = filename;
    this->loadFromFile();
}

void RepoInFile::loadFromFile() {
    if(!this->fileName.empty()) {
        ifstream f(this->fileName);
        string Sid;
        string id;
        string code;
        string zi;
        int price;
        while (!f.eof())
        {

            f>>Sid>>id;
            f>>Sid>>zi;
            f>>Sid>>code;
            f>>Sid>>price;
            bool ok = false;
            for (const auto& a: this->getAll())
                if (a.getId() == id) { ok = true; }
            if(!ok) {
                Ticket p(id, zi, code, price);
                this->create(p);
            }

        }
        f.close();
    }
}

void RepoInFile::saveToFile() {

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

void RepoInFile::create(Ticket p) {
    RepoInMemory::create(p);
    saveToFile();
}

void RepoInFile::deleteTicket(string id){
    RepoInMemory::deleteTicket(id);
    saveToFile();
}

void RepoInFile::update(string id, Ticket p) {
    RepoInMemory::update(id, p);
    saveToFile();
}

vector<Ticket> RepoInFile::getAll() {
    return RepoInMemory::getAll();
}

void RepoInFile::clearFile() {
    ofstream f(this->fileName);
    f<<"";
}
