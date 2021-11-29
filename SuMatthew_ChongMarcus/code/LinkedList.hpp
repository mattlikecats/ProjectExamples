#include <iostream>

// Cowritten by Marcus Chong and Matthew Su
// Marcus generated the basic class functions
// Matthew generated the time calculating parts of the functions and driver files
// Both worked to get values into the float array and into the output txt file.

struct Node{
      int key;
      Node *next;
};

class LinkedList
{
  private:
    Node *head;
    // Node *prev; //keeps trak of prev after 100 cycles of expLI.

  public:
    LinkedList()
    {
    	head = NULL;
      // prev = NULL;
    }
    void insert(Node *prev, int newKey);
    Node* search(int key);
    void display();
    Node* expLinkedInsert(Node* curr, int testData[], float in[], int count);
    // Designed to take a count value and a starting node and insert 100 ints from
    // the testData array into the list class variable. Calculates time to insert and 
    // puts it into the float insert array (units tbd) 
    int randSearch(int count, int testData[], float se[]);
    // Designed to take the testData array and find random values within the first 100
    // stored variables and calculate time to complete and put into float search array (units tbd) 
};
