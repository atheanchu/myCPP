#include "bst_node.h"

#include "bst_node.h"
#include <iostream>

using namespace std;

class AVL
{
private:
	BSTNode *root;

public:
	AVL();

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

	int GetHeight(BSTNode *node);
	BSTNode *RotateLeft(BSTNode *node);
	BSTNode *RotateRight(BSTNode *node);
};

AVL::AVL()
{
	root = NULL;
}

void AVL::Insert(int key)
{
	this->root = Insert(this->root, key);
}

BSTNode *AVL::Insert(BSTNode *node, int key)
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

	// get the balance
	int balance = GetHeight(node->Left) - GetHeight(node->Right);

	// left heavy
	if (balance == 2)
	{
		// get the balance of left subtree
		int balance2 = GetHeight(node->Left->Left) - GetHeight(node->Left->Right);
		// left-left : rotate right
		if (balance2 == 1)
		{
			node = RotateRight(node);
		}
		// left-right
		else
		{
			// Rotate left on left subtree
			node->Left = RotateLeft(node->Left);
			// Rotate right
			node = RotateRight(node);
		}
	}
	// right heavy
	else if (balance == -2)
	{
		// get the balance of right subtree
		int balance2 = GetHeight(node->Right->Right) - GetHeight(node->Right->Left);
		// right-right : rotate right
		if (balance2 == 1)
		{
			node = RotateLeft(node);
		}
		// left-right
		else
		{
			// Rotate left on left subtree
			node->Right = RotateRight(node->Right);
			// Rotate right
			node = RotateLeft(node);
		}
	}

	// Reset height
	node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;

	return node;
}

void AVL::PrintTreeInOrder()
{
	PrintTreeInOrder(this->root);
	cout << endl;
}

void AVL::PrintTreeInOrder(BSTNode *node)
{
	if (node == NULL)
		return;

	if (node->Left != NULL)
		PrintTreeInOrder(node->Left);
	cout << node->Key << " ";
	if (node->Right != NULL)
		PrintTreeInOrder(node->Right);
}

bool AVL::Search(int key)
{
	return Search(this->root, key) == NULL;
}

BSTNode *AVL::Search(BSTNode *node, int key)
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

int AVL::FindMin()
{
	return FindMin(this->root);
}

int AVL::FindMax()
{
	return FindMax(this->root);
}

int AVL::FindMin(BSTNode *node)
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

int AVL::FindMax(BSTNode *node)
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

int AVL::Successor(int key)
{
	// get the node for the key
	BSTNode *keyNode = Search(this->root, key);

	// return -1 if the key is not found in this tree.
	return keyNode == NULL ? -1 : Successor(keyNode);
}

int AVL::Successor(BSTNode *node)
{

	// if node has a right subtree, find the minimum from it
	if (node->Right != NULL)
	{
		return FindMin(node->Right);
	}
	// if currentNode is not root and currentNode is its right, move up
	BSTNode *parentNode = node;
	BSTNode *currentNode = node;
	while (parentNode != NULL && currentNode == parentNode->Right)
	{
		currentNode = parentNode;
		parentNode = currentNode->Parent;
	}

	return parentNode == NULL ? -1 : parentNode->Key;
}

int AVL::Predecessor(int key)
{
	// get the node for the key
	BSTNode *keyNode = Search(this->root, key);

	// return -1 if the key is not found in this tree.
	return keyNode == NULL ? -1 : Successor(keyNode);
}

int AVL::Predecessor(BSTNode *node)
{

	// if node has a right subtree, find the minimum from it
	if (node->Left != NULL)
	{
		return FindMax(node->Left);
	}
	// if currentNode is not root and currentNode is its right, move up
	BSTNode *parentNode = node;
	BSTNode *currentNode = node;
	while (parentNode != NULL && currentNode == parentNode->Left)
	{
		currentNode = parentNode;
		parentNode = currentNode->Parent;
	}

	return parentNode == NULL ? -1 : parentNode->Key;
}

void AVL::Remove(int key)
{
	this->root = Remove(this->root, key);
}

BSTNode *AVL::Remove(BSTNode *node, int key)
{
	// we found the node
	if (node->Key == key)
	{
		// 1. the node has no child
		if (node->Left == NULL && node->Right == NULL)
		{
			// we can safely remove this node
			node = NULL;
		}
		// 2. the node has one left child
		else if (node->Left != NULL && node->Right == NULL)
		{
			// Replace this node with its children
			node->Left->Parent = node->Parent;
			// bypass node
			node = node->Left;
		}
		// 3. the node has one right child
		else if (node->Left == NULL && node->Right != NULL)
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
	else if (key < node->Key)
	{
		node->Left = Remove(node->Left, key);
	}
	else
	{
		node->Right = Remove(node->Right, key);
	}

	// only perform rotation if node is not NULL
	if (node != NULL)
	{
		// get the balance
		int balance = GetHeight(node->Left) - GetHeight(node->Right);

		// left heavy
		if (balance == 2)
		{
			// get the balance of left subtree
			int balance2 = GetHeight(node->Left->Left) - GetHeight(node->Left->Right);
			// left-left : rotate right
			if (balance2 == 1)
			{
				node = RotateRight(node);
			}
			// left-right
			else
			{
				// Rotate left on left subtree
				node->Left = RotateLeft(node->Left);
				// Rotate right
				node = RotateRight(node);
			}
		}
		// right heavy
		else if (balance == -2)
		{
			// get the balance of right subtree
			int balance2 = GetHeight(node->Right->Right) - GetHeight(node->Right->Left);
			// right-right : rotate right
			if (balance2 == 1)
			{
				node = RotateLeft(node);
			}
			// left-right
			else
			{
				// Rotate left on left subtree
				node->Right = RotateRight(node->Right);
				// Rotate right
				node = RotateLeft(node);
			}
		}

		// Reset height
		node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
	}

	return node;
}

int AVL::GetHeight(BSTNode *node)
{
	return node == NULL ? -1 : node->Height;
}

BSTNode *AVL::RotateLeft(BSTNode *node)
{
	// the node must have a right child
	BSTNode *balancedNode = node->Right;
	// balancedNode will replace the current node
	balancedNode->Parent = node->Parent;
	// node will be the left child of the balancedNode
	node->Parent = balancedNode;
	// if balancedNode has a left child, it will be current node's right child
	node->Right = balancedNode->Left;
	if (balancedNode->Left != NULL)
		balancedNode->Left->Parent = node;

	// the left child of balancedNode will be the current node
	balancedNode->Left = node;

	// refresh the heights
	node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
	balancedNode->Height = std::max(GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

	return balancedNode;
}

BSTNode *AVL::RotateRight(BSTNode *node)
{
	BSTNode *balancedNode = node->Left;
	balancedNode->Parent = node->Parent;
	node->Parent = balancedNode;
	node->Left = balancedNode->Right;
	if (balancedNode->Right != NULL)
		balancedNode->Right->Parent = node;
	balancedNode->Right = node;

	// refresh the heights
	node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
	balancedNode->Height = std::max(GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

	return balancedNode;
}