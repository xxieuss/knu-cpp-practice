#include <iostream>
using namespace std;

// 1.
const long long mod = 1000000007;

long long recFunc(long long n, long long mod){
    long long r_1 = 3;
    long long r_2 = 7;
    long long r_3 = mod - 2;
    long long r_4 = 9;
    long long r_n;

    if (n==1) return r_1;
    if (n==2) return r_2;
    if (n==3) return r_3;
    if (n==4) return r_4;

    for (int i = 5; i <= n; ++i){
        long long expr1 = (r_4 * r_1) % mod;
        long long expr2 = (2 * r_2 % mod) * r_3 % mod;
        r_n = (expr1 - expr2 + mod) % mod;
        r_1 = r_2;
        r_2 = r_3;
        r_3 = r_4;
        r_4 = r_n;
    }
    return r_n;
}

// 5.
double sqrtFunc(double x){
    if (x==0) return 0;
    double y_1 = 1;
    double y_n;
    const double eps = 1e-6;
    int i = 0;
    do{
        y_n = 0.5 * (y_1 + x/y_1);
        if ((y_n - y_1) * (y_n - y_1) <= eps*eps) break;
        y_1 = y_n;
    } while (true);
    return y_n;
}

int main(){
    // 1.
    long long n;
    cout << "Введіть натуральне число n: ";
    cin >> n;
    if (cin.fail()){
        cout << "error";
        return 0;
    }
    if (n <= 0){
        cout << "error";
        return 0;
    }
    cout << recFunc(n, mod) << endl;

    // 5.
    double x;
    cout << "Введіть додатнє число х: ";
    cin >> x;
    if (cin.fail()){
        cout << "error";
        return 0;
    }
    if (x < 0){
        cout << "error";
        return 0;
    }
    cout << sqrtFunc(x);

    return 0;
}