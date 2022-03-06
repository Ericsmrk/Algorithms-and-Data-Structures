#pragma once

#include<iostream>
using namespace std;

class BTreeNode {
	int *keys;      // Array of keys
	int t;          // Minimum degree (defines the range for number of keys)
	BTreeNode **C;  // An array of child pointers
	int n;			// Current number of keys
	bool leaf;      // true == node is leaf
public:
	BTreeNode(int _t, bool _leaf);   // Constructor
    
	// traverse all nodes in a subtree rooted with this node
	void traverse();
	
	// search a key in subtree rooted with this node, returns NULL if k is not present
	BTreeNode *search(int k);
	
	// returns the index of the first key >= k
	int findKey(int k);
	
	// insert a new key in the subtree rooted with this node
	// the node must be non-full when insertNonFull is called
	void insertNonFull(int k);
	
	// split the child y of this node. i= index of y in child array C[].  child y must be full when splitchild is called
	void splitChild(int i, BTreeNode *y);
	
	// remove the key k in subtree rooted with this node
	void remove(int k);
	
	// remove the key present in idx-th position in this node which is a leaf
	void removeFromLeaf(int idx);
	
	// remove the key present in idx-th position in this node which is a non-leaf node
	void removeFromNonLeaf(int idx);
	
	// get the predecessor of the key present in the idx-th position in the node
	int getPred(int idx);
	
	// get the successor of the key present in the idx-th position in the node
	int getSucc(int idx);
	
	// fill up the child node present in the idx-th position in the C[] array if that child has less than t-1 keys
	void fill(int idx);
	
	// borrow a key from the C[idx-1]-th node and place it in C[idx]th node
	void borrowFromPrev(int idx);
	
	// borrow a key from the C[idx+1]-th node and place it in C[idx]th node
	void borrowFromNext(int idx);
	
	// merge idx-th child of the node with idx+1 th child of the node
	void merge(int idx);
	
	// Set BTree friend of this --> access private members of BTreeNode in BTree methods
	friend class BTree;
};