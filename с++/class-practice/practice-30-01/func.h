#pragma once

struct Point{
    int pos_x;
    int pos_y;
};

Point get_point();
void put_point(Point p);
double dist(Point p1, Point p2);