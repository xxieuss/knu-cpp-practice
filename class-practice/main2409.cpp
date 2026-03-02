#include <iostream>
#include <format>
#include <cmath>
#include <numbers>
using namespace std;

int main() {
    cout << "4*6/8 = " << 4*6/8 << endl;
    cout << "4/8*6 = " << 4/8*6 << endl;
    cout << "2*(7%8) = " << 2*(7%8) << endl;

    cout << "2*(-7%8) = " << 2*(-7%8) << endl;
    cout << "2*(7%-8) = " << 2*(7%-8) << endl;
    cout << "2*(-7%-8) = " << 2*(-7%-8) << endl;

    cout << "6225/19 = " << 6225/19 << endl;
    cout << "6225/-19 = " << 6225/-19 << endl;
    cout << "-6225/19 = " << -6225/19 << endl;
    cout << "-6225/-19 = " << -6225/-19 << endl;

    cout << "5-3%2 = " << 5-3%2 << endl;

    cout << "(3/5)*21+32.0 = " << (3/5)*21+32.0 << endl; // 3/5=0 => 0+32
    cout << "(3.0/5)*21+32 = " << (3.0/5)*21+32 << endl; // 3.0/5 ≠ 0 => 44
    cout << "(3/5.0)*21+32 = " << (3/5.0)*21+32 << endl;
    cout << "(3.0/5.0)*21+32 = " << (3.0/5.0)*21+32 << endl;

    cout << "(int)3.14 = " << (int)3.14 << endl; //(int) перетворює в ціле
    cout << "int(3.14) = " << int(3.14) << endl;

    cout << "int(3.76) = " << int(3.76) << endl;
    cout << "int(-3.14) = " << int(-3.14) << endl;
    cout << "int(9.99999) = " << int(9.99999) << endl;

    cout << fixed << "double(3) = " << double(3) << endl;

    cout << "13/2+3 = " << 13/2+3 << endl; // 13/2 => +3 => 9
    cout << "13/(2+3) = " << 13/(2+3) << endl; // 2+3 => 13/5 => 2

    cout << "13/(2.0+3) = " << 13/(2.0+3) << endl; // 13/2.0 => +3 => 9.5
    cout << "13/(2+3.0) = " << 13/(2+3.0) << endl;

    int a=13, b=2, c=3;
    cout << "a/(b+c) = " << a/(b+c) << endl;
    cout << "double(a)/(b+c) = " << double(a)/(b+c) << endl;
    cout << "a/(double(b+c)) = " << a/(double(b+c)) << endl;
    cout << "a/(b+double(c)) = " << a/(b+double(c)) << endl;

    char ch = 98;
    cout << "ch = " << ch << endl;
    cout << "'f' - 'o' = " << 'f' - 'o' << endl;

    cout << "true*' ' - false*'b' = " << true*' ' - false*'b' << endl; 
    bool p=true; // 1
    bool l=false; // 0
    cout << "bool(4) = " << bool(4) << endl; // будь-яке не нульове число - true
    cout << "bool(0) = " << bool(0) << endl; // 0 - false
    cout << "bool(-3.14) = " << bool(-3.14) << endl;

    char in;
    cout << "Enter a character: ";
    cin >> in;
    cout << "position in alphabet: " << in - 'a' << endl; // = in -> value
    int r;
    cout << "Value: " << r << endl;

    cout << "sin(60) = " << sin(60) << endl; // 60 rad = -0.304811
    cout << "pi = " << numbers::pi << endl;
    cout << "sin(pi/3) = " << sin(numbers::pi/3) << endl;
    cout << format("{:.30f}\n{:.30f}\n{:.30f}\n", numbers::pi_v<float>, numbers::pi_v<double>, numbers::pi_v<long double>) << endl;
 }