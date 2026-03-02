#include <iostream>
#include <string>
#include "human.h"
#include "triangle.h"
#include "func.h"
using namespace std;

int main(){
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(3, 3);
    Triangle t(p1, p2, p3);
    cout << "the square is: " << t.square();



    // Human h(19, 20);
    // h.humanStatus();
    // h.eat();
    // h.humanStatus();
    // h.work();
    // h.humanStatus();
    // h.work();
    // h.humanStatus();
    // h.work();
    // h.humanStatus();
    // h.sleep(8);
    // h.humanStatus();
    // h.eat();
    // h.humanStatus();
    // h.work();
    // h.humanStatus();

    // Create Triangle:
    // - can be created with 3 Points
    // - can be created with 3 sides
    // - cannot be created with wrong paramenters
    // - can calculate area
    // - can be printed (somehow)
}