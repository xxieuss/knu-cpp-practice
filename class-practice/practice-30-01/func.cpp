#include <iostream>
#include "func.h"
#include <format>
#include <cmath>
using namespace std;

Point get_point(){
    cout << "Enter your points (x, y format)";
    Point p;
    cin >> p.pos_x;
    cin >> p.pos_y;
    return p;
};

void put_point(Point p){
    cout << format("Your point is: {}, {}", p.pos_x, p.pos_y) << endl;
}
double dist(Point p, Point a){
    double dist = sqrt(pow(a.pos_x - p.pos_x, 2) + pow(a.pos_y - p.pos_y, 2));
    return dist;
}