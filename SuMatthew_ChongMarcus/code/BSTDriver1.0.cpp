#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"
#include "BST.hpp"
#include "Hash.hpp"

using namespace std;

int getWordCount(string input, char delim) // Used to determine if there was only 1 word in the string, like #5 but more flexable because static ' ' was replaced with the delim char.
{
    if (input == "") // Simple if statement to check for no input and returns 0
    {
        return 0;
    }
    int counter = 1; // 2. Counter determines word count, matters if counter is either 1 or > 1.
    
    for (int i =0; i< input.length();i++)
    {
        
        if( input[i] == delim)
        {
            counter ++;
        }
        else
        {
            continue;
        }
    }
    
    return counter;
    
}

int split(string str, char delim, string arr[], int len)
{
    string temp; //temp string used to store rotation strings generated by the for loop;
    int place = 0;
    int spaces = 1;
    
    int wordcount = getWordCount(str,delim); // 3. wordcount is used in the consecutive elseif statement to determine the case that the string is only one word without delimitors. 
    if(str == "")
    {
        return 0;
    }
    else if (wordcount == 1)
    {
        arr[0] = str; // 3a. returns arr[0] as the string if elseif condition is met, does not follow through program.
        return spaces;
    }
    else // 4. else statement runs through multiple if and if/else statements to determine many things;
    {
        if(str[0] == delim) // 4a. if the string starts with a delim, removes it from string
        {
            str = str.substr(1, str.length()-1);
        }
        if(str[str.length()-1] != delim) // 4b. if the last char of the string isn't a delim, add one (helps program find end later)
        {
            str = str + delim;
        }
        for (int i = 0; i < str.length(); i++) // 5. for loop designed to traverese the length of the string and run multiple if and if/else statements;
        {
            if((str[i] == delim) && (i != str.length()-1)) // 5a. main if statement that determines when the string should be cut and stored in the array, moves counter variable "spaces" and elevator variable "place". Temp is reset to nothing.
            {
                if(str[i] == str[i+1]) // 5b. IMPORTANT IF STATEMENT WITHIN THIS STATEMENT THAT RECOGNIZES MULTIPLE DELIM CHARS NEXT TO EACH OTHER AND SKIP THE BREAK PROCEDURE ONCE
                {
                    continue;
                }
                arr[place] = temp;
                spaces++;
                place++;
                temp = "";
                
            }
            else if((str[i] != delim)) // 5c. adds the currently compared str[] value to a temp varaible "temp" that store the string until the if statement activation above it.
            {
                temp = temp+str[i];
            }
            else // 5d. else statement ends the loop when the main if statement recognizes that the last added or kept delim exsists, ending the function.  
            {
                arr[place] = temp;
                break;
            }
        }
        return spaces;
    }
}

void fillData(string filename, int testData[])
{
    ifstream link;
    link.open(filename);
    if(link.is_open())
    {
        string line;
        int count;
        while(getline(link,line,',') && count < 40000)
        {
            testData[count] = stoi(line);
            count++;
        }
    }
    else
    {
        cout << "Failed!" << endl;
        return;
    }
    
    link.close();
}

int main()

{
    BST tree;
    int countA = 0;
    int countB = 0;

    int testDataA[40000];
    float insertA[400];
    float searchA[400];

    int testDataB[40000];
    float insertB[400];
    float searchB[400];

    string A = "dataSetA.csv";
    string B = "dataSetB.csv";

    fillData(A, testDataA);
    fillData(B, testDataB); //fills the data array
    
    for(int i = 0; i < 400; i++)
    {
        tree.expBSTInsert(testDataA, insertA, countA);
        countA = countA + 100;
        tree.randSearch(countA, testDataA, searchA);
    }
    
    for(int y = 0; y < 400; y++)
    {
        tree.expBSTInsert(testDataB, insertB, countB);
        countB = countB + 100;
        tree.randSearch(countB, testDataB, searchB);
    }

    ofstream out_file;
    out_file.open("BST_insert_A.txt");

    for (int i = 0; i < 400; i++)
    {
        out_file << insertA[i] << endl;
    }

    out_file.close();

    ofstream out_file2;
    out_file2.open("BST_search_A.txt");
    for (int i = 0; i < 400; i++)
    {
        out_file2 << searchA[i] << endl;
    }

     out_file2.close();

    ofstream out_file3;
    out_file3.open("BST_insert_B.txt");
    for (int i = 0; i < 400; i++)
    {
        out_file3 << insertB[i] << endl;
    }

     out_file3.close();

    ofstream out_file4;
    out_file4.open("BST_search_B.txt");
    for (int i = 0; i < 400; i++)
    {
        out_file4 << searchB[i] << endl;
    }

    out_file4.close();
    
}