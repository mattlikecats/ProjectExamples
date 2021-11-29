#include "hash.hpp"
#include <string>
#include <iostream>
#include <chrono>


using namespace std;

Hash :: Hash (int bsize)
{
    table = new node*[bsize];
    tableSize = bsize;
}

unsigned int  Hash :: hashFunction(int key)
{
    return key % tableSize; //creates indices for use in the hash function
}

void Hash :: insertItem(int key)
{
    int pos = hashFunction(key); //solves/finds positional index

    if(table[pos] != NULL) //if position is not open/NULL
    {
        node* temp = table[pos]; //retrives node at pos
        
        while(temp->next != NULL) //traverese list
        {
            temp = temp->next;
        }

        node* newnode = createNode(key, NULL); //reaches position, creates new node
        temp->next = newnode; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        node* newnode = createNode(key, NULL);
        table[pos] = newnode;
    }
}

void Hash :: insertLin(int key) //mostly same as insert
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = createNode(key, NULL);

    if(table[pos] != NULL) //if position is not open/NULL
    {
        int nextavl = pos;  
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl++;
        }

        table[hashFunction(nextavl)] = temp; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        table[pos] = temp;
    }
}

void Hash :: insertQuad(int key) //mostly same as linear
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = createNode(key, NULL);

    if(table[pos] != NULL) //if position is not open/NULL
    {
        int nextavl = pos;
        int power = 1;
        //did not trust hashFunction function, used literal calculation inside table
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl = pos + power * power; //quadratically increments pos based on power value
            power ++;
        }

        table[hashFunction(nextavl)] = temp; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        table[pos] = temp;
    }
}

node* Hash :: searchItem(int key)
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = table[pos]; //retrieves first node for pos

    while(temp != NULL) //loops to find value or end depending on what it hits first
    {
        if(temp->key == key)
        {
            return temp;
            
        }
        temp = temp->next;
    }
}

node* Hash :: searchLin(int key) //very similar to insert counterpart in terms of traversal
{
    int pos = hashFunction(key);

    if(table[pos]->key == pos) //if value is found immediatly or at all during function
    {
        return table[pos]; //returns found pointer 
    }
    else
    {
        int nextavl = pos;  
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl++;
        }

        return table[hashFunction(nextavl)]; //returns found pointer
    }
     
}

node* Hash :: searchQuad(int key) //very similar to insert counterpart in terms of traversal
{
    int pos = hashFunction(key);

    if(table[pos]-> key == pos)
    {
        return table[pos];
    }

    else
    {
        int nextavl = pos;
        int power = 1;
        //did not trust hashFunction function, used literal calculation inside table
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl = pos + power * power; //quadratically increments pos based on power value
            power ++;
        }

        return table[hashFunction(nextavl)];
    }
    
}

int Hash :: randSearchC(int testData[], float seC[], int count)
{
    using namespace std::chrono;
	
	auto start = steady_clock::now();

    for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
    {
        searchItem(testData[rand() % count]); 
        //random positions of testData bounded by the current count
    }

	auto end = steady_clock::now();

    seC[count/100] = duration_cast<nanoseconds>(end - start).count()/100;

    // output (comment out later)

//   cout << "Elapsed time in nanoseconds : " 
// 		<< duration_cast<nanoseconds>(end - start).count()
// 		<< " ns" << endl;

// 	cout << "Elapsed time in microseconds : " 
// 		<< duration_cast<microseconds>(end - start).count()
// 		<< " µs" << endl;

// 	cout << "Elapsed time in milliseconds : " 
// 		<< duration_cast<milliseconds>(end - start).count()
// 		<< " ms" << endl;

// 	cout << "Elapsed time in seconds : " 
// 		<< duration_cast<seconds>(end - start).count()
// 		<< " sec" << endl;

}

int Hash :: randSearchL(int testData[], float seL[], int count)
{
    using namespace std::chrono;
	
	auto start = steady_clock::now();

    for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
    {
        searchItem(testData[rand() % count]); 
        //random positions of testData bounded by the current count
    }

	auto end = steady_clock::now();

    seL[count/100] = duration_cast<nanoseconds>(end - start).count()/100;

    // output (comment out later)

//   cout << "Elapsed time in nanoseconds : " 
// 		<< duration_cast<nanoseconds>(end - start).count()
// 		<< " ns" << endl;

// 	cout << "Elapsed time in microseconds : " 
// 		<< duration_cast<microseconds>(end - start).count()
// 		<< " µs" << endl;

// 	cout << "Elapsed time in milliseconds : " 
// 		<< duration_cast<milliseconds>(end - start).count()
// 		<< " ms" << endl;

// 	cout << "Elapsed time in seconds : " 
// 		<< duration_cast<seconds>(end - start).count()
// 		<< " sec" << endl;

}

