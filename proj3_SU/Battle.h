#include <string>

using namespace std;
#ifndef BATTLE_H
#define BATTLE_H
#include "Battle.h"

class Battle
{
    public:
    Battle();
    // Battle(double a, double h);
    int monsterselect(double a, double h);
    // double battleSpider(double h);
    
    private:
    int expdrop;
    double health;
    double attack;
    double monsterhp;
    string monster[50];

};

#endif