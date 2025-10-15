#include <iostream>
#include <format>
#include <cmath>
using namespace std;

// type func_name(t1 arg1, t2 arg2, ...){}

int f(int x, int y){
    cout << format("inside f(x={}, y={})\n", x, y) << endl;
    return x*y;
}
void g(int x, int y){
    cout << format("inside g(x={}, y={})\n", x, y) << endl;
    return;
} // void: no return value

// probl:
// calc area of triangle
// input: a, b, c - sides (triangle exists)
// output: area, 5 digits after decimal point
// algo:
// 1. get input
//   1.1 get a;
//   1.2 get b;
//   1.3 get c;
// 2. calc area
// 3. print result
// void prob1(){
//     // 1.
//     double a = get_side();
//     double b = get_side();
//     double c = get_side();
//     // 2.
//     double area = calc_area(a,b,c);
//     // 3.
//     print(area);
// }
// double get_side(){
//     double side;
//     cout << "Enter side: ";
//     cin >> side;
//     return side;
// }
// double calc_area(double a, double b, double c){
//     double p = (a+b+c)/2; // semi-perimeter
//     double area = sqrt(p*(p-a)*(p-b)*(p-c));
//     return area;
// }
// void print(double area){
//     cout << format("Area = {:.5f}\n", area) << endl;
//}

// problem 2:
// calc distance
// input: poin1, point2
// output: distance
// algo:
// 1. get points
//   1.1 get point1
//   1.2 get point2
// 2. calc distance
// 3. print result
void get_point(double &x, double &y){
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}
double calc_distance(double x1, double y1, double x2, double y2){
    double distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return distance;
}
void print_distance(double distance){
    cout << distance << endl;
}
int main(){
    int result = f(3,4);
    cout << "f(3,4) = " << result << endl;
    //cout << g(3,4) << endl;
    g(3,4); // no return value

    // 1.
    double x1, y1;
    double x2, y2;
    get_point(x1, y1);
    get_point(x2, y2);
    // 2.
    double distance = calc_distance(x1, y1, x2, y2);
    // 3.
    print_distance(distance);
}