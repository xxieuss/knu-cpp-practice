#include <iostream>
#include <cstdlib>
#include "museum.h"
using namespace std;

Exposures::Exposures(string name, int expoPrice){
    this -> name = name;
    this -> expoPrice = expoPrice;
}

Ticket::Ticket(){
    this -> id = rand();
    this -> num_choices = 0;
}

int Ticket::ticket_price(const Exposures expo[], int expoQuantity){
    int price = 0;
    for (int i=0; i<num_choices; i++){
        bool found = false;
        for (int j=0; j<expoQuantity; j++){
            if (choice[i] == expo[j].name){
                price += expo[j].expoPrice;
                found = true;
                break;
            }
        }
        if (!found) cout << "There is no such category as: " << choice[i] << endl;
    }
    return price;
}

void Ticket::print_ticket(const Exposures expo[], int expoQuantity){
    cout << "Ticket #" << id << " total: " << ticket_price(expo, expoQuantity) << " USD\n";
}