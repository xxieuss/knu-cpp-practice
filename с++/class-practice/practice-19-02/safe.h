#pragma once
#include <string>
using namespace std;

class Safe{
    int money;
    string password;
    bool verify_password(const string& inputPassword);

    public:
    Safe();
    bool deposit(unsigned int amount, const string& password);
    bool withdraw(unsigned int amount, const string& password);
    void change_pass(const string& oldPass, const string& newPass);
    void check_balance(const string& password);
};