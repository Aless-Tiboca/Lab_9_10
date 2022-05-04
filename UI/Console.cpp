//
// Created by alext on 03/05/2022.
//

#include "Console.h"

Console::Console(const TicketService &service): service(service) {}

void printTicketMenu(){
    cout<<"----------Ticket box------------"<<endl;
    cout<<"1)Adauga un bilet"<<endl;
    cout<<"2)Sterge un bilet"<<endl;
    cout<<"3)Modifica un Bilet"<<endl;
    cout<<"4)Afiseaza toate biletele"<<endl;
    cout<<"x)Iesire"<<endl;
}

void Console::runTicketMenu() {
    bool ok = true;
    char option;
    while(ok) {
        printTicketMenu();
        cout<<"Introduceti optiunea: "<<endl;
        cin>>option;
        switch(option) {
            case '1': {
                string id, zi, cod;
                int pret;
                cout << "Dati ID-ul biletului:" << endl;
                cin >> id;
                cout << "Dati ziua biletului:" << endl;
                cin >> zi;
                cout << "Dati codul biletului:" << endl;
                cin >> cod;
                cout << "Dati pretul biletului:" << endl;
                cin >> pret;
                Ticket ticket(id, zi, cod, pret);
                this->service.create(ticket);
                break;
            }
            case '2': {
                string id;
                cout << "Dati ID-ul biletului pe care doriti sa il stergeti:" << endl;
                cin>>id;
                vector<Ticket> tickets = this->service.deleteTicket(id);
                for(auto i :tickets){
                    cout<<i;
                }
                break;
            }
            case '3': {
                string id, zi, cod;
                int pret;
                cout << "Dati ID-ul biletului pe care doriti sa il modoficati:" << endl;
                cin >> id;
                cout << "Dati noua zi a biletului:" << endl;
                cin >> zi;
                cout << "Dati noul cod a biletului:" << endl;
                cin >> cod;
                cout << "Dati noul pret a biletului:" << endl;
                cin >> pret;
                Ticket newTicket(id, zi, cod, pret);
                this->service.update(id, newTicket);
                break;
            }
            case '4': {
                this->service.getAll();
                for (auto i: service.getAll()) {
                    cout << i;
                }
                break;
            }
            case 'x': {
                ok = false;
                break;
            }
            default:
                cout << "Optiunea introdusa este incorecta!" << endl;
        }
    }
}

void printBanknoteMenu(){
    cout<<"----------BANKNOTES------------"<<endl;
    cout<<"1)Adauga bancnote"<<endl;
    cout<<"2)Afiseaza bancnotele"<<endl;
    cout<<"x)Iesire"<<endl;
}

void Console::runBanknoteMenu() {
    bool ok = true;
    char option;
    while(ok) {
        printBanknoteMenu();
        cout << "Introduceti optiunea: " << endl;
        cin >> option;
        switch (option) {
            case '1': {
                int value;
                myBanknotes.clear();
                for(auto& i: banknotesTypes){
                    cout << i << " Lei:"; cin >> value;
                    myBanknotes.emplace(i, value);
                }
                break;
            }
            case '2': {
                for(auto& i: myBanknotes)
                    cout << i.first << " Lei/" << "Count: " << i.second << endl;
                break;
            }
            case 'x':{
                ok = false;
                break;
            }
            default:
                cout << "Optiunea introdusa este incorecta!" << endl;
        }
    }
}

void printMenu(){
    cout<<"----------MENU------------"<<endl;
    cout<<"1)Admin"<<endl;
    cout<<"2)Client"<<endl;
    cout<<"x)Iesire"<<endl;
}

void Console::runMenu() {
    bool ok = true;
    char option;
    while(ok) {
        printMenu();
        cout << "Introduceti optiunea: " << endl;
        cin >> option;
        switch (option) {
            case '1': {
                runAdmin();
                break;
            }
            case '2':{
                break;
            }
            case 'x':{
                ok = false;
                break;
            }
            default:
                cout << "Optiunea introdusa este incorecta!" << endl;
        }
    }
}

void printAdminMenu(){
    cout<<"----------Admin------------"<<endl;
    cout<<"1)Bilete"<<endl;
    cout<<"2)Bancnote"<<endl;
    cout<<"3)Totalul pe o zi anume"<<endl;
    cout<<"x)Iesire"<<endl;
}

void Console::runAdmin() {
    bool ok = true;
    char option;
    while(ok) {
        printAdminMenu();
        cout << "Introduceti optiunea: " << endl;
        cin >> option;
        switch (option) {
            case '1': {
                runTicketMenu();
                break;
            }
            case '2': {
                runBanknoteMenu();
                break;
            }
            case '3':{
                string day;
                cout<<"Introduceti ziua pentru care doriti sa calculati totalul:"<<endl;
                cin>>day;
                cout<<"Totalul pentru "<<day<<" este: "<<service.getSumOfTicketsFromADay(day)<<endl;
                break;
            }
            case 'x':{
                ok = false;
                break;
            }
            default:
                cout << "Optiunea introdusa este incorecta!" << endl;
        }
    }
}
