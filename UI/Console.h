//
// Created by alext on 03/05/2022.
//

#ifndef LAB_9_10_CONSOLE_H
#define LAB_9_10_CONSOLE_H

#include <iostream>
#include "../Service/TicketService.h"
#include "../Service/BanknoteService.h"

using namespace std;

class Console {
private:
    TicketService ticketService;
    BanknoteService banknoteService;
public:
    Console(const TicketService &ticketService, const BanknoteService &banknoteService);

    void runTicketMenu();
    void runBanknoteMenu();
    void runAdmin();
    void runMenu();
    void runClient();

    void getAll();

    void sumOfTicketFromADay();

    void purchaseATicket();

    void showBanknotes();

    void addBanknotes();

    void modifyTickets();

    void deleteTicket();

    void addTickets();

    void pickUpChange(double &inserted, Ticket &ticket, vector<Banknote> copy);

    void insertMoney(double &inserted, double credit, Ticket &ticket);

    void updateBanknotes();

    void deleteBanknotes();

    void change();
};


#endif //LAB_9_10_CONSOLE_H
