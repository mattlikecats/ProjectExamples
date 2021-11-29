#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>

using namespace std;




// Inserts new node ahead of given node
void LinkedList::insert(Node* prev, int key)
{
  //if statement that checks if head node is empty
  if(head == NULL)
  {
    head = new Node;
    head->key = key;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
    Node* n = new Node;
    n->key = key;
    n->next = head;
    head = n;
  }

  else
  {
    Node* n = new Node;
    n->key = key;
    n->next = prev->next;
    prev->next = n;
  }

}

// Print the keys in your list
void LinkedList::display()
{
  Node* temp = head;

  while(temp->next != NULL)
  {
    cout<< temp->key << " -> ";
    temp = temp->next;
  }
 
  cout << temp->key << endl;

}

// returns pointer associated with given key
Node* LinkedList::search(int key) 
{
    Node* ptr = head;

    while (ptr != NULL && ptr->key != key)
    {
      ptr = ptr->next;
    }

    return ptr;
}

//change to int
Node* LinkedList :: expLinkedInsert(Node* curr, int testData[], float in[], int count)
{  //given as a starting prev for insert

  using namespace std::chrono;

	auto start = steady_clock::now();
    for (int i = count; i < count+100; i++)
    {
        insert(curr, testData[i]); //inserts 
        curr = search(testData[i]); //adapts curr to be the latest postion inserted for next loop
    }


	auto end = steady_clock::now();

  // float in represents insert
  // count for insert is count/100 
  float total = duration_cast<nanoseconds>(end - start).count();
  in[count/100] = total/100;
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

int LinkedList :: randSearch(int count, int testData[], float se[])
{
  using namespace std::chrono;

	auto start = steady_clock::now();

  for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
  {
    int random = rand() % count;
    search(testData[random]); 
    //random positions of testData bounded by the current count
  }

	auto end = steady_clock::now();

  float total = duration_cast<nanoseconds>(end - start).count();
  se[(count-100)/100] = total/100;

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
