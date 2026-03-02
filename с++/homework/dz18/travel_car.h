#pragma once
#include <iostream>
#include <string>

enum class Weather {
    Summer,
    Winter
};
struct Route {
    double distance;
    double time;
    Weather weather;
    int passengers;
};

class Car{
public:
    enum class TireType {
        Summer,
        Rain,
        Winter,
        AllSeason
    };
private:
    std::string carModel;
    int carSpeed;
    int carSeats;
    TireType carTires;
public:
    Car(std::string model, int speed, int seats, TireType tires);
    explicit operator std::string() const;
    friend std::ostream& operator<< (std::ostream& os, const Car& obj);

    void change_speed(int newSpeed);
    void change_seats(int newSeats);
    void change_tire_type(TireType newTires);
    bool can_complete_route(const Route& route) const;
};