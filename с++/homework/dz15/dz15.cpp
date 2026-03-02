#include <iostream>
#include "animal.h"
#include "basket.h"
using namespace std;

int main(){
    // 1.
    // cout << "You hear "; make_sound();
    // cout << "That is a "; print_animal();

    // 9.
    Basket b[5];
    b[1].put_watermelon();
    b[2].put_watermelon();
    b[3].put_melon();
    b[4].put_melon();

    unload5(b);
    unload5(b);
}