#ifndef SEARCH_ENGINE_AVLTREE_H
#define SEARCH_ENGINE_AVLTREE_H
#include "AvlNode.h"
#include <iostream>
#include <dirent.h>
#include <vector>
using namespace std;

class AvlTree{
private:
	void insert(string& data, AvlNode*& rootNode);
    bool search(string& word, AvlNode*& rootNode);
    int size;

public:
    AvlNode* root;

    //CONSTRUCTORS AND DESTRUCTORS
	AvlTree(); //no args constructor
	AvlTree(const AvlTree& newTree); //copy constructor
	~AvlTree();

	//MAIN FUNCTIONS
	void insert(string& data);
	void balance(AvlNode*& rootPtr);

    void rotateWithLeftChild(AvlNode*& n2);
    void doubleWithLeftChild(AvlNode*& n3);
    void rotateWithRightChild(AvlNode*& n2);
    void doubleWithRightChild(AvlNode*& n3);

    //HELPER FUNCTIONS AND MISC
	int height(AvlNode* node);
	int max(const int& leftHeight, const int& rightHeight);
    AvlNode* getRoot();
    void print_persistent(AvlNode* rootNode, ofstream& fout);
    void read_persistent(ifstream& inputFile);
    bool search(string& word);
    void print(AvlNode* rootNode);
    void makeEmpty(AvlNode* rootNode);
    int getSize();
};

#endif //SEARCH_ENGINE_AVLTREE_H
