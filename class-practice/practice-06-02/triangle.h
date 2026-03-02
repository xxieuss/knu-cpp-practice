#pragma once
#include "func.h"
using namespace std;

struct Triangle{
    Point p1;
    Point p2;
    Point p3;
    double square();

    Triangle(Point p1, Point p2, Point p3);
};