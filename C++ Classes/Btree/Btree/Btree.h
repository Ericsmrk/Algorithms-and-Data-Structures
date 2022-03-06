#pragma once

#include<iostream>

#include "BTreeNode.h"

class BTree {
	BTreeNode *root; // Pointer to root node
	int t;           // Minimum degree
public:
	// Constructor (Initializes tree as empty)
	BTree(int _t) { root = NULL; t = _t; }
	void traverse() { if (root != NULL) root->traverse(); }
	
	// search a key in this tree
	BTreeNode* search(int k) { return (root == NULL) ? NULL : root->search(k); }
	
	// insert a new key in the B-Tree 
	void insert(int k);
	
	// remove a key in the B-Tree
	void remove(int k);
};





