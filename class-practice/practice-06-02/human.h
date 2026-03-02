#pragma once
using std::string;

struct Human{
    int age;
    int energy;
    string name;
    bool lifeStatus = true;

    static const int EATENERGY = 7;
    static const int GOODSLEEP = 10;
    static const int BADSLEEP = 5;
    static const int ENERGYAFWORK = 10;
    
    void humanStatus();
    void sleep(int sleeph);
    void eat();
    void work();

    Human(int age, int energy);
    Human(int age, int energy, string name);
};