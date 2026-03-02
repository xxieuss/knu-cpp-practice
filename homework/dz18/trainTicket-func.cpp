#include <iostream>
#include <string>
#include "trainTicket.h"

int Ticket::classQuantity = 0;

Ticket::Ticket(std::string passengerName) {
    name = passengerName;
}

Ticket::~Ticket(){
    classQuantity--;
}

std::string Ticket::get_ticket_name() const {
    return name;
}

Ticket* Ticket::create(std::string passengerName) {
    if (classQuantity < MAX_QUANTITY) {
        classQuantity++;
        return new Ticket(passengerName);
    } else {
        std::cout << "There are no available tickets." << std::endl;
        return nullptr;
    }
}