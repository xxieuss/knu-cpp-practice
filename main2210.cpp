#include <iostream>
using namespace std;

int f1(int x, int &calls, int depth, int &maxdepth){
    calls++;
    if (depth > maxdepth){
        maxdepth = depth;
    }
    if (x < 4){
        return 1;
    }
    if (x%2 == 0){
        return 2*f1(x/2, calls, depth+1, maxdepth);
    }
    return f1(x-2, calls, depth+1, maxdepth) + f1(x-1, calls, depth+1, maxdepth);
}

long long f2(long long x){
    if (x < 0){
        return -f2(-x);
    }
    long long d = 0;
    long long y = 0;
    if (x == 0){
        return x;
    }
    d = f2(x/10);
    y = x%10;
    if (y == 3){
        y = 7;
    }
    return d*10 + y;
}

int flip(int n, int &base){
    if (n < 10){
        base = 10;
        return n;
    }
    int result = flip(n/10, base);
    int digit = n % 10;
    result = digit * base + result;
    base *= 10;
    return result;
}
int flip(int n){
    int base;
    return flip(n, base);
}

int main(){
    //// prob 1 ////
    // int x, calls, maxdepth;
    // maxdepth = 0;
    // calls = 0;
    // cout << "Введіть ціле число: " << endl;
    // cin >> x;
    // cout << "result: " << f1(x, calls, 0, maxdepth) << endl;
    // cout << "counter: " << calls << endl;
    // cout << "maxdepth: " << maxdepth << endl;

    //// prob 2 ////
    // long long x;
    // cout << "Введіть число: " << endl;
    // cin >> x;
    // cout << "result: " << f2(x) << endl;

    //// prob 3 ////
    // int x;
    // cin >> x;
    // cout << flip(x) << endl;
    return 0;
}