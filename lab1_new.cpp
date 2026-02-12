#include <iostream>
#include <numbers>
#include <cmath>
#include <format>
using namespace std;

void checkDomain(double x){ // Checks if the value of x is outside of the functions's domain.
    if (x == 14 || x <= 12){
        throw domain_error("Error message");
    }
}

double f(double x){ // Calculates the value of the expression from variant 152.
    return sin(15/50.0) + 12.0*::numbers::e/(45.0*::numbers::pi) 
    * 6.0/((x-14)*(x+5)) - 14*atan(x+3) - log(x-12) / log(5);
}

int main(){
    cout << "The author of this program is Anna Kondriuk." << endl;
    cout << "This program calculates the value of the expression by given x. Variant 152." << endl;
    cout << "Enter real number x (x>12 && x!=14): ";
    double x;
    cin >> x;
    if (cin.fail()){
        cout << "wrong input" << endl;
        return 0;
    }
    cout << "***** do calculations ... ";
    bool valid = true;
    double result = 0.0;
    try{
        checkDomain(x);
        result = f(x);
    }
    catch(const domain_error& e){
        valid = false;
    }
    cout << "done" << endl;
    cout << "for x = " << format("{:.7f}", x) << endl;
    cout << "result = ";
    if (valid){
        cout << format("{:.8f}", result) << endl;
    } else {
        cout << "undefined" << endl;
    }
    return 0;
}