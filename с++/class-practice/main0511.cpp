#include <iostream>
#include <format>
#include <cmath>
using namespace std;

int a_func(int n){
    if(!n) return 3;
    int first_a = 3, second_a = 2;
    n--;
    while (n){
        int delta = second_a;
        second_a = 4*first_a - 3*second_a;
        first_a = delta;
        n--;
    }
    return second_a;
}

int b_func(int n){
    if (n == 0) return 1;
    int b_n, b_n_1, c_n, c_n_1;
    b_n_1 = 1;
    c_n_1 = 1;
    for (int i = 1; i <= n; i++){
        c_n = b_n_1 % c_n_1 + b_n_1;
        b_n = c_n_1 * c_n + b_n_1;
        b_n_1 = b_n;
        c_n_1 = c_n;
    }
    return b_n;
}

double sum_func(int n){
    double summ_p = sin(1);
    double summ_q = cos(1);
    double summ_s = summ_q / summ_p;
    for (int i = 1; i <= n; i++){
        summ_p += cos(i);
        summ_q += sin(i);
        summ_s += summ_q/summ_p;
    }
    return summ_s;
}

int main(){
    // prob 1
    // int n;
    // cin >> n;
    // cout << a_func(n) << endl;

    //prob 2
    // int n;
    // cin << n;
    // cout << b_func(n) << endl;

    // prob 3
    int n;
    cin >> n;
    cout << 

    return 0;
}