#include <iostream>
#include <string>
#include "Player.h"
#include "Master.h"
#include "Item.h"
#include "Battle.h"

using namespace std;

//Most likely a couple of helper functions based around moving the player through the dungeon.

void displayIntro()
{
    cout << "   WELCOME TO DUNGEON ESCAPE" << endl;
    cout << "---------------------------------" << endl;
    cout << "PLEASE SELECT AN OPTION TO START:" << endl;
    cout << "" << endl;
    cout << "1. Start a game of DUNGEON ESCAPE" << endl;
    cout << "2. Exit the program" << endl;
}

void displayClass()
{
    cout << "" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Beserker" << endl;
    cout << "3. Crusader" << endl;
    cout << "4. Exit game now" << endl;
    cout << "" << endl;
}

int main()
{
    int classselect;
    Master game;
    Player player;
    Battle battle;
    Item item;
    
    displayIntro();
    int inorout;
    cin >> inorout;
    
    if (inorout == 1)
    {
        cout << "Please enter the name you would like to use for this round in the dungeon: " << endl;
        string playername;
        cin.ignore();
        getline(cin,playername);
        player.setName(playername);
        cout << "" << endl;
        
        cout << "Game Started!" << endl;
        cout << endl;
        cout << endl;
        cout << "You wake up in a cold stone room, your mind a blur. Chains rattle as you notice a cold wind glide into the room." << endl;
        cout << "As you come to your senses, you notice weapons and armor laided askew all around the room. " << endl;
        cout << endl;
        cout << endl;
        
        int loop = 0;
            
        while (loop == 0)
        {
            cout << "Please select a class from the following: " << endl;
            displayClass();
            cin >> classselect;
            if (classselect == 1)
            {
                player.setWarrior();
                loop = 1;
            }
            else if(classselect == 2)
            {
                player.setBeserker();
                loop = 2;
            }
            else if(classselect == 3)
            {
                player.setCrusader();
                loop = 3;
            }
            else if (classselect == 4)
            {
                cout << "Exiting game now..." << endl;
                exit(4);
            }
            else
            {
                cout << "Invalid selection try again" << endl;
                cout << "" << endl;
            }
        }
        
        cout << "You sucessfully pick up the weapons and armor of the " << player.getClass() << " and prepare to go into the dungeon that awaits." << endl;
        cout << endl;
        
        int exp= 0;
        int pos = 0;
        int re = 0;
        int end = 0 ;
        int trigger = 0;
        while(trigger != 1)
        {
            if((game.getx() == 3) && (game.gety() == 15))
            {
                ofstream outfile;
                outfile.open("save.txt");
                
                if(outfile.is_open())
                {
                    outfile << "Character name: " << player.getName() << endl;
                    outfile << "Monsters killed: " << game.getTurncount()-1 << endl;
                    outfile << "Class selection: " << player.getClass() << endl;
                    outfile << "Highest level: " << player.getLevel() << endl;
                    outfile << endl;
                }
                
                outfile.close();
                
                cout << "The opening looks promising, so you run with all your might in anticipation of freedom, but as the room closes around you, " << endl;
                cout << "you realize this was not the freedom you were looking for, as the room fills with cold, dark, unforgiving water." << endl;
                cout << "Your stats will be shown in the save.txt file for this run." << endl;
                cout << "Press enter to restart..." << endl;
                cout << endl;
            
                return main();
            
            }
            if ((game.getx() == 5) && (game.gety() == 15))
            {
                ofstream outfile;
                outfile.open("save.txt");
                
                if(outfile.is_open())
                {
                    outfile << "Character name: " << player.getName() << endl;
                    outfile << "Monsters killed: " << game.getTurncount()-1 << endl;
                    outfile << "Class selection: " << player.getClass() << endl;
                    outfile << "Highest level: " << player.getLevel() << endl;
                    outfile << endl;
                }
                
                outfile.close();
                
                cout << "You escape with your life, dropping everything to get out of the dungeon as fast as you can." << endl;
                cout << "As you turn around, your vision blurs and a demonic laughter fills your head as you collapse onto the ground." << endl;
                cout << "You realize just as your mind breaks that you were never going to escape as the chains rattle in the wind, the void watiting to take you again." << endl;
                cout << endl;
            
                cout << "Your stats will be shown in the save.txt file for this run." << endl;
                cout << "Press enter to restart..." << endl;
                cout << endl;
            
                return main();
            }
            re = game.turn();
		    pos = game.position(re);
		    double playerhealth = player.getHealth();
		    double playerattack = player.getAttack();
		    exp = battle.monsterselect(playerattack,playerhealth);
		    if(exp == 3)
            {
                ofstream outfile;
                outfile.open("save.txt");
                
                if(outfile.is_open())
                {
                    outfile << "Character name: " << player.getName() << endl;
                    outfile << "Monsters killed: " << game.getTurncount()-1 << endl;
                    outfile << "Class selection: " << player.getClass() << endl;
                    outfile << "Highest level: " << player.getLevel() << endl;
                    outfile << endl;
                }
                
                outfile.close();
                
                cout << "The dungeon can not longer heal your wonders, and you are consumed by the darkness." << endl; 
                cout << "Your stats will be shown in the save.txt file for this run." << endl;
                cout << "Press enter to restart..." << endl;
                cout << endl;
                
                
                return main();
            
            }
            else if(exp == 4)
            {
                exp = 0;
                cout << endl;
                cout << "You sucessfully escape the monster." << endl;
                cout << "Since you ran away from the battle, you gain no exp." << endl;
            }
		    
		    int buff = player.levelUp(exp);
		    
		    if (buff == 1)
		    {
		        double newattack = playerattack *0.05;
		        double newhealth = playerhealth * 0.07;
		        player.setAttack(newattack);
		        player.setHealth(newhealth);
		        
		        cout << endl;
		        cout << "Level " << player.getLevel() << " obtained!" << endl;
		    }
		    
		    double bonus = item.itemSelect();
		    if(bonus > 0)
		    {
		        player.setAttack(bonus);
		        player.setHealth(bonus);
		    }
        }
    }
    else if (inorout == 2) 
    {
        exit(2);
    }
    else
    {
        cout << "Invalid input try again." << endl;
        cout << "" << endl;
        return main();
    }
    
    
}

