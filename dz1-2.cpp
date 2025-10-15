#include <iostream>
#include <string>
using namespace std;

string converter1(long long digitOctal){
    string octal = "";
    while(digitOctal>0){
        int remain = digitOctal%8;
        octal = to_string(remain) + octal;
        digitOctal /= 8;
    }
    return octal;
}

string converter2(long long digitHex){
    string hex = "";
    while(digitHex>0){
        int remain = digitHex%16;
        char digit;
        if (remain < 10) {
            digit = '0' + remain;
        } else {
            digit = 'A' + (remain - 10);
        }
        hex = digit + hex;
        digitHex /= 16;
    }
    return hex;
}

int main(){
    long long digitOctal = 16973;
    long long digitHex = 16973;
    cout << "Десяткове " << digitOctal << " в вісімкову: " << converter1(digitOctal) << endl;
    cout << "Десяткове " << digitHex << " в шістнадцяткову: " << converter2(digitHex) << endl;
}