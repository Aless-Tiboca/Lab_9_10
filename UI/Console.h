//
// Created by alext on 03/05/2022.
//

#ifndef LAB_9_10_CONSOLE_H
#define LAB_9_10_CONSOLE_H

#include <iostream>
#include "../Service/TicketService.h"

using namespace std;

class Console {
private:
    TicketService service;
    int banknotesTypes[5] = {1, 5, 10, 50, 100};
    map<int, int> myBanknotes;
public:
    Console(const TicketService &service);
    void runTicketMenu();
    void runBanknoteMenu();
    void runAdmin();
    void runMenu();
};


#endif //LAB_9_10_CONSOLE_H
