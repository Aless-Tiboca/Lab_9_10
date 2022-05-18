//
// Created by alext on 17/05/2022.
//

#include <vector>
#include "TicketValidator.h"
#include "../Exception.h"
#include <algorithm>

void TicketValidator::validate(Ticket ticket) {
    vector<string> week{"Luni", "Marti", "Miercuri", "Joi", "Vineri", "Sambata", "Duminica"};

    if(ticket.getId() <= 0) {
        throw Exception("ID-ul trebuie sa fie pozitiv!");
    }
    else if(ticket.getZiua().size() == 0) {
        throw Exception("Ziua trebuie sa fie diferita de NULL!");
    }
    else if(!(std::find(std::begin(week), std::end(week), ticket.getZiua()) != std::end(week))){
        throw Exception("Ziua trebuie sa fie dintre zilele saptamanii!");
    }
    else if(ticket.getCod().size() == 0) {
        throw Exception("Codul trebuie sa fie diferit de NULL!");
    }
    else if(ticket.getPret() <= 0) {
        throw Exception("Pretul trebuie sa fie pozitiv!");
    }
}
