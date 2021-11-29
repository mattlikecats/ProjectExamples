#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef MASTER_H
#define MASTER_H
#include "Master.h"

class Master
{
    private:
    //         r  c
    string map[7][16];
    int turncount;
    int x;
    int y;
    
    public:
    Master();
    int turn();
    int position(int input);
    void printMap();
    int getTurncount();
    int getx();
    int gety();
    // int checkEnd();
};

#endif