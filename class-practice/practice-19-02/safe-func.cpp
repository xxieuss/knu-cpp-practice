#include <iostream>
#include "safe.h"

Safe::Safe() : money(0), password("1234") {}

bool Safe::verify_password(const string& inputPassword){
    return inputPassword == password;
}

bool Safe::deposit(unsigned int amount, const string& password){
    if (verify_password(password)){
        money += amount;
        return true;
    }
    return false;
}

bool Safe::withdraw(unsigned int amount, const string& password){
    if (verify_password(password)){
        if (money < amount){
            std::cout << "Not enough money to withdraw" << std::endl;
            return false;
        }
        money -= amount;
        return true;
    }
    return false;
}

void Safe::change_pass(const string& oldPass, const string& newPass){
    if (verify_password(oldPass)) password = newPass;
}

void Safe::check_balance(const string& password){
    if (verify_password(password)) std::cout << "Balance: " << money << std::endl;
}