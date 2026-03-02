#include <iostream>
#include <string>
#include <algorithm>
#include "travel_car.h"

Car::Car(std::string model, int speed, int seats, TireType tires){
    this -> carModel = model;
    this -> carSpeed = 10;
    this -> carSeats = 1;
    this -> carTires = tires;

    change_speed(speed);
    change_seats(seats);
    change_tire_type(tires);
}

Car::operator std::string() const {
    std::string tireStr;
    switch (carTires) {
        case TireType::Summer: tireStr = "Summer"; break;
        case TireType::Rain: tireStr = "Rain"; break;
        case TireType::Winter: tireStr = "Winter"; break;
        case TireType::AllSeason: tireStr = "All-season"; break;
    }
    return "Car " + carModel + ", engine speed: " + std::to_string(carSpeed) + ", seats: " + std::to_string(carSeats) + 
    ", tires type: " + tireStr;
}
std::ostream& operator<<(std::ostream& os, const Car& obj) {
    os << static_cast<std::string>(obj);
    return os;
}

void Car::change_speed(int newSpeed){
    if (newSpeed >= 10 && newSpeed <= 200) carSpeed = newSpeed;
}

void Car::change_seats(int newSeats){
    if (newSeats >= 1 && newSeats <= 8) carSeats = newSeats;
}

void Car::change_tire_type(TireType newTires){
    carTires = newTires;
}

bool Car::can_complete_route(const Route& route) const {
    if (route.passengers > carSeats) {
        return false;
    }

    if (route.time <= 0) return false;
    
    double requiredSpeed = route.distance / route.time;
    if (carSpeed < requiredSpeed) {
        return false;
    }

    if (route.weather == Weather::Winter) {
        if (carTires != TireType::Winter && carTires != TireType::AllSeason) {
            return false;
        }
    } else if (route.weather == Weather::Summer) {
        if (carTires == TireType::Winter) {
            return false;
        }
    }

    return true;
}