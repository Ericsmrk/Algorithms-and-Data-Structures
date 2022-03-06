// Implementation of a Binary Tree Class
// Eric Smrkovsky
// 3/30/2021
#include "MyTreeNode.h"
#include <iostream>
using namespace std;

void test1();

int main()
{
    test1();

    MyTreeNode* myTree = new MyTreeNode;
    MyTreeNode* n = nullptr;
    myTree->InsertNode1(n, 4);
    myTree->InsertNode1(n, 12);
    myTree->InsertNode1(n, 16);
    myTree->InsertNode1(n, 23);
    myTree->InsertNode1(n, 27);
    myTree->InsertNode1(n, 34);
    myTree->InsertNode1(n, 56);
    cout << "BST? " << myTree->IsBst(myTree, 0, 100) << endl;
    myTree->PrintLevelOrder(n);

    MyTreeNode* myTree2 = new MyTreeNode;
    MyTreeNode* n2 = nullptr;
    myTree->InsertNode1(n, 20);
    myTree->InsertNode1(n, 10);
    myTree->InsertNode1(n, 3);
    myTree->InsertNode1(n, 40);
    myTree->InsertNode1(n, 28);
    myTree->InsertNode1(n, 16);
    myTree->InsertNode1(n, 52);

}


void test1() {

    cout << "\n\nTesting methods within MyTreeNodeClass...\n\n";
    MyTreeNode* myTree = new MyTreeNode;
    MyTreeNode* n = nullptr;
    //cout << n << "<><><><><><>" << &n << "<><><><><><>" << *(&n);
    /*myTree->InsertNode(&n, 50);
    myTree->InsertNode1(n, 50);
    myTree->InsertNode2(n, 50);
    myTree->InsertNode3(&n, 50);
    */
    //myTree->InsertNode4(n, 60);
    //myTree->InsertNode4(n, 40);
    //myTree->InsertNode4(n, 30);
    //myTree->InsertNode4(n, 50);
    //myTree->InsertNode4(n, 45);
    cout << "FindMinTree: ";
    myTree->InsertNode3(&n, 60);
    myTree->InsertNode3(&n, 40);
    myTree->InsertNode3(&n, 30);
    myTree->InsertNode3(&n, 50);
    myTree->InsertNode3(&n, 45);
    myTree->InsertNode3(&n, 70);

    cout << "Count: " << myTree->CountNodes(n) << endl;

    cout << "PreOrder: ";
    myTree->PreorderNode(n);
    cout << endl;

    cout << "InOrder: ";
    myTree->InorderNode(n);
    cout << endl;

    cout << "PostOrder: ";
    myTree->PostorderNode(n);
    cout << endl;

    cout << "PreOrder (with level): ";
    myTree->PrintPreorderNode(n, 0);
    cout << endl;

    cout << "InOrder (with level): ";
    myTree->PrintInorderNode(n, 0);
    cout << endl;

    cout << "PostOrder (with level): ";
    myTree->PrintPostorderNode(n, 0);
    cout << endl;

    cout << "PrintGivenLevel(2): ";
    myTree->PrintGivenLevel(n, 2);
    cout << endl;

    cout << "FindMinTree: ";
    cout << myTree->FindMinTree(n);
    cout << endl;

    cout << "FindMaxTree: ";
    cout << myTree->FindMaxTree(n);
    cout << endl;

    cout << "MaxDepthTree2: ";
    cout << myTree->MaxDepthTree2(n);
    cout << endl;

    cout << "MaxDepthTree: ";
    cout << myTree->MaxDepthTree(n);
    cout << endl;

    cout << "MinDepthTree: ";
    cout << myTree->MinDepthTree(n);
    cout << endl;

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "GetNumberNodesGivenLevel(2): ";
    cout << myTree->GetNumberNodesGivenLevel(n, 4);
    cout << endl;

    cout << "GetNumberNodesLevel: ";
    myTree->GetNumberNodesLevel(n);
    cout << endl;

    cout << "InvertTreeNode: ";
    n = myTree->InvertTreeNode(n);//invert tree
    myTree->PrintLevelOrder(n);//show results
    cout << endl;
    cout << "InvertTreeNode: ";
    n = myTree->InvertTreeNode(n);//invert tree back to original
    myTree->PrintLevelOrder(n);//show results
    cout << endl;

    cout << "SearchNode(50):  ";
    cout << "Found?  " << myTree->SearchNode(n, 40);
    cout << endl;
    cout << "SearchNode(41):  ";
    cout << "Found?  " << myTree->SearchNode(n, 41);
    cout << endl;

    cout << "SearchNode1(50):  ";
    cout << "Found?  " << myTree->SearchNode1(n, 50);
    cout << endl;

    cout << "SearchNode1(41):  ";
    cout << "Found?  " << myTree->SearchNode1(n, 41);
    cout << "\n\n";

    MyTreeNode* myTree2 = new MyTreeNode;
    MyTreeNode* n2 = nullptr;
    myTree->InsertNode3(&n2, 61);
    myTree->InsertNode3(&n2, 41);
    myTree->InsertNode3(&n2, 31);
    myTree->InsertNode3(&n2, 51);
    myTree->InsertNode3(&n2, 41);//checks duplicate case
    myTree->InsertNode3(&n2, 71);
    cout << endl;

    cout << "SameTree: ";
    cout << myTree->SameTree(n, n2);
    cout << endl;

    cout << "DestroyTree(2) ran\n\n\n";
    myTree->DestroyTree(n2);//done with extra tree

    cout << "SameTree: ";
    cout << myTree->SameTree(n, n);
    cout << endl;

    cout << "IsBST: ";
    cout << myTree->IsBst(n, 20, 80);
    cout << endl;

    cout << "IsBST: ";
    cout << myTree->IsBst(n, 35, 80);
    cout << endl;

    cout << "IsBST: ";
    cout << myTree->IsBst(n, 20, 60);
    cout << endl;

    MyTreeNode* myTree3 = new MyTreeNode;
    MyTreeNode* n3 = nullptr;
    myTree->InsertNode3(&n3, 61);

    cout << "IsCompleteTree: ";
    cout << myTree->IsCompleteTree(n3, 0, myTree->CountNodes(n3));
    cout << endl;

    myTree->InsertNode3(&n3, 59);
    myTree->InsertNode3(&n3, 58);

    cout << "IsCompleteTree: ";
    cout << myTree->IsCompleteTree(n3, 0, myTree->CountNodes(n3));
    cout << endl;

    cout << "IsFullTree: ";
    cout << myTree->IsFullTree(n3);
    cout << endl;

    myTree->InsertNode3(&n3, 60);
    myTree->InsertNode3(&n3, 65);

    cout << "IsFullTree: ";
    cout << myTree->IsFullTree(n3);
    cout << endl;

    cout << "IsPerfectTree: ";
    cout << myTree->IsPerfectTree(n3);
    cout << endl;

    myTree->InsertNode3(&n3, 63);
    myTree->InsertNode3(&n3, 66);

    cout << "IsPerfectTree: ";
    cout << myTree->IsPerfectTree(n3);
    cout << endl;

    cout << "DestroyTree(3) ran\n\n\n";
    myTree->DestroyTree(n3);

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "DeleteNode(70): ";
    n = myTree->DeleteNode(n, 70);
    cout << endl;

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "DeleteNode(40): ";
    n = myTree->DeleteNode(n, 40);
    cout << endl;

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "DeleteNode(41): ";
    n = myTree->DeleteNode(n, 41);
    cout << endl;

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "DeleteNode(60): ";
    n = myTree->DeleteNode(n, 60);
    cout << endl;

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "InsertNode(1,55,100,150): ";
    myTree->InsertNode(&n, 1);
    myTree->InsertNode(&n, 55);
    myTree->InsertNode(&n, 100);
    myTree->InsertNode(&n, 150);

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "InsertNode1(49,35,54,99): ";
    myTree->InsertNode1(n, 49);
    myTree->InsertNode1(n, 35);
    myTree->InsertNode1(n, 54);
    myTree->InsertNode1(n, 99);

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "InsertNode2(2,36,32,30): ";
    n = myTree->InsertNode2(n, 2);
    n = myTree->InsertNode2(n, 36);
    n = myTree->InsertNode2(n, 32);
    n = myTree->InsertNode2(n, 30);

    cout << "PrintLevelOrder: ";
    myTree->PrintLevelOrder(n);
    cout << endl;

    cout << "DestroyTree ran\n\n\n";
    myTree->DestroyTree(n);
}

