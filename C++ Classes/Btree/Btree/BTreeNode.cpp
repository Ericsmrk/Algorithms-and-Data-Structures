#pragma once

//#include "stdafx.h"

#include<iostream>
using namespace std;
#include "BTreeNode.h"

BTreeNode::BTreeNode(int t1, bool leaf1) {
	// copy the given minimum degree and leaf property !
	t = t1;  leaf = leaf1;
	// Allocate memory for maximum number of possible keys and child pointers
	keys = new int[2 * t - 1];
	C = new BTreeNode *[2 * t];
	n = 0; // Set  the number of keys to 0
}

// returns the index of the 1st key >= k
int BTreeNode::findKey(int k) {
	int idx = 0;
	while (idx<n && keys[idx] < k)
		++idx;
	return idx;
}

// remove the key k from the sub-tree rooted with this node
void BTreeNode::remove(int k) {
	int idx = findKey(k);
	if (idx < n && keys[idx] == k) { // k present in this node
		if (leaf)
			removeFromLeaf(idx);
		else
			removeFromNonLeaf(idx);
	}
	else {
		if (leaf) {
			cout << "The key " << k << " is does not exist.\n";
			return;
		}
		// The key to be removed is in the sub-tree rooted with this node
		// flag = whether the key is present in the sub-tree rooted with the last child of this node
		bool flag = ((idx == n) ? true : false);
		// If the child where the key is supposed to exist has less than t keys, fill that child
		if (C[idx]->n < t)
			fill(idx);
		// If the last child has been merged, must have merged with the previous child 
		// we keep going on the idx-1 th child., otherwise we go on the idx th child (now has at least t keys)
		if (flag && idx > n)
			C[idx - 1]->remove(k);
		else
			C[idx]->remove(k);
	}
	return;
}

// A function to remove the idx-th key from this node - which is a leaf node
void BTreeNode::removeFromLeaf(int idx) {
	// Move all the keys after the idx-th pos one place backward
	for (int i = idx + 1; i<n; ++i)
		keys[i - 1] = keys[i];
	// Reduce the count of keys
	n--;
	return;
}

// A function to remove the idx-th key from this node - which is a non-leaf node
void BTreeNode::removeFromNonLeaf(int idx) {
	int k = keys[idx];
	// If the child that precedes k (C[idx]) has atleast t keys,
	// find the predecessor 'pred' of k in the subtree rooted at
	// C[idx]. Replace k by pred. Recursively delete pred
	// in C[idx]
	if (C[idx]->n >= t) {
		int pred = getPred(idx);
		keys[idx] = pred;
		C[idx]->remove(pred);
	}
	// If the child C[idx] has less that t keys, examine C[idx+1].
	// If C[idx+1] has atleast t keys, find the successor 'succ' of k in
	// the subtree rooted at C[idx+1]
	// Replace k by succ
	// Recursively delete succ in C[idx+1]
	else if (C[idx + 1]->n >= t) {
		int succ = getSucc(idx);
		keys[idx] = succ;
		C[idx + 1]->remove(succ);
	}
	// If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1]
	// into C[idx]
	// Now C[idx] contains 2t-1 keys
	// Free C[idx+1] and recursively delete k from C[idx]
	else {
		merge(idx);
		C[idx]->remove(k);
	}
	return;
}

// A function to get predecessor of keys[idx]
int BTreeNode::getPred(int idx) {
	// Keep moving to the right most node until we reach a leaf
	BTreeNode *cur = C[idx];
	while (!cur->leaf)
		cur = cur->C[cur->n];
	return cur->keys[cur->n - 1]; // the last key of the leaf
}

int BTreeNode::getSucc(int idx) {
	// Keep moving the left most node starting from C[idx+1] until we reach a leaf
	BTreeNode *cur = C[idx + 1];
	while (!cur->leaf)
		cur = cur->C[0];
	return cur->keys[0]; //  the 1st key of the leaf
}

// fill child C[idx] which has less than t-1 keys
void BTreeNode::fill(int idx) {
	// If the previous child(C[idx-1]) more than t-1 keys --> borrow a key
	// from that child
	if (idx != 0 && C[idx - 1]->n >= t)
		borrowFromPrev(idx);
	// If the next child(C[idx+1]) more than t-1 keys --> borrow a key
	// from that child
	else if (idx != n && C[idx + 1]->n >= t)
		borrowFromNext(idx);
	// Merge C[idx] with its sibling
	else {
		if (idx != n) // If C[idx] == last child
			merge(idx); // merge with with its previous sibling
		else
			merge(idx - 1); // merge with its next sibling
	}
	return;
}

// borrow a key from C[idx-1] and insert it into C[idx]
void BTreeNode::borrowFromPrev(int idx) {
	BTreeNode *child = C[idx];
	BTreeNode *sibling = C[idx - 1];
	// The last key from C[idx-1] goes up to the parent and key[idx-1] 
	// from parent is inserted as the 1st key in C[idx]
	// --> the loses sibling one key and child gains one key
	// Moving all key in C[idx] one step ahead
	for (int i = child->n - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];
	// If C[idx] is not a leaf, move all its child pointers one step ahead
	if (!child->leaf) {
		for (int i = child->n; i >= 0; --i)
			child->C[i + 1] = child->C[i];
	}
	// Setting child's 1st key == to keys[idx-1] from the current node
	child->keys[0] = keys[idx - 1];
	// Moving sibling's last child as C[idx]'s 1st child
	if (!(child->leaf))
		child->C[0] = sibling->C[sibling->n];
	// Moving the key from the sibling to the parent
	// This reduces the number of keys in the sibling
	keys[idx - 1] = sibling->keys[sibling->n - 1];
	child->n += 1;
	sibling->n -= 1;
	return;
}


