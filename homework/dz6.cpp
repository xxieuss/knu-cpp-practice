#include <iostream>
#include <cmath>
#include <numbers>
#include <format>
using namespace std;

// 5.a
bool taskFiveA(int x){
    if (x % 3 == 0){
        return true;
    } else{
        return false;
    }
}
// 5.b
bool taskFiveB(int a, int b, int c){
    if (a != b && b != c && a != c){
        return true;
    } else{
        return false;
    }
}
// 5.c
bool taskFiveC(char y){
    if (y == '?' || y == '!'){
        return true;
    } else{
        return false;
    }
}
// 6.a
bool taskSixA(int x, int y){
    if (x % 2 == 0 && y % 2 == 0){
        return true;
    } 
    else if (x % 2 != 0 && y % 2 != 0){
        return true;
    } 
    else{
        return false;
    }
}
// 6.b
bool taskSixB(int x, int y){
    if (x % y == 0){
        return true;
    } else{
        return false;
    }
}
// 7.
void getLinesCoefficients(double &a1, double &b1, double &c1, double &a2, double &b2, double &c2) {
    cout << "Введіть коефіцієнти a1, b1, c1 для першої прямої: ";
    cin >> a1 >> b1 >> c1;
    cout << "Введіть коефіцієнти a2, b2, c2 для другої прямої: ";
    cin >> a2 >> b2 >> c2;
}
// 7.a
bool linesIntersect (double a1, double b1, double c1, double a2, double b2, double c2) {
    if (a1 * b2 != a2 * b1) {
        return true;
    } else {
        return false;
    }
}
// 7.b
bool linesPerpendicular (double a1, double b1, double c1, double a2, double b2, double c2) {
    if (a1 * a2 + b1 * b2 == 0) {
        return true;
    } else {
        return false;
    }
}
// 8.
void sortValues(int& a, int& b, int& c) {
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}
// 9.
void sortValues(int& a, int& b, int& c, int& d) {
    if (b < a) {
        swap(a, b);
    }
    if (c < a) {
        swap(a, c);
    }
    if (d < a) {
        swap(a, d);
    }
    sortValues(b, c, d);
}
// 10.
double f(double x, double y){
    if (x == 0){
        return y*y;
    }
    else if (x > 1){
        return x / (2*y-2);
    }
    else if (x < -1){
        return x / (y+1);
    }
    else {
        return x*y + 3;
    }
}
// 11.
double calculateMass(double h, double d, double density) {
    double volume = ::numbers::pi * pow(d / 2, 2) * h;
    if (density < 0){
        density = 1000;
        return volume * density;
    }
    return volume * density;
}
// 12.
int numberOfSolutions(double a, double b, double c, int solutions) {
    if (a == 0){
        if (b == 0){
            if (c == 0){
                return solutions = -1;
            }
            else {
                return solutions = 0;
            }
        }
        else {
            return solutions = 1;
        }
    }
    else {
        double discriminant = b*b - 4*a*c;
        if (discriminant > 0) {
            return solutions = 2;
        } 
        else if (discriminant == 0) {
            return solutions = 1;
        } 
        else {
            return solutions = 0;
        }
    }
}



int main() {
    // 5.a
    // int x;
    // cout << "Введіть число х: ";
    // cin >> x;
    // cout << taskFiveA(x);

    // 5.b
    // int a, b, c;
    // cout << "Введіть числа a, b та c: ";
    // cin >> a >> b >> c;
    // cout << taskFiveB(a, b, c);

    // 5.c
    // char y;
    // cout << "Введіть символ y: ";
    // cin >> y;
    // cout << taskFiveC(y);

    // 6.
    // int x, y;
    // cout << "Введіть числа x та y: ";
    // cin >> x >> y;
    // 6.a
    // if (taskSixA(x, y)){
    //     cout << "Числа мають однакову парність";
    // } else{
    //     cout << "Числа мають різну парність";
    // }
    // 6.b
    // if (taskSixB(x, y)){
    //     cout << "x ділиться націло на y";
    // } else{
    //     cout << "x не ділиться націло на y";
    // }

    // 7.
    // double a1, b1, c1, a2, b2, c2;
    // getLinesCoefficients(a1, b1, c1, a2, b2, c2);
    // 7.a
    // if (linesIntersect(a1, b1, c1, a2, b2, c2)) {
    //     cout << "Прямі перетинаються.";
    // } else {
    //     cout << "Прямі не перетинаються.";
    // }
    // 7.b
    // if (linesPerpendicular(a1, b1, c1, a2, b2, c2)) {
    //     cout << "Прямі перпендикулярні.";
    // } else {
    //     cout << "Прямі не перпендикулярні.";
    // }

    // 8.
    // int a, b, c;
    // cout << "Введіть три числа: ";
    // cin >> a >> b >> c;
    // sortValues(a, b, c);
    // cout << "Відсортовані числа: " << a << " " << b << " " << c << endl;
    // 9.
    // int d;
    // cout << "Введіть четверте число: ";
    // cin >> d;
    // sortValues(a, b, c, d);
    // cout << "Відсортовані числа: " << a << " " << b << " " << c << " " << d << endl;

    // 10.
    // double x, y;
    // cout << "Введіть числа х та y: ";
    // cin >> x >> y;
    // cout << "Результат f(x, y): " << f(x, y) << endl;

    // 11.
    // double h, d, density;
    // cout << "Введіть висоту, діаметр та густину: ";
    // cin >> h >> d >> density;
    // cout << "Маса циліндра: " << format("{:.3f}", calculateMass(h, d, density)) << " кг" << endl;

    // 12.
    // int solutions;
    // double a, b, c;
    // cout << "Введіть коефіцієнти a, b та c рівняння типу ax^2 + bx + c = 0: ";
    // cin >> a >> b >> c;
    // cout << "Кількість розв'язків: " << numberOfSolutions(a, b, c, solutions) << endl;

    return 0;
}