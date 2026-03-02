#include <iostream>
using namespace std;

int count(long long n, int r){
    int r_c = 0;
    if (n==0 && r == 0){
        return 1;
    }
    if (n<0){
        n = -n;
    }
    while (n>0){
        if (n%10 == r) r_c++;
        n /= 10;
    }
    return r_c;
}

int main(){
    // long long n;
    // cout << "Enter a number: " << endl;
    // cin >> n;
    // int r;
    // cout << "Enter a digit: " << endl;
    // cin >> r;
    // cout << count(n, r) << endl;

    int n;
    cin >> n;
    int max = -1e9;
    for (int i=0; i <= n; i++){
        int a;
        cin >> a;
        if (a>max){
            max = a;
        }
    }
    return 0;
}