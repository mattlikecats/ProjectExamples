#include <iostream>
#include <string>

// Cowritten by Marcus Chong and Matthew Su
// Matthew generated the basic class functions
// Matthew generated the time calculating parts of the functions and driver files
// Marcus generated the output method to bring the data from the float values into graphs

using namespace std;

struct BSTNode{
int key;
BSTNode* left;
BSTNode* right;
};

class BST{
    private:
        BSTNode* root;

    public:
        BST();
        BST(int key);  
        ~BST();
        BSTNode* createNode(int data);
        void display();
        void insert(int key);
        BSTNode* addNodeHelper(BSTNode*currNode, int data);
        BSTNode* search(int key);
        int randSearch(int count, int testData[], float se[]);
        BSTNode* expBSTInsert(int testData[], float in[], int count);

};
