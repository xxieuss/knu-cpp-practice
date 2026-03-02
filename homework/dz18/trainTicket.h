#pragma once
#include <iostream>
#include <string>

class Ticket{
private:
    std::string name;
    static int classQuantity;
    static const int MAX_QUANTITY = 60;
    Ticket(std::string passengerName);

public:
    ~Ticket();
    Ticket(const Ticket& other) = delete;
    Ticket& operator=(const Ticket& other) = delete;
    std::string get_ticket_name() const;
    static Ticket* create(std::string passengerName);
};