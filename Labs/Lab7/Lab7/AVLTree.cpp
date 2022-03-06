// CSci 115 --Lab 7
// Implementation of a AVL Tree Class
// Eric Smrkovsky
// 4/2/2021
#include "AVLtree.h"
#include <iostream>;
using namespace std;

//constructor initializes pointer to tree as nullptr
AVLTree::AVLTree(){
	treeRoot = nullptr;
}

//destructor calls DestroyTree method
AVLTree::~AVLTree(){
	DestroyTree(treeRoot);
}

//Returns the maximum depth of the tree by calling a helper method
int AVLTree::GetMaxDepth() {
	return GetMaxDepthH(treeRoot);
}

//Returns the maximum depth of the given root
int AVLTree::GetMaxDepthH(AVLTreeNode* root){
	if (root == nullptr)
		return 0;
	else if (root->left == nullptr && root->right == nullptr)
		return 0;
	else//add one for the current level and check depth of subtrees
		return 1 + max(GetMaxDepthH(root->left),
			GetMaxDepthH(root->right));
}

//print a specific level of the tree
void AVLTree::PrintLevel(AVLTreeNode* root, int level){
	if (root != nullptr) {
		if (level == 0)
			cout << "(" << root->data << ")";
		else {
			PrintLevel(root->left, level - 1);
			PrintLevel(root->right, level - 1);
		}
	}
	else
		cout << "   ";
}

//Displays the tree in an interesting way
void AVLTree::DisplayTree(){
	int depth = GetMaxDepth();
	cout << endl;
	for (int i = 0; i <= depth; i++) {
		for (int j = depth - i; j >= 0; j--)
			cout << "  ";
		PrintLevel(treeRoot, i);
		cout << endl;
	}
}

//Display the balance of the tree
void AVLTree::DisplayBalance(){
	PrintNodeBalance(treeRoot);
}

//deletes the memory allocated to each node recursively
void AVLTree::DestroyTree(AVLTreeNode* root){
	if (root != nullptr) {
		DestroyTree(root->left);
		DestroyTree(root->right);
		delete root;//delete the node after deleting it's children recursively
	}
}

//Returns the height of the node 
int AVLTree::Height(AVLTreeNode* root){
	if (root == nullptr)
		return -1;
	return 1 + max(Height(root->left), Height(root->right));
}

//Get's the balance of the tree Height(r)-Height(l)
void AVLTree::SetBalance(AVLTreeNode* root){
	if (root != nullptr) {
		root->balance = (Height(root->right) - Height(root->left));
	}
}

//Prints the nodes balance
void AVLTree::PrintNodeBalance(AVLTreeNode* root){
	//SetBalance(root);
	if (root != nullptr) {
		PrintNodeBalance(root->left);
		cout << root->balance << " ";
		PrintNodeBalance(root->right);
	}
}

//Inserts a node into a tree in it's correct position according to BST algorith
void AVLTree::Insert(int data){
	if (treeRoot == nullptr)
		treeRoot = new AVLTreeNode(data);
	else
		InsertNode(treeRoot, nullptr, data);
}

//Deletes the node with the given value
void AVLTree::Delete(int data){
	treeRoot = DeleteNode(treeRoot, data);
}

//Inserts a node into a tree in it's correct position according to BST algorith
void AVLTree::InsertNode(AVLTreeNode*& root, AVLTreeNode* parent, int data){
	if (root == nullptr) {
		root = new AVLTreeNode(data, parent);
		Rebalance(parent);
	}
	else if (root->data == data)
		cout << data << " already existe in the tree.\n";
	else if (data < root->data)
		InsertNode(root->left, root, data);
	else
		InsertNode(root->right, root, data);
}

//Checks for necessary rotations, performs them and resets treeRoot
void AVLTree::Rebalance(AVLTreeNode* root){
	if (root != nullptr) {
		root = Rotate(root);
		if (root->parent != nullptr)
			Rebalance(root->parent);
		else
			treeRoot = root;
	}
}

