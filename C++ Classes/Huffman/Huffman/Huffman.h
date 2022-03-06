//Huffman extra credit
//Eric Smrkovsky
//Csci 115 Sp21


#pragma once
#include <string>
#include <queue>
using namespace std;
//create a node for a letter
struct Node {
	Node* left;
	Node* right;
	int frequency;
	char letter;

	Node(char let, int f, Node* l, Node* r) : letter(let), frequency(f), left(l), right(r) { }
};

class Huffman {

public:

	Huffman();
	~Huffman() { DestroyTree(root); };
	
	Node* MHNode(char letter, float freq);
	Node* MHNode(char letter, float freq, Node* left, Node* right);
	Node* GetRoot();
	
	void runHuffman();
	void printStoreHuffmanCodes(Node* root, string str);
	void encode(string str);
	char decodeH(string str);
	void decode();
	void DestroyTree(Node* root);
	void printString();
	string getInputString();
	void showEncodedData();
	void getStringFromFile();

private:
	string* str;
	Node* root;
	string* encodedLetters;  //stores binary codes for alphabet
	string* letters;			//Stores letters 
	string* encodedData;
};
