#include <iostream>
#include "triangle.h"
#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3){
    this -> p1 = p1;
    this -> p2 = p2;
    this -> p3 = p3;
    if (square() <= 0){
        throw invalid_argument("error");
    }
}

double Triangle::square(){
    Point v1 (p2.pos_x - p1.pos_x, p2.pos_y - p1.pos_y);
    Point v2 (p3.pos_x - p1.pos_x, p3.pos_y - p1.pos_y);
    return 0.5*(abs((v1.pos_x * v2.pos_y) - (v1.pos_y * v2.pos_x)));
}