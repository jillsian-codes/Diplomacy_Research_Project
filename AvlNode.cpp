#include "AvlNode.h"

AvlNode::AvlNode(string& theElement){
    element = theElement;
    height = 0;
    left = nullptr;
    right = nullptr;
}