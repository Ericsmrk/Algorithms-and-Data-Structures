// CSci 115 --Lab 7
// Implementation of a AVL Tree Class
// Eric Smrkovsky
// 4/2/2021
#include "AVLTree.h"
#include <iostream>
using namespace std;

int main()
{
	//show title
	cout << "--------------------------------------------------------------\n";
	cout << "-----Implementation-------------------CSCi 115---Lab 7--------\n";
	cout << "---------of a-------------------------Eric Smrkovsky----------\n";
	cout << "-----AVL Tree Class----------------------4/2/2021-------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "\n\n\n";

	cout << "Testing methods within AVLTree Class...\n\n\n";
	
	AVLTree* myTree = new AVLTree();

	myTree->Insert(50);
	myTree->Insert(60);
	myTree->Insert(40);
	myTree->Insert(20);
	myTree->Insert(45);
	myTree->Insert(47);
	myTree->DisplayTree();
	

	//
	//cout << "Insert(100): ";
	//myTree->Insert(100);
	//cout << "Insert(200): ";
	//myTree->Insert(200);
	//cout << "Insert(200): ";
	//myTree->Insert(200);
	//cout << "Insert(300): ";
	//myTree->Insert(300);
	//cout << "GetMaxDepth: " << myTree->GetMaxDepth() << endl;
	//cout << "Insert(150): ";
	//myTree->Insert(150);
	//cout << "Insert(50): ";
	//myTree->Insert(50);
	//cout << "Insert(30): ";
	//myTree->Insert(30);
	//cout << "Insert(75): ";
	//myTree->Insert(75);
	//cout << "GetMaxDepth: " << myTree->GetMaxDepth() << endl;
	//cout << "Insert(76): ";
	//myTree->Insert(76);
	//cout << "Insert(77): ";
	//myTree->Insert(77);	
	//cout << "GetMaxDepth: " << myTree->GetMaxDepth() << endl;
	//cout << "DisplayTree: ";
	//myTree->DisplayTree();
	//cout << "Checking Destructor: \n";
	//myTree->~AVLTree();

	//AVLTree* myTree2 = new AVLTree();
	//cout << "Insert(100): ";
	//myTree2->Insert(100);
	//cout << "Balance: ";
	//myTree2->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree2->DisplayTree();
	//cout << "\nInsert(50): ";
	//myTree2->Insert(50);
	//cout << "Balance: ";
	//myTree2->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree2->DisplayTree();
	//cout << "\nInsert(25): ";	
	//myTree2->Insert(25);
	//cout << "Balance: ";
	//myTree2->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree2->DisplayTree();

	////Example from slide 29 in lecture PDF for AVLtrees
	//AVLTree* myTree3 = new AVLTree();
	//cout << "Insert(3): ";
	//myTree3->Insert(3);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(2): ";
	//myTree3->Insert(2);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(1): ";
	//myTree3->Insert(1);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(4): ";
	//myTree3->Insert(4);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(5): ";
	//myTree3->Insert(5);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(6): ";
	//myTree3->Insert(6);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(7): ";
	//myTree3->Insert(7);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(16): ";
	//myTree3->Insert(16);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(15): ";
	//myTree3->Insert(15);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nInsert(14): ";
	//myTree3->Insert(14);
	//cout << "Balance: ";
	//myTree3->DisplayBalance();
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();

	//cout << "\nDelete(4): ";
	//myTree3->Delete(4);
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nDelete(3): ";
	//myTree3->Delete(3);
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nDelete(2): ";
	//myTree3->Delete(2);
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nDelete(6): ";
	//myTree3->Delete(6);
	//cout << "DisplayTree: ";
	//myTree3->DisplayTree();
	//cout << "\nDelete(7): ";
	//myTree3->Delete(7);
	//cout << "DisplayTree: ";
	
	cout << "\n\n\nEnd  of testing...\n\n\n";

}
