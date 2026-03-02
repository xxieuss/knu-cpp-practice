#include <iostream>
#include <numbers>
#include <cmath>
#include <format>
using namespace std;

// Domain of the function S(x)
const double a = -0.9;
const double b = 0.9;

double s(double x, double eps){ // Calculates the value of the function S(x)
    double sum = 0.0;
    double x_n = x*x;
    int n = 0;
    while (x_n >= eps || x_n <= -eps){
        sum += x_n;
        x_n = -(x*x) * (n+1.0)*(2*n+1.0)/((n+2.0)*(2*n+3.0)) * x_n;
        n++;
    }
    return sum;
}

int main(){
    cout << "The author of this program is Anna Kondriuk." << endl;
    cout << "This program calculates the value of the function S by given x. Variant 152." << endl;
    double x, eps, result;
    cout << "Enter the real number x (x >= -0.9 && x <= 0.9): ";
    cin >> x;
    if (cin.fail()){
        cout << "***** error" << endl;
        cout << "invalid input for x." << endl;
        return 1;
    }
    else if (x < a || x > b){
        cout << "***** error" << endl;
        cout << "x is outside the domain." << endl;
        return 1;
    }
    cout << "Enter the desired calculation accuracy (eps > 0): ";
    cin >> eps;
    if (cin.fail()){
        cout << "***** error" << endl;
        cout << "invalid input for eps." << endl;
        return 1;
    }
    else if (eps <= 0){
        cout << "***** error" << endl;
        cout << "eps must be positive." << endl;
        return 1;
    }
    cout << "***** do calculations ... ";
    result = s(x, eps);
    cout << "done" << endl;
    cout << "for x = " << format("{:.5e}", x) << endl;
    cout << "for eps = " << format("{:.8e}", eps) << endl;
    cout << "result = " << format("{:.9f}", result) << endl;
    return 0;
}