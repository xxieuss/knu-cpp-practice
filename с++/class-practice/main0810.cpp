#include <iostream>
using namespace std;

bool triangleExists(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double f(double x){
    if (x > -2 && x < 1){
        return pow(x, 2) + 1;
    }
    else if (x >= 1){
        return 2*x;
    }
    else if (x <= -2){
        return 5/(x+1);
    }
}

int hexDigit(char n){
    if (n >= 'A' && n <= 'F'){
        return n - 'A' + 10;
    }
    else if (n >= '0' && n<='9'){
        return n - '0';
    }
}

int main() {
    // prob 1
    cout << "3, 4, 5: " << triangleExists(3, 4, 5)<< endl;
    cout << "4, 3, 5: " << triangleExists(4, 3, 5)<< endl;
    cout << "1, 1, 4: " << triangleExists(1, 1, 4)<< endl;
    cout << "-3, -4, -5: " << triangleExists(-3, -4, -5)<< endl;

    // prob 2
    cout << "f(0): " << f(0) << endl;
    cout << "f(-1): " << f(-1) << endl;
    cout << "f(2): " << f(2) << endl;
    cout << "f(-3): " << f(-3) << endl;

    // prob 3
    cout << "hexDigit('0'): " << hexDigit('0') << endl;
    cout << "hexDigit('1'): " << hexDigit('1') << endl;
    cout << "hexDigit('2'): " << hexDigit('2') << endl;
    cout << "hexDigit('3'): " << hexDigit('3') << endl;
    cout << "hexDigit('4'): " << hexDigit('4') << endl;
    cout << "hexDigit('5'): " << hexDigit('5') << endl;
    cout << "hexDigit('6'): " << hexDigit('6') << endl;
    cout << "hexDigit('7'): " << hexDigit('7') << endl;
    cout << "hexDigit('8'): " << hexDigit('8') << endl;
    cout << "hexDigit('9'): " << hexDigit('9') << endl;
    cout << "hexDigit('A'): " << hexDigit('A') << endl;
    cout << "hexDigit('B'): " << hexDigit('B') << endl;
    cout << "hexDigit('C'): " << hexDigit('C') << endl;
    cout << "hexDigit('D'): " << hexDigit('D') << endl;
    cout << "hexDigit('E'): " << hexDigit('E') << endl;
    cout << "hexDigit('F'): " << hexDigit('F') << endl;
}