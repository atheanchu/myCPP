#include "bst_node.h"
#include <iostream>

using namespace std;

class BST
{
private:
	BSTNode *root;

public:
	BST();

	void Insert(int key);
	BSTNode *Insert(BSTNode *node, int key);

	void PrintTreeInOrder();
	void PrintTreeInOrder(BSTNode *node);

	bool Search(int key);
	BSTNode *Search(BSTNode *node, int Key);

	int FindMin();
	int FindMax();
	int FindMin(BSTNode *node);	
	int FindMax(BSTNode *node);

	int Successor(int key);
	int Successor(BSTNode *node);

	int Predecessor(int key);
	int Predecessor(BSTNode *node);

	void Remove(int key);
	BSTNode *Remove(BSTNode *node, int key);
};

BST::BST()
{
	root = NULL;
}

void BST::Insert(int key)
{
	this->root = Insert(this->root, key);
}

BSTNode *BST::Insert(BSTNode *node, int key)
{
	// we've reached a leaf node (or this is a root of a empty tree)
	if (node == NULL)
		node = new BSTNode(key);

	else if (key < node->Key)
	{
		node->Left = Insert(node->Left, key);
		node->Left->Parent = node;
	}
	else
	{
		node->Right = Insert(node->Right, key);
		node->Right->Parent = node;
	}

	return node;
}

void BST::PrintTreeInOrder()
{
	PrintTreeInOrder(this->root);
	cout << endl;
}

void BST::PrintTreeInOrder(BSTNode *node)
{
	if (node == NULL)
		return;

	if (node->Left != NULL)
		PrintTreeInOrder(node->Left);
	cout << node->Key << " ";
	if (node->Right != NULL)
		PrintTreeInOrder(node->Right);
}

bool BST::Search(int key)
{
	return Search(this->root, key) == NULL;
}

BSTNode *BST::Search(BSTNode *node, int key)
{
	// we've reached the leaf node without finding the key
	if (node == NULL)
		return NULL;
	// found the match!
	else if (node->Key == key)
		return node;
	else if (key < node->Key)
		return Search(node->Left, key);
	else
		return Search(node->Right, key);
}

int BST::FindMin()
{
	return FindMin(this->root);
}

int BST::FindMax()
{
	return FindMax(this->root);
}

int BST::FindMin(BSTNode *node)
{
	if (node == NULL)
	{
		return -1;
	}
	else if (node->Left == NULL)
	{
		return node->Key;
	}
	else
	{
		return FindMin(node->Left);
	}
}

int BST::FindMax(BSTNode *node)
{
	if (node == NULL)
	{
		return -1;
	}
	else if (node->Right == NULL)
	{
		return node->Key;
	}
	else
	{
		return FindMax(node->Right);
	}
}

int BST::Successor(int key) {
	// get the node for the key 
	BSTNode *keyNode = Search(this->root, key);

	// return -1 if the key is not found in this tree.
	return keyNode == NULL ? -1 : Successor(keyNode);
}

int BST::Successor(BSTNode * node) {

	// if node has a right subtree, find the minimum from it
	if(node->Right != NULL) {
		return FindMin(node->Right);
	}
	// if currentNode is not root and currentNode is its right, move up
	BSTNode * parentNode = node;
	BSTNode * currentNode = node;
	while(parentNode != NULL && currentNode == parentNode->Right) {
		currentNode = parentNode;
		parentNode =currentNode->Parent;
	}

	return parentNode == NULL ? -1 : parentNode->Key;
}

int BST::Predecessor(int key) {
	// get the node for the key 
	BSTNode *keyNode = Search(this->root, key);

	// return -1 if the key is not found in this tree.
	return keyNode == NULL ? -1 : Successor(keyNode);
}

int BST::Predecessor(BSTNode * node) {

	// if node has a right subtree, find the minimum from it
	if(node->Left != NULL) {
		return FindMax(node->Left);
	}
	// if currentNode is not root and currentNode is its right, move up
	BSTNode * parentNode = node;
	BSTNode * currentNode = node;
	while(parentNode != NULL && currentNode == parentNode->Left) {
		currentNode = parentNode;
		parentNode =currentNode->Parent;
	}

	return parentNode == NULL ? -1 : parentNode->Key;
}

void BST::Remove(int key) {
	this->root = Remove(this->root, key);
}

BSTNode *BST::Remove(BSTNode *node, int key) {
	// we found the node 
	if(node->Key == key) {
		// 1. the node has no child 
		if(node->Left == NULL && node->Right == NULL) 
		{
			// we can safely remove this node 
			node = NULL;
		}
		// 2. the node has one left child
		else if(node->Left != NULL && node->Right == NULL)
		{
			// Replace this node with its children
			node->Left->Parent = node->Parent;
			// bypass node 
			node = node->Left;
		}
		// 3. the node has one right child
		else if(node->Left == NULL && node->Right != NULL)
		{
			// Replace this node with its children
			node->Right->Parent = node->Parent;
			// bypass node 
			node = node->Right;
		} 
		// 4. the node has 2 children
		else 
		{
			// get the successor of this node 
			int myMin = FindMin(node->Right);
			// remove the successor 
			Remove(node->Right, myMin);
			// set the current key with myMin
			node->Key = myMin;
		}
	}
	else if(key < node->Key) 
	{
		node->Left = Remove(node->Left, key);
	}
	else
	{
		node->Right = Remove(node->Right, key);
	}

	return node;
}