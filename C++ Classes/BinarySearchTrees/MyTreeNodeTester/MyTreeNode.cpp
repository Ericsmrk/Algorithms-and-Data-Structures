// Implementation of a Binary Tree Class
// Eric Smrkovsky
// 3/30/2021
#include "MyTreeNode.h"
#include <iostream>
using namespace std;

typedef double MyType;//add in change when implement prototype pattern

//This is a utility function for printing data within a tree node
void MyTreeNode::PrintNode(MyTreeNode* root){
	cout << root->data << " ";
}

//return the number of nodes in the tree
int MyTreeNode::CountNodes(MyTreeNode* root){
	if (root != nullptr) {
		return 1 + CountNodes(root->left) + CountNodes(root->right);
	}
	else
		return 0;
}


MyTreeNode* MyTreeNode::InvertTreeNode(MyTreeNode* root){
	if(root == nullptr)
		return nullptr;
	//until the given root is nullptr...
	auto left = InvertTreeNode(root->left);//invert left sub-tree
	auto right = InvertTreeNode(root->right);//invert right sub-tree
	//take these inverted trees and swap within tree
	root->left = right;
	root->right = left;
	return root;
}

//return the lowest value in the tree
MyType MyTreeNode::FindMinTree(MyTreeNode* root){
	if (root == nullptr) {
		cout << "No values in tree.\n";
		return 0;
	}
	if (root->left != nullptr)
		return FindMinTree(root->left);
	
	return root->data;
}

//return the highest value in the tree
MyType MyTreeNode::FindMaxTree(MyTreeNode* root){
	if (root == nullptr) {
		cout << "No values in tree.\n";
		return 0;
	}
	if (root->right != nullptr)
		return FindMaxTree(root->right);

	return root->data;
}

//return the pointer to the node with the smallest value in the tree
MyTreeNode* MyTreeNode::FindMinNode(MyTreeNode* root){
	if (root == nullptr) {
		cout << "No nodes in tree.\n";
		return nullptr;
	}
	if (root->left != nullptr)
		return FindMinNode(root->left);

	return root;
}

//return the pointer to the node with the highest value in the tree
MyTreeNode* MyTreeNode::FindMaxNode(MyTreeNode* root){
	if (root == nullptr) {
		cout << "No nodes in tree.\n";
		return nullptr;
	}
	if (root->left != nullptr)
		return FindMinNode(root->left);

	return root;
}

//return the maximim depth the tree can reach
//this method uses recursion to traverse the whole tree
int MyTreeNode::MaxDepthTree2(MyTreeNode* root){
	if (root == nullptr)
		return 0;
	else if (root->left == nullptr && root->right == nullptr)
		return 0;
	else
		return 1 + max(MaxDepthTree2(root->left),
					   MaxDepthTree2(root->right));
}

//return the maximim depth the tree can reach 
//this method compares the depth of the left subtree with right subtree
int MyTreeNode::MaxDepthTree(MyTreeNode* root){
	if (root == nullptr)
		return 0;
	else if (root->left == nullptr && root->right == nullptr)
		return 0;
	else{
		//compute depth of each subtree
		int leftDepth = MaxDepthTree(root->left);
		int rightDepth = MaxDepthTree(root->right);
		//return the largest value
		if (leftDepth < rightDepth)
			return rightDepth + 1;
		else
			return leftDepth + 1;
	}
}

//return the minimum depth that the tree can reach
int MyTreeNode::MinDepthTree(MyTreeNode* root){
	if (root == nullptr)//an empty tree has a nullptr root
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;//A leaf node as 2 nullptrs for children
	if (!root->left)//if left is null check right
		return MinDepthTree(root->right) + 1;
	if (!root->right)//if right is null check left
		return MinDepthTree(root->left) + 1;
	return min(MinDepthTree(root->right), MinDepthTree(root->left));
}

//post data from nodes in 'preorder' form
void MyTreeNode::PreorderNode(MyTreeNode* root){
	if (root != nullptr) {
		PrintNode(root);
		PreorderNode(root->left);
		PreorderNode(root->right);
	}
}

//post data from nodes in 'inorder' form
void MyTreeNode::InorderNode(MyTreeNode* root){
	if (root != nullptr) {
		InorderNode(root->left);
		PrintNode(root);
		InorderNode(root->right);
	}
}

//post data from nodes in 'postorder' form
void MyTreeNode::PostorderNode(MyTreeNode* root){
	if (root != nullptr) {
		PostorderNode(root->left);
		PostorderNode(root->right);
		PrintNode(root);
	}
}

//post data from nodes in 'preorder' form showing levels
void MyTreeNode::PrintPreorderNode(MyTreeNode* root, int lv1){
	if (root != nullptr) {
		PrintNode(root);
		cout << " (" << lv1 << ")\n";
		PrintPreorderNode(root->left, lv1 + 1);
		PrintPreorderNode(root->right, lv1 + 1);
	}
}

