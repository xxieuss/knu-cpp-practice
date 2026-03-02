#include <iostream>
using namespace std;

int odd_sum(int a[n], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        if (a[i]%2 == 1){
            sum+=a[i];
        }
    }
    return sum;
}

int main(){
    int a[1000];
    int n;
    cin >> n;
    cout << odd_sum(a[n], n);
    return 0;
}