#include <iostream>
#include <format>
#include "basket.h"

Basket::Basket(bool hasWatermelon, bool hasMelon){
    this -> hasWatermelon = hasWatermelon;
    this -> hasMelon = hasMelon;
};

bool Basket::put_watermelon(){
    if (hasMelon) return false;
    hasWatermelon = true;
    return true;
}

bool Basket::put_melon(){
    if (hasWatermelon) return false;
    hasMelon = true;
    return true;
}

void Basket::print_basket(){
    if (hasMelon) std::cout << "Basket with Melon\n";
    else if (hasWatermelon) std::cout << "Basket with Watermelon\n";
    else std::cout << "Empty basket\n";
}

void unload5(Basket b[]){
    std::cout << "Unloading...\n";

    int unloadedMelons = 0;
    int unloadedWatermelons = 0;

    for (int i=0; i<5; i++){
        std::cout << std::format("{}: ", i+1);
        b[i].print_basket();
        if (b[i].hasMelon){
            b[i].hasMelon = false;
            unloadedMelons++;
        }
        else if (b[i].hasWatermelon){
            b[i].hasWatermelon = false;
            unloadedWatermelons++;
        }
    }

    std::cout << std::format("Unloaded {} Watermelons and {} Melons\n", unloadedWatermelons, unloadedMelons);
}