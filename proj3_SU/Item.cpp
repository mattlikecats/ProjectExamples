#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include "Item.h"

using namespace std;

Item :: Item()
{
    ifstream itemlist;
    itemlist.open("item.txt");
    string m;
    int counter = 0;
    while((getline(itemlist,m)) && (counter < 30))
    {
        item[counter] = m;
        counter ++;
    }
}

double Item :: itemSelect()
{
    cout << "" << endl;
    cout << "You look around the immediate area for anything you can use..." << endl;
    int rollchance = rand() % 10;
    if (rollchance <=6)
    {
        cout << "You found nothing" << endl;
        cout << "" << endl;
        return 0;
    }
    else
    {
        int itemroll = rand() % 30;
        string itemfound = item[itemroll];
        if(itemfound == "sa")
        {
            cout << "You found a rusty dagger. Your stats increase by 1." << endl;
            cout << "" << endl;
            return 1.0;
        }
        else if (itemfound == "sh")
        {
            cout << "You pull some extra padding off the corpse of a shirveled husk. Your stats increase by 1. " << endl;
            cout << "" << endl;
            return 1.0;
        }
        else if (itemfound == "oa")
        {
            cout << "You pick up a worn spear. Your stats increase by 2." << endl;
            cout << "" << endl;
            return 2.0;
        }
        else if(itemfound == "oh")
        {
            cout << "The gleam of a fashioned shield catches your eye. Your stats increase by 2." <<endl;
            cout << "" << endl;
            return 2.0;
        }
        else if(itemfound == "ma")
        {
            cout << "A sword laced with a unknown poison lies near a campfire. Your stats increase by 3" << endl;
            cout << "" << endl;
            return 3.0;
        }
        else if(itemfound == "mh")
        {
            cout << "Some light armor sits unused on a skeleton. You wear the pieces and increase stats by 3." << endl;
            cout << "" << endl;
            return 3.0;
        }
        else if(itemfound == "la")
        {
            cout << "The glow of a demonic weapon draws you in. You pick it up and it turns your body inside out." << endl;
            cout << "It calls your name as fire crawls around your body, enhancing every reflex and giving you strength." << endl;
            cout << "Your stats increase by 5 across the board." << endl;
            return 5.0;
        }
        else if(itemfound == "lh")
        {
            cout << "A heavenly light beckons for you to come forth. The golden light originates from a full suit of angelic armor." << endl;
            cout << "// A gift from the dungeon // you read as you put yourself into it. a sudden warmth envelopes you and envigorates you to fight on." << endl;
            cout << "You know you are being watched by someone, as your stats increase by 5 across the board." << endl;
            return 5.0;
        }
    }
}