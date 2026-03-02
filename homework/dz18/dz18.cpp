#include <iostream>
#include "trainTicket.h"
#include "travel_car.h"
#include "hole.h"
using namespace std;

void test_rotation(const Hole& hole, const Bar& bar, const std::string& test_name) {
    cout << test_name << ": Bar (" << bar.x << "x" << bar.y << "x" << bar.z << ") -> ";
    string result = hole.get_rotation(bar);
    
    if (result == "") {
        cout << "It won't fit!" << endl;
    } else {
        cout << "Transforms: '" << result << "'" << endl;
    }
}

int main(){
    // prob 4
    // for entering names:
    // const int n = 3;
    // Ticket* ticket[n];
    // for (int i=0; i<n; i++){
    //     string my_name;
    //     cout << "Enter your name: ";
    //     cin >> my_name;
    //     ticket[i] = Ticket::create(my_name);
    //     if (ticket[i] != nullptr) {
    //         cout << "Ticket for: " << ticket[i]->get_ticket_name() << endl;
    //         delete ticket[i]; 
    //     }
    // }

    // for checking the program:
    // Ticket* manyTickets[65];
    // for (int j=0; j<65; j++){
    //     manyTickets[j] = Ticket::create("Пасажир " + to_string(j + 1));
    //     if (manyTickets[j] != nullptr) {
    //         cout << j + 1 << ". Квиток успішно видано: " << manyTickets[j]->get_ticket_name() << endl;
    //     }
    // }
    // for (int i = 0; i < 65; ++i) {
    //     if (manyTickets[i] != nullptr) {
    //         delete manyTickets[i];
    //     }
    // }

    // prob 8
    // Car car("BMW", 100, 2, Car::TireType::Winter);
    // cout << car << endl;

    // car.change_speed(150);
    // car.change_seats(4);
    // car.change_tire_type(Car::TireType::Summer);
    // cout << car << endl;

    // prob 9
    // Route route1 = {200.0, 2.0, Weather::Summer, 3};
    // Route route2 = {300.0, 2.0, Weather::Summer, 2};
    // Route route3 = {100.0, 2.0, Weather::Winter, 2};

    // if (car.can_complete_route(route1)) cout << "Car can travel the first route." << endl;
    // else cout << "Car can't travel the first route." << endl;

    // if (car.can_complete_route(route2)) cout << "Car can travel the second route" << endl;
    // else cout << "Car can't travel the second route." << endl;

    // if (car.can_complete_route(route3)) cout << "Car can travel the third route" << endl;
    // else cout << "Car can't travel the third route." << endl;

    // car.change_tire_type(Car::TireType::AllSeason);
    
    // if (car.can_complete_route(route3)) cout << "Car can travel the third route" << endl;
    // else cout << "Car can't travel the third route." << endl;

    // prob 13
    Hole hole(4.0, 6.0);
    Bar bar1(3.0, 5.0, 10.0);
    test_rotation(hole, bar1, "Test 1: ");

    Bar bar2(3.0, 10.0, 5.0);
    test_rotation(hole, bar2, "Test 2: ");

    Bar bar3(10.0, 5.0, 3.0);
    test_rotation(hole, bar3, "Test 3: ");

    Bar bar4(10.0, 3.0, 5.0);
    test_rotation(hole, bar4, "Test 4: ");

    Bar bar5(5.0, 10.0, 3.0);
    test_rotation(hole, bar5, "Test 5: ");

    Bar bar6(5.0, 3.0, 10.0);
    test_rotation(hole, bar6, "Test 6: ");

    Bar bar7(10.0, 10.0, 10.0);
    test_rotation(hole, bar7, "Test 7: ");
    return 0;
}