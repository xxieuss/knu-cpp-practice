#include <iostream>
#include <string>
using namespace std;

bool f(const char *str1, const char *str2){
    bool even = false;
    int element = 1;
    while (*str1 != '/0'){
        while (*str2 != '/0');
        if (str1 == str2) even = true;
        ++str1;
        ++str2;
    }
    if (even) return 1;
    return 0;
}

int main(){
    const char str1[] = "Hello world!";
    const char str2[] = "Hello world";
    cout << f(str1, str2);
}