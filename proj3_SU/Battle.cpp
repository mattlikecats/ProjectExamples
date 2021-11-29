#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include "Battle.h"

using namespace std;

void displayOption()
{
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Search for an item that could be useful" << endl;
    cout << "3. Attempt to run" << endl;
    cout << endl;
}


Battle :: Battle()
{
    ifstream monsterlist;
    monsterlist.open("monster.txt");
    string l;
    int counter = 0;
    while(getline(monsterlist,l) && (counter < 50))
    {
        monster[counter] = l;
        counter ++;
    }
}

int Battle::monsterselect(double a, double h)
{
    attack = a;
    health = h;
    
    int status = 0;
    int select = rand() % 30;
    if (monster[select] == "pp")
    {
        cout << "A massive hairy spider lands in front of you." << endl;
        cout << "" << endl;
        
        
        monsterhp = 30;
        
        do
        {
            
            displayOption();
            int input;
            cin >> input;
            
            if (input == 1)
            {
                cout << "" << endl;
                cout << "The spider spits poison that damages you 7." << endl;
                health = health-7;
                cout << health << " health remains" << endl;
                cout << "You attack for " << attack << " damage." << endl;
                monsterhp = monsterhp - attack;
                cout << monsterhp << " health remains" << endl;
            
                if (health <= 0)
                {
                    status = 3; //death trigger
                }
                else if((monsterhp <=0) && (health > 0))
                {
                
                    status = 7; 
                }
                
            }
            else if (input == 2)
            {
                int improv = rand() %30;
                for (int h = 0; h < 10; h++)
                {
                    if (input == h)
                    {
                        cout << endl;
                        cout << "You throw a rock and it stuns the enemy for a turn." << endl;
                    }
                }
                continue;
            }
            else if (input == 3)
            {
                int counter = 0; 
                int run = rand() % 30;
                for (int d = 20; d < 30; d++)
                {
                    if (d == run)
                    {
                        counter ++;
                    }
                }
                if(counter > 0)
                {
                    status = 4;
                    monsterhp = 0;
                }
                else 
                {
                    cout << "You fail to run from the spider and recieve a nasty scratch for 6 damage." << endl;
                    health = health - 6;
                    cout << health << " health remaining." << endl;
                }
            }
            
            else
            {
                cout << endl;
                cout << "Invalid input try again." << endl;
            }
        }
        while((monsterhp > 0) && (health > 0));
        
        
        if (status == 3)
        {
            return 3;
        }
        else if (status == 4)
        {
            return 4;
        }
        else
        {
            cout << "" << endl;
            cout << "You have killed the spider and have survived the encounter!" << endl; 
            cout << "You are healed by the dungeon and gain +7 exp." << endl;
            cout << "" << endl;
            return status;
        }
    }
    else if(monster[select] == "ll")
    {
        cout << "A flimsy slime scoots his way towards you." << endl;
        cout << "" << endl;
        
        
        monsterhp = 20;
        
        do
        {
            displayOption();
            int input;
            cin >> input;
            
            if (input == 1)
            {
                cout << "" << endl;
                cout << "The slime's corrosion deals 5 damage." << endl;
                health = health-5;
                cout << health << " health remains" << endl;
                cout << "You attack for " << attack << " damage." << endl;
                monsterhp = monsterhp - attack;
                cout << monsterhp << " health remains" << endl;
            
                if (health <= 0)
                {
                    status = 3; //death trigger
                }
                else if((monsterhp <=0) && (health > 0))
                {
                
                    status = 5; 
                }
            }
            
            else if (input == 2)
            {
                int improv = rand() %30;
                for (int h = 0; h < 10; h++)
                {
                    if (input == h)
                    {
                        cout << endl;
                        cout << "You hide behind a old crate and it takes the bulk of the damage." << endl;
                    }
                }
                continue;
            }
            else if (input == 3)
            {
                int counter = 0; 
                int run = rand() % 30;
                for (int d = 20; d < 30; d++)
                {
                    if (d == run)
                    {
                        counter ++;
                    }
                }
                if(counter > 0)
                {
                    status = 4;
                    monsterhp = 0;
                }
                else 
                {
                    cout <<"You failed to run away from the slime and took 4 damage." << endl;
                    health = health - 4;
                    cout << health << " health remains" << endl;
                }
            }
            
            else
            {
                cout << endl;
                cout << "Invalid input try again." << endl;
            }
            
            
        }
        while((monsterhp > 0) && (health > 0));
        
        
        if (status == 3)
        {
            return 3;
        }
        else if (status == 4)
        {
            return 4;
        }
        else
        {
            cout << "" << endl;
            cout << "You have killed the slime and have survived the encounter!" << endl; 
            cout << "You are healed by the dungeon and gain +5 exp." << endl;
            cout << "" << endl;
            return status;
        }
    }    else if(monster[select] == "kk")
    {
        cout << "A skeleton dressed in tattered rags stands up and attacks." << endl;
        cout << "" << endl;
        
        
        monsterhp = 35;
        
        do
        {
            displayOption();
            int input;
            cin >> input;
            
            if (input == 1)
            {
                cout << "" << endl;
                int var = rand() % 3;
                if(var == 0)
                {
                    cout << "The skeleton shoots an arrow and deals 9 damage." << endl;
                    health = health-9;
                }
                else if (var == 1)
                {
                    cout << "The skeleton throws its skull at you for 6 damage." << endl;
                    health = health- 6;
                }
                else if (var == 2)
                {
                    cout << "The skeleton swings its sword and hits you for 7 damage." << endl;
                    health = health - 7;
                }
                cout << health << " health remains" << endl;
            
                cout << "You attack for " << attack << " damage." << endl;
                monsterhp = monsterhp - attack;
                
                cout << monsterhp << " health remains" << endl;
            
                if (health <= 0)
                {
                    status = 3; //death trigger
                }
                else if((monsterhp <=0) && (health > 0))
                {
                    status = 10; 
                }
            }
            
        else if (input == 2)
            {
                int improv = rand() %30;
                for (int h = 0; h < 10; h++)
                {
                    if (input == h)
                    {
                        cout << endl;
                        cout << "You knock one of its limbs off and it loses interest in you as it struggles to find the lost limb in the dark." << endl;
                    }
                }
                continue;
            }
        else if (input == 3)
            {
                int counter = 0; 
                int run = rand() % 30;
                for (int d = 20; d < 30; d++)
                {
                    if (d == run)
                    {
                        counter ++;
                    }
                }
                if(counter > 0)
                {
                    status = 4;
                    monsterhp = 0;
                }
                else 
                {
                    cout << "You failed to run and the skeleton hits you for 7 damage." << endl;
                    health = health-7;
                    cout << health << " health remains" << endl;
                }
            }
            
        else
            {
                cout << endl;
                cout << "Invalid input try again." << endl;
            }
            
            
        }
        while((monsterhp > 0) && (health > 0));
        
        
        if (status == 3)
        {
            return 1;
        }
        else if (status == 4)
        {
            return 4;
        }
        else
        {
            cout << "" << endl;
            cout << "You have killed the skeleton and have survived the encounter!" << endl; 
            cout << "You are healed by the dungeon and gain +10 exp." << endl;
            cout << "" << endl;
            return status;
        }
    }
    else if(monster[select] == "cc")
    {
        cout << "A thin lady appears in the darkness. When you take a closer look," << endl; 
        cout << "she turns around to reveal her snow white skin and unleases a bloodcurling scream." << endl;
        cout << "" << endl;
        
        
        monsterhp = 50;
        
        do
        {
            displayOption();
            int input;
            cin >> input;
            
            if( input == 1)
            {
                cout << "" << endl;
                int var = rand() % 3;
                if(var == 0)
                {
                    cout << "The screamer uses her fingernails like many swords and you take 15 damage." << endl;
                    health = health-15;
                }
                else if (var == 1)
                {
                    cout << "The screamer unleashes a scream and you take 11 points of damage." << endl;
                    health = health- 11;
                }
                else if (var == 2)
                {
                    cout << "You cover your ears just in time and avoid damage." << endl;
                }
                
                cout << health << " health remains" << endl;
                cout << "You attack for " << attack << " damage." << endl;
                monsterhp = monsterhp - attack;
                cout << monsterhp << " health remains" << endl;
            
                if (health <= 0)
                {
                    status = 3; //death trigger
                }
                else if((monsterhp <=0) && (health > 0))
                {
                
                    status = 35; 
                }
            }
            
        else if (input == 2)
            {
                int improv = rand() %30;
                for (int h = 0; h < 10; h++)
                {
                    if (input == h)
                    {
                        cout << endl;
                        cout << "You throw dust into the air and the screamer chokes on it, stalling it for a second." << endl;
                    }
                }
                continue;
            }
        else if (input == 3)
            {
                int counter = 0; 
                int run = rand() % 30;
                for (int d = 20; d < 30; d++)
                {
                    if (d == run)
                    {
                        counter ++;
                    }
                }
                if(counter > 0)
                {
                    status = 4;
                    monsterhp = 0;
                }
                else 
                {
                    cout << "The screamer impeads your escape and deals 11 damage as punishment." << endl;
                    health = health - 11;
                    cout << health << " health remaining" << endl;
                }
            }
            
            else
            {
                cout << endl;
                cout << "Invalid input try again." << endl;
            }
            
            
        }
        while((monsterhp > 0) && (health > 0));
        
        if (status == 3)
        {
            return 3;
        }
        else if(status == 4)
        {
            return 4;
        }
        else
        {
            cout << "" << endl;
            cout << "You have killed the screamer and have survived the encounter!" << endl; 
            cout << "You are healed by the dungeon and gain +35 exp." << endl;
            cout << "" << endl;
            return status;
        }
    }
    cout << ""<< endl;
}
