#ifndef PROB3_TV_H
#define PROB3_TV_H

struct TV{
    bool status = false;
    int channel = 1;
    bool setChannel(int newChannel);
    void setStatus(bool newStatus);
    void printTV();
};

#endif