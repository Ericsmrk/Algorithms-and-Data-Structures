// Implementation of a Binary Tree Class
// Eric Smrkovsky
// 3/30/2021
#pragma once

class MyTreeNode
{
public:
	typedef double MyType;//added in change when implement prototype pattern

	//define a "TreeNode" with a left and right pointer and data 
	MyTreeNode() : data(0), left(nullptr), right(nullptr) { }
	MyTreeNode(int d) : data(d), left(nullptr), right(nullptr) { }
	~MyTreeNode() { };		//destructor calls destroy tree (in slides)
	int data;
	MyTreeNode* left;
	MyTreeNode* right;

	//Utility functions
	void PrintNode(MyTreeNode* root);
	int CountNodes(MyTreeNode* root);
	MyTreeNode* InvertTreeNode(MyTreeNode* root);
	MyType FindMinTree(MyTreeNode* root);
	MyType FindMaxTree(MyTreeNode* root);
	MyTreeNode* FindMinNode(MyTreeNode* root);
	MyTreeNode* FindMaxNode(MyTreeNode* root);
	int MaxDepthTree2(MyTreeNode* root);
	int MaxDepthTree(MyTreeNode* root);
	int MinDepthTree(MyTreeNode* root);

	//Traversal functions
	void PreorderNode(MyTreeNode* root);
	void InorderNode(MyTreeNode* root);
	void PostorderNode(MyTreeNode* root);
	void PrintPreorderNode(MyTreeNode* root, int lv1);
	void PrintInorderNode(MyTreeNode* root, int lv1);
	void PrintPostorderNode(MyTreeNode* root, int lv1);
	void PrintGivenLevel(MyTreeNode* root, int level);
	void PrintLevelOrder(MyTreeNode* root);
	int GetNumberNodesGivenLevel(MyTreeNode* root, int level);
	void GetNumberNodesLevel(MyTreeNode* root);

	//Search functions
	bool SearchNode(MyTreeNode* root, MyType data);
	bool SearchNode1(MyTreeNode* root, MyType data);

	//Insert functions
	void InsertNode(MyTreeNode** root, MyType data);
	void InsertNode1(MyTreeNode* &root, MyType data);
	MyTreeNode* InsertNode2(MyTreeNode* root, MyType data);
	void InsertNode3(MyTreeNode** root, MyType data);
	void InsertNode4(MyTreeNode* &root, MyType data);
	
	//Delete functions
	MyTreeNode* DeleteNode(MyTreeNode* root, MyType data);
	void DestroyTree(MyTreeNode* root);

	//Comparison functions
	bool SameTree(MyTreeNode* t1, MyTreeNode* t2);
	bool IsBst(MyTreeNode* node, int min, int max);
	bool IsCompleteTree(MyTreeNode* node, int min, int max);
	bool IsFullTree(MyTreeNode* node);
	bool IsPerfectTree(MyTreeNode* node);

};

