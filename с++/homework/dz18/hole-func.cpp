#include <iostream>
#include <string>
#include "hole.h"

Bar::Bar(double x, double y, double z){
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

Hole::Hole(double a, double b){
    this -> a = a;
    this -> b = b;
}

std::string Hole::get_rotation(const Bar& bar) const{
    double bar_x = bar.x;
    double bar_y = bar.y;
    double bar_z = bar.z;

    if (bar_x <= a && bar_y <= b) return ".";
    if (bar_x <= a && bar_z <= b) return "x";
    if (bar_z <= a && bar_y <= b) return "y";
    if (bar_y <= a && bar_z <= b) return "xy";
    if (bar_z <= a && bar_x <= b) return "yx";
    if (bar_y <= a && bar_x <= b) return "z";
    return "";
}