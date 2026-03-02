#include <iostream>
#include <format>
using namespace std;

int main() {
    // завдання 4
    double x;
    cout << "Введіть дійсне значення: ";
    cin >> x;

    cout << format("{:.6f}\n", x) << endl;
    cout << format("{:.3e}\n", x) << endl;
    cout << format("{:+.3e}\n", x) << endl;

    // завдання 5
    int day, month, year;
    cout << "Введіть дату народження (день місяць рік): ";
    cin >> day >> month >> year;
    cout << "Ваша дата народження: " << format("{:02d}/{:02d}/{:04d}\n", day, month, year) << endl;
}