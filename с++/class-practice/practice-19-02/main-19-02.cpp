#include <iostream>
#include "safe.h"
using namespace std;

int main(){
    // prob 1
    Safe s;
    s.check_balance("1234");
    s.check_balance("4321");

    s.deposit(100, "1234");
    s.check_balance("1234");

    s.withdraw(200, "1234");
    s.check_balance("1234");
}