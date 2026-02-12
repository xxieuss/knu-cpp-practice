#include <iostream>
#include <numbers>
#include <cmath>
#include <format>
#include <stdexcept>
using namespace std;

// Domain of the function S(x)
const double a = -0.9;
const double b = 0.9;

double s(double x, double eps){ // Calculates the value of the function S(x)
    double sum = 0.0;
    double x_n = x*x;
    sum += x_n;
    int n = 1;
    while (x_n >= eps || x_n <= -eps){
        x_n = -(x*x) * n*(2*n-1.0)/((n+1.0)*(2*n+1.0)) * x_n;
        sum += x_n;
        n++;
    }
    return sum;
}

int main(){
    cout << "The author of this program is Anna Kondriuk." << endl;
    cout << "This program calculates the value of the function S by given x. Variant 152." << endl;
    double x, eps, result;
    try{
        cout << "Enter the real number x (x >= -0.9 && x <= 0.9): ";
        cin >> x;
        if (cin.fail()){
            throw runtime_error("invalid input for x.");
        }
        if (x < a || x > b){
            throw domain_error("x is outside the domain.");
        }
        cout << "Enter the desired calculation accuracy (eps > 0): ";
        cin >> eps;
        if (cin.fail()){
            throw runtime_error("invalid input for eps.");
        }
        if (eps <= 0){
            throw domain_error("eps must be positive.");
        }
        cout << "***** do calculations ... ";
        result = s(x, eps);
        cout << "done" << endl;
        cout << "for x = " << format("{:.5e}", x) << endl;
        cout << "for eps = " << format("{:.8e}", eps) << endl;
        cout << "result = " << format("{:.9f}", result) << endl;
    }
    catch (domain_error& e){
        cout << "***** error" << endl;
        cout << e.what() << endl;
        return 0;
    }
    catch (runtime_error& e) {
        cout << "***** error" << endl;
        cout << e.what() << endl;
        return 0;
    }
    return 0;
}