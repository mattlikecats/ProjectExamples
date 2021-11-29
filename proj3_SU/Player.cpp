#include "Player.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
Player :: Player()
{
 attack = 0.0;
 health = 0.0;
 level = 0.0;
}

Player :: Player(string playername,double a, double h, double l)
{
 name = playername;
 attack = a;
 health = h;
 level = l;
}

void Player::setName(string playername)
{
 name = playername;
}

string Player :: getName()
{
 return name;
}


void Player:: setWarrior()
{
 //all around stats (tbd)
 health = 30.0;
 attack = 10.0;
 level = 0;
 classselect = "Warrior";
}

void Player :: setBeserker()
{
 attack = 15.0;  
 health = 25.0;
 level = 0;
 classselect = "Beserker";
}

void Player:: setCrusader()
{
 attack = 5.0;
 health = 40.0;
 level = 0;
 classselect = "Crusader";
}

void Player:: setAttack(double a)
{
 attack = attack + a;
}

double Player :: getAttack()
{
 return attack;
}

void Player:: setHealth(double h)
{
 health = health + h;
}

double Player :: getHealth()
{
 return health;
}

int Player :: getLevel()
{
 return level;
}

int Player :: levelUp(int increase) //uses the return value to show level up or not
{
 exp = exp + increase;
 int templevel = exp / 10;
 if (templevel > level) 
 {
  level = templevel;
  return 1;
 }
 else
 {
  return 0;
 }
}

string Player :: getClass()
{
 return classselect;
}