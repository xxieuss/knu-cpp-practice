#pragma once
#include <iostream>
#include <string>

class Car{
    double fuel;
    const double MAX_FUEL = 250.0;
    const double fuelByKM = 2.0;
    std::string model;
    std::string carNum;
    double coordinate;

    public:
    Car(double fuel, std::string carNum, std::string model, double coordinate);

    Car& operator+=(double addedFuel); // fuel refilling

    explicit operator bool() const; // fuel supply
    explicit operator double() const; // current coordinate
    explicit operator std::string() const; // car info in string

    // shift to a new coordinate
    Car& operator<<=(double shift);
    Car& operator>>=(double shift);

    friend std::ostream& operator<< (std::ostream& os, const Car& obj); // car info
};