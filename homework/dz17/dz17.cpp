#include <iostream>
#include <string>
#include "numberM.h"
#include "car.h"
using namespace std;

int main(){
    //prob 1
    // NumberM a(500);
    // NumberM b(20);
    // NumberM c = a + b;
    // std::cout << "a = " << (std::string)a << std::endl;
    // std::cout << "a + b = " << c << std::endl;
    // std::cout << "c - 10 = " << (c + (-10)) << std::endl;

    // prob 6
    Car car(100, "AA1111AA", "lanos", 0.0);
    cout << car << endl;
    car += 10;
    car >>= 50;
    cout << car << endl;
    car <<= 50;
    cout << car << endl;
    if (!car) car += 10;
    car <<= (double)car;
    cout << car << endl;
    return 0;
}