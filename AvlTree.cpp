#include "AvlTree.h"
#include <fstream>
#include <cstring>
#include <string>

//CONSTRUCTORS AND DESTRUCTORS
AvlTree::AvlTree(){
    root = nullptr;
} //no arg constructor
AvlTree::AvlTree(const AvlTree& newTree) {
    root == nullptr;
    *this = newTree;
} //copy constructor
AvlTree::~AvlTree(){
    makeEmpty(root);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTIONS
void AvlTree::insert(string& data) {
    insert(data, root);
}
void AvlTree::insert(string& data, AvlNode*& rootNode){
    if(rootNode == nullptr){ //this means it's time to insert
        rootNode = new AvlNode(data);
        size++;
    }
    else if(rootNode->element < data) //element is smaller than data, insert to right
        insert(data, rootNode->right);
    else if(rootNode->element > data) //element is larger than data, insert to left
        insert(data, rootNode->left);
    else if(rootNode->element == data) { //element is same as data
        return;
    }
    balance(rootNode);
}
void AvlTree::balance(AvlNode*& rootPtr){
    if(height(rootPtr->left) - height(rootPtr->right) > 1){ //this means it's not balanced, and either case 1 or 2
        if(height(rootPtr->left->left) >= height(rootPtr->left->right)) //if left is deeper than right, must be where new value was. case 1
            rotateWithLeftChild(rootPtr);
        else //case 2
            doubleWithLeftChild(rootPtr);
    }
    else if(height(rootPtr->right) - height(rootPtr->left) > 1){ //not balances, either case 3 or 4
        if(height(rootPtr->right->left) >= height(rootPtr->right->right)) //case 3
            doubleWithRightChild(rootPtr);
        else //case 4
            rotateWithRightChild(rootPtr);
    }
    rootPtr->height = max(height(rootPtr->left), height(rootPtr->right))+ 1;
}

void AvlTree::rotateWithLeftChild(AvlNode*& n2){
    //rotate
    //k2 left and right pointers won't be nullptr, cause a newly-inserted node would never call this function
    AvlNode* n1 = n2->left;
    n2->left = n1->right;
    n1->right = n2;

    //fix heights
    n2->height = max(height(n2->left), height(n2->right)) + 1;
    n1->height = max(height(n1->left), n2->height) + 1;

    n2 = n1;
}
void AvlTree::doubleWithLeftChild(AvlNode*& n3){
    rotateWithRightChild(n3->left);
    rotateWithLeftChild(n3);
}
void AvlTree::rotateWithRightChild(AvlNode*& n2){
    //rotate
    //k2 left and right pointers won't be nullptr, cause a newly-inserted node would never call this function
    AvlNode* n1 = n2->right;
    n2->right = n1->left;
    n1->left = n2;

    //fix heights
    n2->height = max(height(n2->left), height(n2->right) + 1);
    n1->height = max(n2->height, height(n1->right) + 1);

    n2 = n1;
}
void AvlTree::doubleWithRightChild(AvlNode*& n3){
    rotateWithLeftChild(n3->right);
    rotateWithRightChild(n3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HELPER FUNCTIONS
int AvlTree::height(AvlNode* node){
    if(node == nullptr){
        return -1;
    }
    else
        return node->height;
}
/*"height" is a necessary helper function, as opposed to directly calling the variable, like the left side of this
 * equation does, *cause for trees w/ no nodes, the height is null. directly calling the height variable
 * in that case would produce a seg fault*/
int AvlTree::max(const int& leftHeight, const int& rightHeight){
    if(leftHeight > rightHeight)
        return leftHeight;
    else
        return rightHeight;
}
AvlNode* AvlTree::getRoot(){
    return root;
}
bool AvlTree::search(string& word){
    return search(word, root);
}
bool AvlTree::search(string& word, AvlNode*& rootNode){
    if(rootNode == nullptr) { //this means it wasn't found
        return false;
    }
    else if(rootNode->element < word) //element is smaller than data, search to right
        search(word, rootNode->right);
    else if(rootNode->element > word) //element is larger than data, search to left
        search(word, rootNode->left);
    else if(rootNode->element == word) { //element is same as data
        return true;
    }
}

void AvlTree::print(AvlNode* rootNode){
    if(rootNode == NULL)
        return;
    print(rootNode->left);
    cout << "Word: " << rootNode->element << endl;
    cout << endl;
    print(rootNode->right);
}

void AvlTree::makeEmpty(AvlNode* rootNode){
    if(rootNode != NULL){
        makeEmpty(rootNode->left);
        makeEmpty(rootNode->right);
        delete rootNode;
    }
    rootNode = NULL;
    size = 0;
}

int AvlTree::getSize(){return size;}