// borrow a key from the C[idx+1] and place it in C[idx]
void BTreeNode::borrowFromNext(int idx) {
	BTreeNode *child = C[idx];
	BTreeNode *sibling = C[idx + 1];
	// keys[idx] is inserted as the last key in C[idx]
	child->keys[(child->n)] = keys[idx];
	// Sibling's 1st child is inserted as the last child into C[idx]
	if (!(child->leaf))
		child->C[(child->n) + 1] = sibling->C[0];
	// 1st key from sibling is inserted into keys[idx]
	keys[idx] = sibling->keys[0];
	// Moving all keys in sibling one step behind
	for (int i = 1; i<sibling->n; ++i)
		sibling->keys[i - 1] = sibling->keys[i];
	// Moving the child pointers one step behind
	if (!sibling->leaf) {
		for (int i = 1; i <= sibling->n; ++i)
			sibling->C[i - 1] = sibling->C[i];
	}
	// Increasing and decreasing the key count of C[idx] and C[idx+1]
	child->n += 1;
	sibling->n -= 1;
	return;
}

// merge C[idx] with C[idx+1] C[idx+1] is freed after merging
void BTreeNode::merge(int idx) {
	BTreeNode *child = C[idx];
	BTreeNode *sibling = C[idx + 1];
	// Pulling a key from the current node and inserting it into (t-1)th position of C[idx]
	child->keys[t - 1] = keys[idx];
	// Copying the keys from C[idx+1] to C[idx] at the end
	for (int i = 0; i<sibling->n; ++i)
		child->keys[i + t] = sibling->keys[i];
	// Copying the child pointers from C[idx+1] to C[idx]
	if (!child->leaf) {
		for (int i = 0; i <= sibling->n; ++i)
			child->C[i + t] = sibling->C[i];
	}
	// Moving all keys after idx in the current node one step before -
	// to fill the gap created by moving keys[idx] to C[idx]
	for (int i = idx + 1; i<n; ++i)
		keys[i - 1] = keys[i];
	// Moving the child pointers after (idx+1) in the current node one step before
	for (int i = idx + 2; i <= n; ++i)
		C[i - 1] = C[i];
	// Updating the key count of child and the current node
	child->n += sibling->n + 1;
	n--;
	delete(sibling); // free memory occupied by sibling
	return;
}


// insert a new key in this node, the node must be non-full when insertNonFull is called
void BTreeNode::insertNonFull(int k) {
	// Initialize index as index of rightmost element
	int i = n - 1;
	// If this is a leaf node
	if (leaf == true) {
		// 1) Finds the location of new key to be inserted
		// 2) Moves all greater keys to 1 place ahead
		while (i >= 0 && keys[i] > k) {
			keys[i + 1] = keys[i];
			i--;
		}
		// Insert the new key at found location
		keys[i + 1] = k;
		n = n + 1;
	}
	else { // If this node is not leaf
		   // Find the child which is going to have the new key
		while (i >= 0 && keys[i] > k)
			i--;
		// See if the found child is full
		if (C[i + 1]->n == 2 * t - 1) {
			// If the child is full, then split it
			splitChild(i + 1, C[i + 1]);
			// After split, the middle key of C[i] goes up and
			// C[i] is splitted into 2  
			// See which of the 2 is going to have the new key
			if (keys[i + 1] < k)
				i++;
		}
		C[i + 1]->insertNonFull(k);
	}
}

// split the child y of this node (y must be full when splitChild is called)
void BTreeNode::splitChild(int i, BTreeNode *y) {
	// Create a new node which is going to store (t-1) keys of y
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;
	// Copy the last (t-1) keys of y to z
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];
	// Copy the last t children of y to z
	if (y->leaf == false) {
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}
	// Reduce the number of keys in y
	y->n = t - 1;
	// As this node is going to have a new child, create space of new child
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	// Link the new child to this node
	C[i + 1] = z;
	// A key of y will move to this node. Find location of
	// new key and move all greater keys one space ahead
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];
	// Copy the middle key of y to this node
	keys[i] = y->keys[t - 1];
	// Increment count of keys in this node
	n = n + 1;
}



// traverse all the nodes in a subtree rooted with this node
void BTreeNode::traverse() {
	// There are n keys and n+1 children, traverse through n keys and 1st n children
	int i;
	for (i = 0; i < n; i++) {
		// if not leaf then before printing key[i]
		// traverse the subtree rooted with child C[i]
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}
	if (leaf == false)
		C[i]->traverse();
}

// search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int k) {
	int i = 0;
	while (i < n && k > keys[i])
		i++;
	if (keys[i] == k)
		return this;
	if (leaf == true)
		return NULL;
	return C[i]->search(k);
}

