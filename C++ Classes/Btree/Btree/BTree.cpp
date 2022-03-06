#pragma once

//#include "stdafx.h"

#include<iostream>
#include "Btree.h"
#include "BTreeNode.h"

// The main function that inserts a new key in this B-Tree
void BTree::insert(int k) {
	if (root == NULL) {
		root = new BTreeNode(t, true);
		root->keys[0] = k;  // Insert key
		root->n = 1;  // Update number of keys in root
	}
	else {
		// If root is full, then tree grows in height
		if (root->n == 2 * t - 1) {
			BTreeNode *s = new BTreeNode(t, false);
			s->C[0] = root; // set old root as child of new root
							// split the old root and move 1 key to the new root
			s->splitChild(0, root);
			// new root has 2 children.  
			//Decide which of the 2 children is going to have new key!
			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);
			// Change root
			root = s;
		}
		else  // root is not full, call insertNonFull for root
			root->insertNonFull(k);
	}
}

void BTree::remove(int k) {
	if (!root) {
		cout << "The tree is empty.\n";
		return;
	}
	// Call the remove function for root
	root->remove(k);
	// if the root node has 0 keys --> its 1st child as the new root if it has a child
	// otherwise set root as NULL
	if (root->n == 0) {
		BTreeNode *tmp = root;
		if (root->leaf)
			root = NULL;
		else
			root = root->C[0];
		delete tmp; // free old root
	}
	return;
}