#include <iostream>
#include <numbers>
#include <cmath>
#include <format>
#include <string>
using namespace std;

bool inalidDomain(double x){ // Checks if the value of x is outside of the functions's domain
    return (x == 14 || x <= 12);
}

double log5(double x){ // Calculates the base 5 logarithm of x
    return log(x) / log(5);
}

double f(double x){ // Calculates the value of the expression from variant 152
    return sin(15/50.0) + 12.0*::numbers::e/(45.0*::numbers::pi) * 6.0/((x-14)*(x+5)) - 14*atan(x+3) - log5(x-12);
}

int main(){
    cout << "The author of this program is Anna Kondriuk." << endl;
    cout << "This program calculates the value of the expression by given x. Variant 152." << endl;
    double x;
    string result;
    cout << "Enter real number x (x>12 && x!=14): ";
    cin >> x;
    if (cin.fail()){
        cout << "wrong input" << endl;
        return 1;
    }
    cout << "***** do calculations ... ";
    if (inalidDomain(x)){
        result = "undefined";
    } else{
        double resultValue = f(x);
        result = format("{:.8f}", resultValue);
    }
    cout << "done" << endl;
    cout << "for x = " << format("{:.7f}", x) << endl;
    cout << "result = " << result << endl;
}