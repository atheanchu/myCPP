#include <iostream>

class BSTNode {
public:
	int Key;
	BSTNode *Left;
	BSTNode *Right;
	BSTNode *Parent;
	int Height;

	BSTNode(int key);
};

BSTNode::BSTNode(int key) {
	this->Key = key;
	this->Left = NULL;
	this->Right = NULL;
	this->Parent = NULL;
}