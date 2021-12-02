#ifndef SEARCH_ENGINE_AVLNODE_H
#define SEARCH_ENGINE_AVLNODE_H
#include <string>
using namespace std;

class AvlNode {
	public:
		string element;
		AvlNode *left;
		AvlNode *right;
		int height;

		AvlNode(string& theElement);
};

#endif //SEARCH_ENGINE_AVLNODE_H
