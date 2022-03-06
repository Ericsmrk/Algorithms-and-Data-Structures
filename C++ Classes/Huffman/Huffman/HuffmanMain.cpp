#include <string>
#include "Huffman.h"
#include <iostream>
//Huffman extra credit
//Eric Smrkovsky
//Csci 115 Sp21


#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
	Huffman* myTree = new Huffman();
	myTree->runHuffman();
	Node* myRoot = myTree->GetRoot();
	myTree->printStoreHuffmanCodes(myRoot, "");
	myTree->getStringFromFile();
	myTree->printString();
	string myStr = myTree->getInputString();
	myTree->encode(myStr);
	myTree->showEncodedData();
	cout << "\n\n";
	myTree->decode();
	cout << "\n\n\n";

	myTree->DestroyTree(myRoot);
}
