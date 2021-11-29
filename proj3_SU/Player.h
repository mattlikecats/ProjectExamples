#include <iostream>
#include <string>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"



class Player //might instead use another class player
{
    public:
    Player();
    Player(string playername, double a, double h, double l);
    void setName(string playername);
    string getName();
    void setWarrior(); //all around
    void setBeserker(); //+atk -hp
    void setCrusader(); // -atk +hp
    void setAttack(double a);
    //increase slightly by a certain percentage every level-up
    void setHealth(double h);
    //increases by a certain percentage during every level-up
    double getAttack();
    double getHealth();
    int getLevel();
    int levelUp(int increase);
    string getClass();
    
    //addition item function tbd
    
    
    private:
    string classselect;
    string name;
    double attack;
    double health;
    int level;
    int exp;
    
    
};

#endif