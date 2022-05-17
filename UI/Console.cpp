//
// Created by alext on 03/05/2022.
//

#include "Console.h"
#include "../Domain/DoubleCompare.h"

Console::Console(const TicketService &ticketService, const BanknoteService &banknoteService) : ticketService(
        ticketService), banknoteService(banknoteService) {}

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
                addTickets();
                break;
            }
            case '2': {
                deleteTicket();
                break;
            }
            case '3': {
                modifyTickets();
                break;
            }
            case '4': {
                getAll();
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

void Console::addTickets() {
    try{
        int id;
        string zi, cod;
        double pret;
        cout << "Dati ID-ul biletului:" << endl;
        cin >> id;
        cout << "Dati ziua biletului:" << endl;
        cin >> zi;
        cout << "Dati codul biletului:" << endl;
        cin >> cod;
        cout << "Dati pretul biletului:" << endl;
        cin >> pret;
        Ticket ticket(id, zi, cod, pret);
        ticketService.create(ticket);
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::deleteTicket() {
    try{
        int id;
        cout << "Dati ID-ul biletului pe care doriti sa il stergeti:" << endl;
        cin>>id;
        vector<Ticket> tickets = ticketService.deleteTicket(id);
        for(auto i :tickets){
            cout<<i;
        }
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::modifyTickets() {
    try{
        int id;
        string zi, cod;
        double pret;
        cout << "Dati ID-ul biletului pe care doriti sa il modoficati:" << endl;
        cin >> id;
        cout << "Dati noua zi a biletului:" << endl;
        cin >> zi;
        cout << "Dati noul cod a biletului:" << endl;
        cin >> cod;
        cout << "Dati noul pret a biletului:" << endl;
        cin >> pret;
        Ticket newTicket(id, zi, cod, pret);
        ticketService.update(id, newTicket);
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::getAll() {
    ticketService.getAll();
    for (auto i: ticketService.getAll()) {
        cout << i;
    }
}

void printBanknoteMenu(){
    cout<<"----------BANKNOTES------------"<<endl;
    cout<<"1)Adauga bancnote"<<endl;
    cout<<"2)Afiseaza bancnotele"<<endl;
    cout<<"3)Modifica o bancnota"<<endl;
    cout<<"4)Sterge o bancnota"<<endl;
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
                addBanknotes();
                break;
            }
            case '2': {
                showBanknotes();
                break;
            }
            case '3': {
                updateBanknotes();
                break;
            }
            case '4': {
                deleteBanknotes();
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

void Console::deleteBanknotes() {
    try {
        int id;
        cout<<"Dati ID-ul bancnotei pe care doriti sa o stergeti:"<<endl;
        cin>>id;
        banknoteService.deleteBanknote(id);
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::updateBanknotes() {
    try {
        int id, nrOcc;
        double value;
        cout<<"Dati ID-ul bancnotei pe care doriti sa o modificati:"<<endl;
        cin>>id;
        cout<<"Dati valoarea bancnotei:"<<endl;
        cin>>value;
        cout<<"Dati numarul aparitilor bancnotei:"<<endl;
        cin>>nrOcc;
        banknoteService.update(id, Banknote(id, value, nrOcc));
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::addBanknotes() {
    try {
        int id, nrOcc;
        double value;
        cout<<"Dati ID-ul bancnotei:"<<endl;
        cin>>id;
        cout<<"Dati valoarea bancnotei:"<<endl;
        cin>>value;
        cout<<"Dati numarul aparitilor bancnotei:"<<endl;
        cin>>nrOcc;
        banknoteService.create(Banknote(id, value, nrOcc));
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}

void Console::showBanknotes() {
    for(auto& i: banknoteService.getAll())
        cout << i;
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
                runClient();
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
    cout<<"----------ADMIN------------"<<endl;
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
                sumOfTicketFromADay();
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

void Console::sumOfTicketFromADay() {
    string day;
    cout<<"Introduceti ziua pentru care doriti sa calculati totalul:"<<endl;
    cin>>day;
    cout << "Totalul pentru " << day << " este: " << ticketService.getSumOfTicketsFromADay(day) << endl;
}

void printClientMenu() {
    cout<<"----------CLIENT------------"<<endl;
    cout<<"1)Arata biletele disponibile"<<endl;
    cout<<"2)Cumpara bilet"<<endl;
    cout<<"x)Iesire"<<endl;
}

void Console::runClient() {
    bool ok = true;
    char option;
    while(ok) {
        printClientMenu();
        cout << "Introduceti optiunea: " << endl;
        cin >> option;
        switch (option) {
            case '1': {
                getAll();
                break;
            }
            case '2': {
                unsigned int id;
                cout << "Dati ID-ul biletului pe care doriti sa il cumparati: ";
                cin >> id;
                int index = 0;
                double inserted = 0;
                double credit;
                for(int i = 0;i < ticketService.getAll().size(); i++){
                    if(ticketService.getAll()[i].getId() == id) {
                        index = id;
                        i =  ticketService.getAll().size();
                    }
                }
                vector<Banknote> copy = banknoteService.getAll();
                insertMoney(inserted, credit, ticketService.getAll()[index]);
                pickUpChange(inserted, ticketService.getAll()[index], copy);
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

void Console::insertMoney(double &inserted, double credit, Ticket &ticket) {
    while(DoubleCompare::less(inserted, ticket.getPret())) {
        cout << "Inserati credit (0.01/0.05/0.1/0.5/1/5/10/50/100/200/500):";
        cin >> credit;

        if(DoubleCompare::equal(credit, 0.01) ||
           DoubleCompare::equal(credit, 0.05) ||
           DoubleCompare::equal(credit, 0.1) ||
           DoubleCompare::equal(credit, 0.5) ||
           DoubleCompare::equal(credit, 1) ||
           DoubleCompare::equal(credit, 5) ||
           DoubleCompare::equal(credit, 10) ||
           DoubleCompare::equal(credit, 50) ||
           DoubleCompare::equal(credit, 100) ||
           DoubleCompare::equal(credit, 200) ||
           DoubleCompare::equal(credit, 500)) {
            Banknote banknote = banknoteService.getBanknoteByValue(credit);
            banknote.setNoOccurrences(banknote.getNoOccurrences() + 1);
            banknoteService.update(banknote.getId(), banknote);
            inserted += credit;
        }
        else {
            cout << "Nu se accepta tipul de bancnota!" << '\n';
        }
    }
}

void Console::pickUpChange(double &inserted, Ticket &ticket, vector<Banknote> copy) {
    std::vector<Banknote> result = banknoteService.change(ticket.getPret(), inserted);
    if (DoubleCompare::equal(inserted, ticket.getPret())) {
        cout << "Operatiunea a fost finalizata cu succes!" <<endl;
        ticketService.deleteTicket(ticket.getId());
    } else {
        unsigned int checker = 0;
        for (int i = 0; i < result.size(); i++) {
            checker += result[i].getNoOccurrences();
        }
        if (checker == 0) {
            banknoteService.updateAll(copy);
            cout<< "Nu se poate oferi rest!"<<endl;
        } else {
            double change = 0;
            for (int i = 0; i < result.size(); i++) {
                change += result[i].getValue() *
                          result[i].getNoOccurrences();
            }

            if (DoubleCompare::equal(change, inserted - ticket.getPret())) {
                ticketService.deleteTicket(ticket.getId());
                cout << "Poti ridica restul: " <<endl;
                for(auto& item: result){
                    if(item.getNoOccurrences() != 0){
                        cout<<item.getNoOccurrences() << "bancnote de "<<item.getValue()<<" RON"<<endl;
                    }
                }
                cout << "Total: " << change << " RON." <<endl;
            } else {
                banknoteService.updateAll(copy);
                cout<< "Nu se poate oferi rest!"<<endl;
            }
        }
    }
}