#pragma once
#include <string>

struct Exposures{
    std::string name;
    int expoPrice;

    Exposures(std::string name, int expoPrice);
};

struct Ticket{
    int id;
    static const int MAX_CHOICE = 5;
    std::string choice[MAX_CHOICE];
    int num_choices;

    Ticket();

    int ticket_price(const Exposures expo[], int expoQuantity);
    void print_ticket(const Exposures expo[], int expoQuantity);
};