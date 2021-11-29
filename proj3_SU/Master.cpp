#include <iostream>
#include <string>
#include <fstream>
#include "Master.h"

using namespace std;

Master :: Master() //place map function into consructor
{
    ifstream map_file;
    string seg;
    map_file.open("dungeon.txt");
    int counter = 0;
    
    while (getline(map_file, seg) && (counter < 7))
    {
            for (int l = 0; l < 16; l++)
            {
                map[counter][l] = seg[l];
                
            }
		counter ++;
    }
    
    turncount = 0;
    x = 3;
    y = 0;
}

void Master :: printMap()
{
    for (int i = 0; i < 7; i++)
        {
            for (int j= 0; j < 16; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }
}

int Master :: turn()
{
    turncount ++;
        for (int k = 0; k < 7; k++)
        {
            for (int l = 0; l < 16; l++)
            {
                cout << map[k][l];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << "Turn " << turncount << endl;
        cout << "" << endl;
        
        int stop = 0;
        int input;
    
    while(stop == 0)
    {
        int option = 0;

        cout << "The following movement options are avaliable: " << endl;
        cout << "" << endl;
        
        if(map[x][y+1] == "-")
        {
            cout << "1. Move forward 1." << endl;
            option = 1;
        }
        if(map[x+1][y] == "-")
        {
            cout << "2. Move to the right 1." << endl;
            option = option + 3;
        }
        if(map[x-1][y] == "-")
        {
            cout << "3. Move to the left 1." << endl;
            option = option + 5;
        }
        
        
        
        
    
    cin >> input;
    cout << endl;
    
    if (option == 1)
    {
        if (input != 1)
        {
            cout << "Invalid option" << endl;
        }
        else 
        {
            stop ++;
        }
    }
    else if(option == 4)
    {
        if ((input != 1) && (input != 2))
        {
            cout << "Invalid option" << endl;
        }
        else
        {
            stop ++;
        }
    }
    else if(option == 6)
    {
        if((input != 1) && (input !=3))
        {
            cout << "Invalid option" << endl;
        }
        else 
        {
            stop ++;
        }
    }
    else if(option == 9)
    {
        if((input > 3) && (input < 0))
        {
            cout << "Invalid option" << endl;
        }
        else
        {
            stop++;
        }
    }
    else if(option == 8)
    {
        if((input != 2) && (input !=3))
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            stop++;
        }
    }
    else if(option == 5)
    {
        if((input != 3))
        {
            cout << "Invalid input" << endl;
            
        }
        else
        {
            stop++;
        }

    }
    else if(option == 3)
    {
        if(input != 2)
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            stop++;
        }
    }
    
    }
    
    return input;
    
     
}

int Master :: position(int input)
{
    
    map[x][y] = "-";
    if (input == 1)
    {
        y++;
        map[x][y] = "H";
        
    }
    else if(input == 2)
    {
        x++;
        map[x][y] = "H";
    }
    else if(input == 3)
    {
        x--;
        map[x][y] = "H";
    }

    
    
    
}
int Master :: getTurncount()
{
    return turncount;
}

// int Master :: checkEnd()
// {
//     int end;
    
//     if ((x == 3) && (y == 15))
//     {
//         end =  3;
//     }
        
//     if((x == 5) && (y == 15))
//     {
//         end = 123;
//     }
    
    


int Master :: getx()
{
    return x;
}

int Master :: gety()
{
    return y;
}    

