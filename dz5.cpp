#include <iostream>
#include <cmath>
#include <numbers>
#include <format>
using namespace std;

// 3
double calcCtg(double x){
    return 1/tan(x);
}
double calcArcctg(double x){
    return atan(1/x);
}
double radians(double x){
    return x*(numbers::pi/180);
}
double calcSin(double x){
    return sin(x);
}

// 4.
void getPoint(double &x, double &y){
    cout << "Введіть координати точки (x, y): " << endl;
    cin >> x >> y;
}
double segmentLength(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double midpointX(double x1, double x2){
    return (x1+x2)/2;
}
double midpointY(double y1, double y2){
    return (y1+y2)/2;
}

// 5.
void getTrianglePoints(double &x, double &y){
    cout << "Введіть координати вершини трикутника (x, y): " << endl;
    cin >> x >> y;
}
double calcTriangleSides(double x1, double y1, double x2, double y2){
    double side = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return side;
}
double calcTriangleArea(double ab, double ac, double bc){
    double p = (ab+ac+bc)/2;
    double area = sqrt(p*(p-ab)*(p-ac)*(p-bc));
    return area;
}
void printTriangleArea(double area){
    cout << "Площа трикутника: " << area << endl;
}

// 6.
void getArguments(double &x, double &y){
    cout << "Введіть аргументи (x, y): " << endl;
    cin >> x >> y;
}
double myFunction(double x, double y){
    double result = (x*y - 3) / (x*x + y*y + 2);
    return result;
}
void printFunctionResult(double result){
    cout << "Результат функції: " << result << endl;
}

// 7.
void getCircleArea(double &area){
    cout << "Введіть площу кола: " << endl;
    cin >> area;
}
double calcCircleRadius(double area){
    double radius = sqrt(area/numbers::pi);
    return radius;
}
double calcCircleCircumference(double radius){
    double circumference = 2*numbers::pi*radius;
    return circumference;
}
void printCircleCalculations(double radius, double circumference){
    cout << "Радіус кола: " << radius << endl;
    cout << "Довжина кола: " << circumference << endl;
}

// 8.
void getTrapeziumSides(double &a, double &b, double &c, double &h){
    cout << "Введіть бічні сторони трапеції: " << endl;
    cin >> a >> c;
    cout << "Введіть меншу основу трапеції: " << endl;
    cin >> b;
    cout << "Введіть висоту трапеції: " << endl;
    cin >> h;
}
double calcTrapeziumSide(double &a, double &b, double &c, double &h){
    double d = b + sqrt(a*a - h*h) + sqrt(c*c - h*h);
    return d;
}
double calcTrapeziumArea(double b, double d, double h){
    double area = ((b+d)/2)*h;
    return area;
}
void printTrapeziumArea(double area){
    cout << "Площа трапеції: " << format("{:.6f}", area) << endl;
}

int main(){
    // 3.
    // double x;
    // cout << "Введіть число в градусах: " << endl;
    // cin >> x;

    // cout << "ctg(x) = " << calcCtg(x) << endl;
    // cout << "arcctg(x) = " << calcArcctg(x) << endl;
    // cout << "Ваше число в радіанах: " << radians(x) << endl;
    // cout << "sin(x) = " << calcSin(x) << endl;

    // 4.
    // double x1, x2, y1, y2;
    // getPoint(x1, y1);
    // getPoint(x2, y2);
    // cout << "Довжина відрізка: " << segmentLength(x1, y1, x2, y2) << endl;
    // cout << "Координати середини відрізка: (" << midpointX(x1, x2) << ", " << midpointY(y1, y2) << ")" << endl;

    // 5.
    // double a1, a2, b1, b2, c1, c2;
    // double ab, ac, bc;
    // double area;
    // getTrianglePoints(a1, a2);
    // getTrianglePoints(b1, b2);
    // getTrianglePoints(c1, c2);

    // ab = calcTriangleSides(a1, a2, b1, b2);
    // ac = calcTriangleSides(a1, a2, c1, c2);
    // bc = calcTriangleSides(b1, b2, c1, c2);

    // area = calcTriangleArea(ab, ac, bc);
    // printTriangleArea(area);

    // 6.
    // double x, y;
    // double result;
    // getArguments(x, y);
    // result = myFunction(x, y);
    // printFunctionResult(result);

    // 7.
    // double area;
    // double radius;
    // double circumference;
    // getCircleArea(area);
    // radius = calcCircleRadius(area);
    // circumference = calcCircleCircumference(radius);
    // printCircleCalculations(radius, circumference);

    // 8.
    // double a, b, c, d, h;
    // getTrapeziumSides(a, b, c, h);
    // d = calcTrapeziumSide(a, b, c, h);
    // double area = calcTrapeziumArea(b, d, h);
    // printTrapeziumArea(area);
    return 0;
}