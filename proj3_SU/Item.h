#include <iostream>
#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H
#include "Item.h"

class Item 
{

    public:
    Item();
    double itemSelect();
    
    private:
    string item[30];
    double bonus;
    
};

#endif