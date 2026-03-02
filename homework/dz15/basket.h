#pragma once

struct Basket{
    bool hasWatermelon = false;
    bool hasMelon = false;

    Basket() = default;
    Basket(bool hasWatermelon, bool hasMelon);

    bool put_watermelon();
    bool put_melon();
    void print_basket();
};

void unload5(Basket b[]);