int Hash :: randSearchQ(int testData[], float seQ[], int count)
{
    using namespace std::chrono;
	
	auto start = steady_clock::now();

    for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
    {
        searchItem(testData[rand() % count]); 
        //random positions of testData bounded by the current count
    }

	auto end = steady_clock::now();

    seQ[count/100] = duration_cast<nanoseconds>(end - start).count()/100;

    // output (comment out later)

//   cout << "Elapsed time in nanoseconds : " 
// 		<< duration_cast<nanoseconds>(end - start).count()
// 		<< " ns" << endl;

// 	cout << "Elapsed time in microseconds : " 
// 		<< duration_cast<microseconds>(end - start).count()
// 		<< " µs" << endl;

// 	cout << "Elapsed time in milliseconds : " 
// 		<< duration_cast<milliseconds>(end - start).count()
// 		<< " ms" << endl;

// 	cout << "Elapsed time in seconds : " 
// 		<< duration_cast<seconds>(end - start).count()
// 		<< " sec" << endl;

}



void Hash :: next100C(int testData[], float inC[], int count)
{
    using namespace std::chrono;

	auto start = steady_clock::now();

    for (int i = count; i < count + 100; i++) 
    {
        insertItem(testData[i]);    
    }

    auto end = steady_clock::now();

  // float in represents insert
  // count for insert is count/100 
    float total = duration_cast<nanoseconds>(end - start).count();
    inC[count/100] = total/100;

//   output (comment out later)

    // cout << "Elapsed time in nanoseconds : " 
	// 	<< duration_cast<nanoseconds>(end - start).count()
	// 	<< " ns" << endl;

	// cout << "Elapsed time in microseconds : " 
	// 	<< duration_cast<microseconds>(end - start).count()
	// 	<< " µs" << endl;

	// cout << "Elapsed time in milliseconds : " 
	// 	<< duration_cast<milliseconds>(end - start).count()
	// 	<< " ms" << endl;

	// cout << "Elapsed time in seconds : " 
	// 	<< duration_cast<seconds>(end - start).count()
	// 	<< " sec" << endl;

}

void Hash :: next100L(int testData[], float inL[], int count)
{
    using namespace std::chrono;

	auto start = steady_clock::now();

    for (int i = count; i < count + 100; i++) 
    {
        insertItem(testData[i]);    
    }

    auto end = steady_clock::now();

  // float in represents insert
  // count for insert is count/100 
    float total = duration_cast<nanoseconds>(end - start).count();
    inL[count/100] = total/100;

  // output (comment out later)

//   cout << "Elapsed time in nanoseconds : " 
// 		<< duration_cast<nanoseconds>(end - start).count()
// 		<< " ns" << endl;

// 	cout << "Elapsed time in microseconds : " 
// 		<< duration_cast<microseconds>(end - start).count()
// 		<< " µs" << endl;

// 	cout << "Elapsed time in milliseconds : " 
// 		<< duration_cast<milliseconds>(end - start).count()
// 		<< " ms" << endl;

// 	cout << "Elapsed time in seconds : " 
// 		<< duration_cast<seconds>(end - start).count()
// 		<< " sec"<<endl;

}

void Hash :: next100Q(int testData[], float inQ[], int count)
{
    using namespace std::chrono;

	auto start = steady_clock::now();

    for (int i = count; i < count + 100; i++) 
    {
        insertItem(testData[i]);    
    }

    auto end = steady_clock::now();

  // float in represents insert
  // count for insert is count/100 
    float total = duration_cast<nanoseconds>(end - start).count();
    inQ[count/100] = total/100;

  // output (comment out later)

  // cout << "Elapsed time in nanoseconds : " 
	// 	<< duration_cast<nanoseconds>(end - start).count()
	// 	<< " ns" << endl;

	// cout << "Elapsed time in microseconds : " 
	// 	<< duration_cast<microseconds>(end - start).count()
	// 	<< " µs" << endl;

	// cout << "Elapsed time in milliseconds : " 
	// 	<< duration_cast<milliseconds>(end - start).count()
	// 	<< " ms" << endl;

	// cout << "Elapsed time in seconds : " 
	// 	<< duration_cast<seconds>(end - start).count()
	// 	<< " sec";

}









 