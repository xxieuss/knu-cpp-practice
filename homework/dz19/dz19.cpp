#include <iostream>
#include "telephone.h"
#include "matrix.h"
using namespace std;

int main(){
    // 1.
    // Telephone phone;
    // phone.add(new Battery(1000));

    // Battery* old_b = nullptr;
    // old_b = phone.add(new Battery(2000));
    // delete old_b;

    // phone.add(new Camera(15));
    // phone.photo();

    // try {
    //     phone.photo();
    // }
    // catch(const exception &e) {
    //     cout << e.what() << endl;
    // }

    // try{
    //     phone.call();
    // }
    // catch(const exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    // cout << phone << endl;


    // 2.
    // try {
    //     cout << "For Pon M10 Pro Max" << endl;
    //     Telephone* new_phone = Telephone::create_phone("Pon M10 Pro Max");
    //     cout << *new_phone << endl;
    //     delete new_phone; 
        
    //     cout << "For fake model: " << endl;
    //     Telephone* fake_phone = Telephone::create_phone("Nokia 3310");
        
    // } catch (const exception& e) {
    //     cout << e.what() << endl;
    // }


    // 4.
    // Matrix m(2, 3);
    // m(0, 0) = 10;
    // m(0, 1) = 20;
    // m(0, 2) = 30;
    // m(1, 0) = 40;
    // m(1, 1) = 50;
    // m(1, 2) = 60;
    // for (int i = 0; i < m.getRows(); ++i) {
    //     for (int j = 0; j < m.getCols(); ++j) {
    //         cout << m(i, j) << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << "checking the change of the first element:" << endl;
    // Matrix a = m;
    // a(0, 0) = 999;
    // cout << m(0, 0) << endl;
    // cout << a(0, 0) << endl;

    // cout << "checking the out of range error:" << endl;
    // try {
    //     m(5, 5) = 100;
    // } 
    // catch (const out_of_range& e) {
    //     cout << e.what() << endl;
    // }

    // 9.
    Matrix s(3, 3);
    int counter = 1;
    for (int i = 0; i < s.getRows(); ++i) {
        for (int j = 0; j < s.getCols(); ++j) {
            s(i, j) = counter++;
        }
    }

    cout << "orig matrix:" << endl;
    for (int i = 0; i < s.getRows(); ++i) {
        for (int j = 0; j < s.getCols(); ++j) {
            cout << s(i, j) << "\t";
        }
        cout << endl;
    }

    cout << "resize to 2x2:" << endl;
    s.resize(2, 2);
    for (int i = 0; i < s.getRows(); ++i) {
        for (int j = 0; j < s.getCols(); ++j) {
            cout << s(i, j) << "\t";
        }
        cout << endl;
    }

    cout << "resize to 4x4:" << endl;
    s.resize(4, 4);
    for (int i = 0; i < s.getRows(); ++i) {
        for (int j = 0; j < s.getCols(); ++j) {
            cout << s(i, j) << "\t";
        }
        cout << endl;
    }

    return 0;
}