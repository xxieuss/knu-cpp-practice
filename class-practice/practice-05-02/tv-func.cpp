#include <iostream>
#include <format>
#include "tv.h"
using namespace std;

void TV::setStatus(bool newStatus){
    TV::status = newStatus;
    printTV();
}

bool TV::setChannel(int newChannel){
    if (!status || newChannel < 1 || newChannel > 50){
        printTV();
        return false;
    }
    channel = newChannel;
    printTV();
    return true;
}

void TV::printTV(){
    if (status){
        cout << format("TV is ON. Showing channel: {}\n", channel);
    } else{
        cout << "TV is switched OFF\n";
    }
}