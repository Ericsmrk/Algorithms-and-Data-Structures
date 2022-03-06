//Huffman extra credit
//Eric Smrkovsky
//Csci 115 Sp21


#include "Huffman.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

//create a new node for heap
Node* Huffman::MHNode(char letter, float freq, Node* left, Node* right){
	return new Node(letter, freq, left, right);
}

Node* Huffman::GetRoot(){
	return root;
}

Huffman::Huffman(){
	root = nullptr; 
	letters = new string[200];         //allocate memory
	encodedLetters = new string[200];  //allocate memory
	encodedData = nullptr;
	str = nullptr;
}

//create a new node for heap with null kids
Node* Huffman::MHNode(char letter, float freq) {
	return new Node(letter, freq, nullptr, nullptr);
}

// overloaded function for comparisons
struct compare {
	bool operator()(Node* left, Node* right){
		return (left->frequency > right->frequency);
	}
};

//stores the codes in an array and prints them
void Huffman::printStoreHuffmanCodes(Node* root, string str){
	
	if (root != nullptr) {
		if (root->letter != 'X') {
			letters[root->letter] = root->letter;
			encodedLetters[root->letter] = str;
			cout << letters[root->letter] << ": " << encodedLetters[root->letter] << endl;
		}
		printStoreHuffmanCodes(root->left, str + "0");
		printStoreHuffmanCodes(root->right, str + "1");
	}
}

//encode a string 
void Huffman::encode(string str) {
	int sSize = str.size();
	encodedData = new string[sSize];         //allocate memory
		
	cout << "\n\nNow encoding string: " << str << "!" << endl;
	for (int i = 0; i < sSize; i++) {//initialize array with subscript values
		encodedData[i] = encodedLetters[str[i]];
	}
}

//a helper function that returns a decoded letter
char Huffman::decodeH(string str){
	string letters1 = "abcdefghijklmnopqrstuvwkyz ";

	for (int i = 0; i < 27; i++) {
		if (encodedLetters[letters1[i]] == str)
			return letters1[i];
	}
}

//decodes and prints the string that was encoded
void Huffman::decode() {
	string letters = "abcdefghijklmnopqrstuvwkyz ";
	int lengthOfString = str->size();

	cout << "Length of string to decode: " << lengthOfString << endl;
	cout << "\nDecoded string: ";

	for (int i = 0; i < lengthOfString; i++)
		cout << decodeH(encodedData[i]);
}


//deallocate mem for tree
void Huffman::DestroyTree(Node* root){
	if (root != nullptr) {
		DestroyTree(root->left);
		DestroyTree(root->right);
		delete root;
	}
}

//get huffman codes and put them into a priority queue
void Huffman::runHuffman(){
	string alphabet = "abcdefghijklmnopqrstuvwxyz ";
	float freq[] = { .082,.015, .028, .043, .13, .022, .02, .061, .07, .0015, .0077, .04,
		.024, .067, .075, .019, .00095, .06, .063, .08, .028, .0098, .024,
		.0015, .02, .00074, .00681 }; //I altered this a little because no space
								//and the wikipedia values don't add up to 1
	//check above contents
	/*float total = 0;
	for (int i = 0; i < 27; i++) {
		cout << alphabet[i] << "::" << FsfromWiki[i] << endl;
		total = total + FsfromWiki[i];
	}
	cout << "Total? " << total << endl;*/
	
	int length = alphabet.length();
	cout << "Number of Huffman codes: " << length << endl;

	Node* left = nullptr;
	Node* right = nullptr;

	//make a priority q
	priority_queue<Node*, vector<Node*>, compare> myPQ;
	
	//add to queue by smallest frequency
	for (int i = 0; i < length; i++)
		myPQ.push(MHNode(alphabet[i], freq[i]));

	while (myPQ.size() != 1) {
		
		//get the smallest frequency items from Q
		left = myPQ.top();
		myPQ.pop();

		right = myPQ.top();
		myPQ.pop();

		//make a new node for sum of frequencies and push onto Q
		Node* newNode = MHNode('X', left->frequency + right->frequency, left, right);
		myPQ.push(newNode);
		root = myPQ.top();
	}
}

//prints the private string from class
void Huffman::printString(){
	cout << *str;
}

//returns string found in the input file
string Huffman::getInputString(){
	return *str;
}

//shows the string returned fron encoding process
void Huffman::showEncodedData(){
	cout << "\n\nEncoded data: ";
	int sSize = str->size();
	for (int i = 0; i < sSize; i++)
		cout << encodedData[i];
}

//get a string from a file input is input.txt 
void Huffman::getStringFromFile(){
	cout << "\nReading input from file: ";
	string outStr;					//create a string to return
	ifstream myStr("input.txt");		//open file into fstream object
	stringstream ss;				//make a "input buffer" ?
	ss << myStr.rdbuf();			//get everything from file into string
	outStr = ss.str();				//put everything from buffer into a string
	myStr.close();
	str = new string;
	*str = outStr;				//assign to class 
}