//post data from nodes in 'inorder' form showing levels
void MyTreeNode::PrintInorderNode(MyTreeNode* root, int lv1){
	if (root != nullptr) {
		PrintInorderNode(root->left, lv1+1);
		PrintNode(root);
		cout << " (" << lv1 << ")\n";
		PrintInorderNode(root->right, lv1+1);
	}
}

//post data from nodes in 'postorder' form showing levels
void MyTreeNode::PrintPostorderNode(MyTreeNode* root, int lv1){
	if (root != nullptr) {
		PrintPostorderNode(root->left, lv1+1);
		PrintPostorderNode(root->right, lv1+1);
		PrintNode(root);
		cout << " (" << lv1 << ")\n";
	}

}

//print the nodes from given level of the tree
void MyTreeNode::PrintGivenLevel(MyTreeNode* root, int level){
	if (root != nullptr) {
		if (level == 0)
			cout << "." << root->data << ".";
		else {
			PrintGivenLevel(root->left, level - 1);
			PrintGivenLevel(root->right, level - 1);
		}
	}
}

//print the node values by level
void MyTreeNode::PrintLevelOrder(MyTreeNode* root){
	cout << endl;
	for (int i = 0; i <= MaxDepthTree(root); i++) {
		PrintGivenLevel(root, i);
		cout << endl;
	}
}

int MyTreeNode::GetNumberNodesGivenLevel(MyTreeNode* root, int level){
	if (root != nullptr) {
		if (level == 0)
			return 1;
		else return	GetNumberNodesGivenLevel(root->left, level - 1) +
			GetNumberNodesGivenLevel(root->right, level - 1);
	}
	else
		return 0;
}

void MyTreeNode::GetNumberNodesLevel(MyTreeNode* root) {
	cout << endl;
	for (int i = 0; i <= MaxDepthTree(root); i++) {
		cout << "Level:" << i << " with " << GetNumberNodesGivenLevel(root, i);
		cout << " nodes." << endl;
	}
}

//recursively search for a value in the tree, returns 1 if found
bool MyTreeNode::SearchNode(MyTreeNode* root, MyType data){
	if (root == nullptr) 
		return false;
	else if (root->data == data)
		return true;
	else if (data < root->data) 
		return SearchNode(root->left, data);
	else
		return SearchNode(root->right, data);
}

//iteratively search for a value in the tree, returns 1 if found
bool MyTreeNode::SearchNode1(MyTreeNode* root, MyType data){
	if (root == nullptr)
		return false;
	else {
		MyTreeNode* current = root;
		bool found = false;
		while (!found && current != nullptr) {
			if (current->data == data)
				found = true;
			else if (data < current->data)
				current = current->left;
			else
				current = current->right;
		}
		return found;
	}
}

//Recusive insert method with pass by pointer (root is input/output)
void MyTreeNode::InsertNode(MyTreeNode** root, MyType data){
	//if the tree is empty make new parent node
	if ((*root) == nullptr)
		(*root) = new MyTreeNode(data);
	//if data in node matches input data do nothing
	else if ((*root)->data == data)
		cout << "This data is already present in the tree...\n";
	//otherwise we traverse tree until finding correct insert spot
	else if (data < (*root)->data)
		InsertNode(&((*root)->left), data);
	else
		InsertNode(&((*root)->right), data);
}

//Recusive insert method with pass by reference (root is input/output)
void MyTreeNode::InsertNode1(MyTreeNode*& root, MyType data){
	//if the tree is empty make new parent node
	if (root == nullptr)
		root = new MyTreeNode(data);
	//if data in node matches input data do nothing
	else if (root->data == data)
		cout << "This data is already present in the tree...\n";
	//otherwise we traverse tree until finding correct insert spot
	else if (data < root->data)
		InsertNode1(root->left, data);
	else
		InsertNode1(root->right, data);
}

//Recusive insert method with pass by reference (root is input)
MyTreeNode* MyTreeNode::InsertNode2(MyTreeNode* root, MyType data){
	//if the tree is empty make new parent node
	if (root == nullptr)
		return new MyTreeNode(data);
	//if data in node matches input data do nothing
	else if (root->data == data) {
		cout << "This data is already present in the tree...\n";
		return root;
	}
	//otherwise we traverse tree until finding correct insert spot
	else if (data < root->data) {
		root->left = InsertNode2(root->left, data);
		return root;
	}
	else {
		root->right = InsertNode2(root->right, data);
		return root;
	}
}

