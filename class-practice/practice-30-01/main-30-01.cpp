#include <iostream>
#include "func.h"
#include <cmath>
#include <format>
using namespace std;

int main(){
    Point p1 = get_point();
    Point p2 = get_point();
    put_point(p1);
    put_point(p2);
    cout << "Distance between p1 and p2: " << dist(p1, p2) << endl;
}