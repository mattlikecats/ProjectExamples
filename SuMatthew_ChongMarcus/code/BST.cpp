#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "BST.hpp"

using namespace std;

BSTNode* BST:: createNode(int data)
{
    BSTNode* newNode = new BSTNode;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void deleteTree(BSTNode *Node)
{
    if (Node == NULL) return;

    deleteTree(Node->left);
    deleteTree(Node->right);
  
    delete Node;
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
    deleteTree(root);
}

void inorder(BSTNode* root)
{
  if (root != NULL)
  {
    inorder(root->left);
    cout << root->key << " ->" << endl;
    inorder(root->right);
  }
}

void BST::display()
{
   if (root == NULL)
   {
     cout << "Tree is Empty. Cannot print" << endl;
   }

   else
   {
     inorder(root);
   }
}

BSTNode* BST:: addNodeHelper(BSTNode* currNode, int data) //sourced from rec 8
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}

void BST::insert(int key) //sourced from rec 8 as add
{
    root = addNodeHelper(root, key);
}

BSTNode* searchHelper(BSTNode* root, int key)
{
  if (root == NULL || root->key == key)
  {
    return root;
  }

  if (root->key < key)
  {
    return searchHelper(root->right, key);
  }

  else
  {
    return searchHelper(root->left, key);
  }

}

BSTNode* BST::search(int key)
{
    if (root != NULL)
    {
        BSTNode* x = searchHelper(root, key);

        if(x != NULL)
        {
            return x;
        }

        else
        {
          cout << "false" << endl;
            return NULL;
        }
    }
}

int BST::randSearch(int count, int testData[], float se[])
{
  using namespace std::chrono;
	
	auto start = steady_clock::now();

  for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
  {
    search(testData[rand() % count]); 
    //random positions of testData bounded by the current count
  }

  // this_thread::sleep_for (seconds(2));
	// sleep(2);

	auto end = steady_clock::now();

  se[(count-100)/100] = duration_cast<nanoseconds>(end - start).count()/100;
  //-100 because count is incremented by one position after +100 new, scales
  //position value to be the same as the previous value during insert

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

    //  TODO ** insert either micro or nanosecond time values into float search **

}

BSTNode* BST::expBSTInsert(int testData[], float in[], int count)
{  //given as a starting prev for insert

  using namespace std::chrono;

	auto start = steady_clock::now();
  
  for (int i = count; i < count+100; i++) //count should equal 0 to start, hence count+100
  {
    insert(testData[i]); //inserts 
  }

	auto end = steady_clock::now();
  float total = duration_cast<nanoseconds>(end - start).count();
  in[count/100] = total/100;

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

    //count for insert is count/100  
}