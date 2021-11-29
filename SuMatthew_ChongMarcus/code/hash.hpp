#ifndef HASH_HPP
#define HASH_HPP

#include <string>

//Written by Matthew
//Based off the attached hash.hpp file given for this assignment
//Matthew built the general functions
//Matthew developed the output formats for each experiment set of data and the driver for this. 
//Marcus generated the graph for the data sets. 

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class Hash
{
    private:
        int tableSize;  // No. of buckets (linked lists)

        // Pointer to an array containing buckets
        node* *table;
        int numOfcolision = 0;
        node* createNode(int key, node* next)
        {
            node* newNode = new node;
            newNode->key = key;
            newNode->next = next;
            return newNode;
        }

    public:
        Hash(int bsize);  // Constructor

        // hash function to map values to key

        unsigned int hashFunction(int key);

        // inserts a key into hash table

        void insertItem(int key); //insert function through chainedl linked list
        void insertLin(int key);  //insert with linear probing
        void insertQuad(int key); //insert with quadratic probing

        // searches for a key in the table

        node* searchItem(int key); //search function through chained linked list
        node* searchLin(int key);  //search with linear opening addresses
        node* searchQuad(int key); //search with quadratic opening addresses

        // functions used during increment calculations of time per 100 inserted or searched
        
        int randSearchC(int testData[], float seC[], int count);
        int randSearchL(int testData[], float seL[], int count);
        int randSearchQ(int testData[], float seQ[], int count);
        void next100C(int testData[], float inC[], int count); //chained
        void next100L(int testData[], float inL[], int count); //linear
        void next100Q(int testData[], float inQ[], int count); //quadratic


        

        

        
};

#endif
