#pragma once
#include <iostream>
#include <string>

class Bar{
public:
    double x, y, z;
    Bar(double x, double y, double z);
};

class Hole{
private:
    double a, b;
public:
    Hole(double a, double b);
    std::string get_rotation(const Bar& bar) const;
};