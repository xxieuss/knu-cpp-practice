#include <iostream>
#include <string>
#include <algorithm>
#include "car.h"

Car::Car(double fuel, std::string carNum, std::string model, double coordinate){
    this -> fuel = fuel;
    this -> carNum = carNum;
    this -> model = model;
    this -> coordinate = coordinate;
}

Car& Car::operator+=(double addedFuel) { // fuel refilling
    fuel += addedFuel;
    if (fuel > MAX_FUEL) {
        fuel = MAX_FUEL;
    }
    return *this;
}

Car::operator bool() const { // fuel supply
    return fuel > 0.0;
}

Car::operator double() const { // current coordinate
    return coordinate;
}

Car::operator std::string() const { // car info in string
    return "Car " + model + " [" + carNum + "], Fuel: " + std::to_string(fuel) + "L, Coord: " 
    + std::to_string(coordinate);
}

// shift to a new coordinate
Car& Car::operator<<=(double shift) {
    if (fuel <= 0) return *this;
    double maxDistance = fuel / fuelByKM;
    double actualDistance = std::min(shift, maxDistance);
    coordinate -= actualDistance;
    fuel -= actualDistance * fuelByKM;
    return *this;
}
Car& Car::operator>>=(double shift) {
    if (fuel <= 0) return *this;
    double maxDistance = fuel / fuelByKM;
    double actualDistance = std::min(shift, maxDistance);
    coordinate += actualDistance;
    fuel -= actualDistance * fuelByKM;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& obj) {
    os << static_cast<std::string>(obj);
    return os;
}