//Perform rotations 
AVLTreeNode* AVLTree::Rotate(AVLTreeNode* root){
	SetBalance(root);
	if (root->balance == -2)
		if (Height(root->left->left) >= Height(root->left->right))
			root = RotateRight(root);
		else
			root = RotateLeftThenRight(root);
	else if(root->balance == 2)
		if (Height(root->right->right) >= Height(root->right->left))
			root = RotateLeft(root);
		else
			root = RotateRightThenLeft(root);
	return root;
}

//Performs a Left Rotation and returns the parent node of the tree
AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* root){
	if (root != nullptr) {
		AVLTreeNode* pivot = root->right;
		pivot->parent = root->parent;
		root->right = pivot->left;
		if (root->right != nullptr)//assign parent node
			root->right->parent = root;
		pivot->left = root;//pivot node is new root
		root->parent = pivot;
		if (pivot->parent != nullptr) {//if pivot is not the top parent
			if (pivot->parent->right == root)//top parent points to pivot
				pivot->parent->right = pivot;
			else
				pivot->parent->left = pivot;
		}
		//calculate balance of each node and add to balance var in nodes
		SetBalance(root);
		SetBalance(pivot);
		return pivot;
	}
	else//nothing to rotate 
		return nullptr;
}

//Performs a Right Rotation and returns the parent node of the tree
AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* root){
	if (root != nullptr) {
		AVLTreeNode* pivot = root->left;
		pivot->parent = root->parent;
		root->left = pivot->right;
		if (root->left != nullptr)//assign parent node
			root->left->parent = root;
		pivot->right = root;//pivot node is new root
		root->parent = pivot;
		if (pivot->parent != nullptr) {//if pivot is not the top parent
			if (pivot->parent->right == root)//top parent points to pivot
				pivot->parent->right = pivot;
			else
				pivot->parent->left = pivot;
		}
		//calculate balance of each node and add to balance var in nodes
		SetBalance(root);
		SetBalance(pivot);
		return pivot;
	}
	else//nothing to rotate 
		return nullptr;
}

//performs a left rotation and then a right rotation, returns the root node
AVLTreeNode* AVLTree::RotateLeftThenRight(AVLTreeNode* root){
	root->left = RotateLeft(root->left);
	return RotateRight(root);
}

//performs a right rotation and then a left rotation, returns the root node
AVLTreeNode* AVLTree::RotateRightThenLeft(AVLTreeNode* root){
	root->right = RotateRight(root->right);
	return RotateLeft(root);
}

//returns a pointer to the new tree after deleting the node with data
AVLTreeNode* AVLTree::DeleteNode(AVLTreeNode* root, int data){
	//if the tree is empty return a nullptr
	if (root == nullptr)
		return nullptr;
	//compare input data to node data
	if (data < root->data)//go left
		root->left = DeleteNode(root->left, data);//find and delete in subtree
	else if (data > root->data)	//go right
		root->right = DeleteNode(root->right, data);//find and delete in subtree
	else { //case where input data matches with node data
		//if no children we delete the root
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		}
		//if only a right child we delete node and replace with it's child 
		else if (root->left == nullptr) {
			AVLTreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		//if only a left child we delete node and replace with it's child
		else if (root->right == nullptr) {
			AVLTreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		//two children we delete node and replace with the inorder sucsessor 
		//inorder succsessor == the minimum node of right subtree of node to delete
		else {
			AVLTreeNode* temp = FindMinNode(root->right);//find minimum value
			root->data = temp->data; //place minimum value in node
			root->right = DeleteNode(root->right, temp->data);//delete min from subtree						
		}
	}
	if (root == nullptr)
		return root;
	else
		return Rotate(root);
}

//find the node with the smallest value and returns a pointer to it 
AVLTreeNode* AVLTree::FindMinNode(AVLTreeNode* root){
	if (root == nullptr) {
		cout << "No values in tree.\n";
		return 0;
	}
	if (root->left != nullptr)
		return FindMinNode(root->left);

	return root;
}
