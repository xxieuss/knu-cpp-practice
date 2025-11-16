#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// 3.
long long inverseNumber(long long x){
    long long result = 0, num = x;
    if (x < 0) num = -x;
    while (num > 0){
        int digit = num % 10;
        result = result*10 + digit;
        num = num/10;
    }
    if (x<0) return -result;
    return result;
}

// 4.
double func(double x){
    return cos(sin(7*x)) + cos(log(x) / log(2));
}
double maxFunc(double a, double b, long long delta = 2000000){
    if (b <= 0) return NAN;
    if (a <= 0) a = 1e-9;
    if (a > b) return NAN;

    double maxValue = func(a);
    double deltaSize = (b-a) / static_cast<double>(delta);
    for (long long i = 1; i <= delta; ++i){
        double x = a + i * deltaSize;
        double currentValue = func(x);
        if (currentValue > maxValue) maxValue = currentValue;
    }
    return maxValue;
}

// 5.
int maxY_a(long long x){
    long long y = 0, factorial = 1;
    while (true){
        if (x / (y+1) < factorial) break;
        y += 1;
        factorial *= y;
    }
    return y;
}
int maxY_b(long long x){
    int y = 0;
    double sum = 0.0;
    while (true){
        double nextLog = log(y+1) / log(2);
        if (sum+nextLog > x) break;
        sum += nextLog;
        y += 1;
    }
    return y;
}
int maxY_c(long long x){
    if (x<1) return 0;
    int y=0;
    long long power = 1;
    while (power <= x/3){
        power *= 3;
        y += 1;
    }
    return y;
}

// 6.
bool checkPrimeNum(int x){
    if (x<=1) return 0;
    bool result = 0;
    for (int i=2; i*i <= x; ++i){
        if (x % i == 0) return 0;
    }
    return 1;
}

// 8.
void getNumber(double &x){
    cout << "Введіть число з діапазону [-1000, 1000]: ";
    while(!(cin >> x) || x < -1000 || x > 1000){
        if (cin.fail()){
            cout << "Введено не число. Спробуйте ще раз: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            cout << "Число не належить діапазону [-1000, 1000]. Спробуйте ще раз: ";
        }
    }
}

int main(){
    // 3.
    // long long x;
    // cout << "Введіть ціле число х (|x| < 10^18): ";
    // cin >> x;
    // cout << inverseNumber(x) << endl;

    // 4.
    // double a, b;
    // long long delta = 5000000;
    // cout << "Введіть відрізок [a, b]: ";
    // cin >> a >> b;
    // cout << maxFunc(a, b, delta) << endl;

    // 5.
    // long long x;
    // cout << "Введіть ціле число х: ";
    // cin >> x;
    // cout << maxY_a(x) << endl;
    // cout << maxY_b(x) << endl;
    // cout << maxY_c(x) << endl;

    // 6.
    // int x;
    // cout << "Введіть число: ";
    // cin >> x;
    // if(checkPrimeNum(x)){
    //     cout << "Число є простим";
    // } else{
    //     cout << "Число не є простим";
    // }

    // 8.
    // double x;
    // getNumber(x);

    // 9.
    // int n; 
    // int positive_n = 0; 
    // int negative_n = 0;
    // cout << "Введіть послідовність чисел, закінчивши її нулем: ";
    // do {
    //     cin >> n;
    //     if (n > 0) positive_n++;
    //     else if (n < 0) negative_n++;
    // } while (n != 0);
    // cout << positive_n << " " << negative_n << endl;

    return 0;
}