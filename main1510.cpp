#include <iostream>
#include <exception>
#include <cmath>
#include <format>
using namespace std;

// prob 1
double getSides(){
    double a;
    cout << "Enter side: ";
    cin >> a;
    if (a <= 0) {
        throw invalid_argument("Side lengths must be positive numbers.");
    }
    return a;
}
double calcTrianglePerimeter(double a, double b, double c){
    return a + b + c;
}

// prob 2
double getX(){
    double x;
    cout << "Enter x: ";
    cin >> x;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        throw ::ios_base::failure("Invalid input. Please enter a numeric value.");
    }
    if (sin(x) <= 0){
        throw domain_error("sin(x) must be positive.");
    }
    return x;
}
double f(double x){
    return 1 / sqrt(sin(x));
}

int main() {
    // prob 1
    // double a, b, c;
    // try{
    //     double a = getSides();
    //     double b = getSides();
    //     double c = getSides();
    //     if (a + b <= c || a + c <= b || b + c <= a) {
    //         throw invalid_argument("The provided lengths do not form a valid triangle.");
    //     }
    //     cout << "Perimeter: " << calcTrianglePerimeter(a, b, c) << endl;
    // }
    // catch (const invalid_argument& e) {
    //     cout << "Error: " << e.what() << endl;
    //     return 0;
    // }

    //prob 2
    // try{
    //     double x = getX();
    //     cout << format("Result: {:.4f}", f(x)) << endl;
    //     return 0;
    // }
    // catch (const ios_base::failure& e) {
    //     cout << "Error: " << e.what() << endl;
    //     return 0;
    // }
    // catch (const domain_error& e) {
    //     cout << "Error: " << e.what() << endl;
    //     return 0;
    // }

    return 0;
}