void MyTreeNode::InsertNode3(MyTreeNode** root, MyType data){
	{//pass with none
//access with none ...root is actually a pointer to a node so adding & get's address
		//if the tree is empty, create a node
		if ((*root) == nullptr)
			(*root) = new MyTreeNode(data);
		//otherwise we traverse tree until finding correct insert spot
		else {
			MyTreeNode* current = (*root);		//for traversal
			MyTreeNode* parent = nullptr;	//for insertion into corect location(why can't use current instead?)
			while (current != nullptr) {	//when current becomes nullptr we insert
				parent = current;		//keep track of the parent
				if (data == current->data) {
					cout << "This data is already present in the tree...\n";
					current = nullptr;
				}
				else if (data < current->data)//go left if value to insert is less than nodes data
					current = current->left;//go left
				else//value to insert is >= to node data so we go right
					current = current->right;//go right
			}
			//we have reached the empty leaf where we insert
			current = new MyTreeNode(data);//create new node
			if (data < parent->data)//make correct left/right pointer point to node
				parent->left = current;
			else
				parent->right = current;
		}
	}//pass with &
}

//Iterative insert using a reference (duplicates are discarded)
void MyTreeNode::InsertNode4(MyTreeNode*& root, MyType data){//pass with none
	//access with none ...root is actually a pointer to a node so adding & get's address
	cout << "InsertNode4 ran\n";

	//if the tree is empty, create a node
	if (root == nullptr)
		root = new MyTreeNode(data);
	//otherwise we traverse tree until finding correct insert spot
	else {
		MyTreeNode* current = root;		//for traversal
		MyTreeNode* parent = nullptr;	//for insertion into corect location(why can't use current instead?)
		while (current != nullptr) {	//when current becomes nullptr we insert
			parent = current;		//keep track of the parent
			if (data == current->data) {
				cout << "This data is already present in the tree...\n";
				current = nullptr;
			}
			else if (data < current->data)//go left if value to insert is less than nodes data
				current = current->left;//go left
			else//value to insert is >= to node data so we go right
				current = current->right;//go right
		}
		//we have reached the empty leaf where we insert
		current = new MyTreeNode(data);//create new node
		if (data < parent->data)//make correct left/right pointer point to node
			parent->left = current;
		else
			parent->right = current;
	}
}


//returns a pointer to the new tree after deleting the node with data
MyTreeNode* MyTreeNode::DeleteNode(MyTreeNode* root, MyType data){
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
			MyTreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		//if only a left child we delete node and replace with it's child
		else if (root->right == nullptr) {
			MyTreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		//two children we delete node and replace with the inorder sucsessor 
		//inorder succsessor == the minimum node of right subtree of node to delete
		else {
			MyTreeNode* temp = FindMinNode(root->right);//find minimum value
			root->data = temp->data; //place minimum value in node
			root->right = DeleteNode(root->right, temp->data);//delete min from subtree						
		}
	}
	return root;
}

//frees memory allocated to a trees root and it's nodes
void MyTreeNode::DestroyTree(MyTreeNode* root){
	if (root != nullptr) {
		DestroyTree(root->left);
		DestroyTree(root->right);
		delete root;
	}
}

//returns true if the two input trees are exactly the same
bool MyTreeNode::SameTree(MyTreeNode* t1, MyTreeNode* t2){
	//if both trees are empty they match
	if (t1 == nullptr && t2 == nullptr)
		return true;
	//if they both aren't empty compare them
	if (t1 != nullptr && t2 != nullptr) {
		return (t1->data == t2->data && SameTree(t1->left, t2->left)
									 && SameTree(t1->right, t2->right));
	}
	//if only one is empty they don't match
	return false;
}

//returns true if the tree meets all of the conditions of a Binary Search Tree
//AND is within the bounds of min and max
bool MyTreeNode::IsBst(MyTreeNode* root, int min, int max){
	if (root == nullptr)
		return true;
	if (root->data < min || root->data > max)
		return false;
	return(IsBst(root->left, min, root->data) &&
		IsBst(root->right, root->data + 1, max));
}

//returns true if all nodes on a level are full before starting a new level
bool MyTreeNode::IsCompleteTree(MyTreeNode* root, int index, int nnodes){
	//if the tree is empty then it is complete
	if (root == nullptr)
		return true;
	if (index >= nnodes)
		return false;
	return(IsCompleteTree(root->left, 2 * index + 1, nnodes) &&
		IsCompleteTree(root->right, 2 * index + 2, nnodes));
}

//returns true if every node has either 0 or 2 children
bool MyTreeNode::IsFullTree(MyTreeNode* root){
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
		return true;
	else if (root->left != nullptr && root->right != nullptr)
		return (IsFullTree(root->left) && IsFullTree(root->right));
	else
		return false;
}

//returns true if all interior nodes have 2 children
//and all leaves have the same depth
bool MyTreeNode::IsPerfectTree(MyTreeNode* root){
	if (root == nullptr)
		return true;
	else
		return (CountNodes(root) == pow(2, MaxDepthTree(root) + 1) - 1);
}