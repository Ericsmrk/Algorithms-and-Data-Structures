// CSci 115 --Lab 7
// Implementation of a AVL Tree Class
// Eric Smrkovsky
// 4/2/2021
#pragma once

struct AVLTreeNode{
	int data, balance;
	AVLTreeNode* left, * right, * parent;
	//with data and parent info
	AVLTreeNode(int d, AVLTreeNode* p) : data(d), left(nullptr),
		right(nullptr), parent(p), balance(0) {};
	//with data info only
	AVLTreeNode(int d) : data(d), left(nullptr),
		right(nullptr), parent(nullptr), balance(0) {};
	//with no info
	AVLTreeNode() : data(0), left(nullptr),
		right(nullptr), parent(nullptr), balance(0) {};
};

class AVLTree
{
public:
	
	AVLTree();
	~AVLTree();

	//Utility Functions
	int GetMaxDepth();
	void DisplayTree();
	void DisplayBalance();
	void Insert(int);
	void Delete(int data);

private:
	AVLTreeNode* treeRoot;

	void DestroyTree(AVLTreeNode* root);
	int Height(AVLTreeNode* root);
	void SetBalance(AVLTreeNode* root);
	void PrintNodeBalance(AVLTreeNode* root);
	int GetMaxDepthH(AVLTreeNode* root);
	void PrintLevel(AVLTreeNode* root, int level);
	void InsertNode(AVLTreeNode*& root, AVLTreeNode* parent, int data);
	void Rebalance(AVLTreeNode* root);
	AVLTreeNode* Rotate(AVLTreeNode* root);
	AVLTreeNode* RotateLeft(AVLTreeNode* root);
	AVLTreeNode* RotateRight(AVLTreeNode* root);
	AVLTreeNode* RotateLeftThenRight(AVLTreeNode* root);
	AVLTreeNode* RotateRightThenLeft(AVLTreeNode* root);
	AVLTreeNode* DeleteNode(AVLTreeNode* root, int data);
	AVLTreeNode* FindMinNode(AVLTreeNode* root);
};