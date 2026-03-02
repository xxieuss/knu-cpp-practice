#include <iostream>
#include <string>
#include <format>
#include "human.h"
using namespace std;

Human::Human(int age, int energy){
    this -> age = age;
    this -> energy = energy;
    this -> name = "";
}

Human::Human(int age, int energy, string name){
    this -> age = age;
    this -> energy = energy;
    this -> name = name;
}

void Human::humanStatus(){
    if(lifeStatus) cout << format("human {}, age = {}, energy = {}\n", name, age, energy);
    else cout << format("human {} is dead, age = {}, energy = {}\n", name, age, energy);
}

void Human::sleep(int sleeph){
    if(lifeStatus){
        if(sleeph >= 8) energy += GOODSLEEP;
        else energy += BADSLEEP;
    }
}

void Human::eat(){
    if(lifeStatus){
        energy += EATENERGY;
    }
}

void Human::work(){
    if(lifeStatus){
        energy -= ENERGYAFWORK;
        if (energy <= 0) lifeStatus = false;
    }
}