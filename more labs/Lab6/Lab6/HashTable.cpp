//CSCi 115 --Lab 6
//Eric Smrkovsky
//3/12/2021

//This lab uses arrays and linked lists to implement a Hash Table. 
//The Hash Table is of size 50 and uses an array to store data.
//If the slot in the array is already filled the algorithm    
//will uses separate chaining to deal with collisions.

//This is a simple program that accesses a text file called 'numbers.txt that
//includes 100 power-ball numbers. The program then take the sum of each 
//power-ball number and hashes it into the data structure. Each slot of the 
//array holds a (head) node of a linked list which can lead to a chain of nodes
//if there are multiple collisions that occur when the insertions happens. 

//NOTE: I left some debugging commented out for when I finish this
//planned implementation of other functionalites and more probing techniques

#include "HashTable.h"
#include <iostream>
using namespace std;

//creates an empty hash table of size 50
HashTable::HashTable(){
											//cout << "Constructor\n";
	for (int i = 0; i < 50; i++) {//assign every array vallue to nullptr
		table[i] = nullptr;
	}
}

void HashTable::insert(int sum){
	int key = hash(sum);	//get the key for this sum
	bool done = false;		//flag turns true when insertion occurs or count++
											//cout << "  key: " << key << endl;
	//if the value at element 'key' of the array is nullptr we just insert 
	if (table[key] == nullptr) {
		Node* newNode = new Node;			//allocate mem for new node
		table[key] = newNode;  //assign newNode to slot in array at index 'key'
		newNode->sum = sum;	   //assign the value of sum input to node sum var
	}
	
	else {
		//if the sum exists, increment the count of the node that holds the sum
		//create a temp node for traversal in for loop checking for nullptr
		for (Node* temp = table[key]; temp != nullptr; temp = temp->next) {
			if (temp->sum == sum) {		//check that node sum matches input sum
				temp->count++;			//if sums match increment count 
				done = true;			//need this flag to prevent an error
			}							//found when testing the find function
			//if we haven't incremented count and next is null, insert here
			else if (temp->next == nullptr && not done) {
				Node* newNode = new Node;		//allocate mem for new node
				temp->next = newNode;	//next now points to the new node 	
				newNode->sum = sum;		//this node holds a sum we haven't seen
				temp = temp->next; //get ready to check next node but loop dies
			}
		}
	}
}

//finds the count of a sum, if sum doesn't exist return 0
//otherwise if sum does exist increment count and return count value
int HashTable::find(int sum){
	int count = 0;			//count is at 0 to start (0 represents false also)
	int key = hash(sum);	//get the key of the sum

	//FIND the count value for the given sum in the respective slot of the key
	if (table[key] != nullptr) {		//if there is a node in the slot
		Node* temp = table[key];		//create a temp node for traversal
		while (temp != nullptr) {		//while temp is still a node
			if (temp->sum == sum) 		//check that node sum matches input sum
				count = temp->count;	//if a match update count for return
										//otherwise return value remains 0
			temp = temp->next;			//update temp node to check next node
		}
	}
	return count;		//returns 0 if not found and count of the sum if found
}

//displays the sums in the array and their count
void HashTable::display(){
	cout << "\nNow displaying table...\n";
	for (int i = 0; i < 50; i++) {

		if (table[i] != nullptr) {   //table slots value is not nullptr
			//traverse linked list to show node contents 
			for (Node* temp = table[i]; temp != nullptr; temp = temp->next) {
				cout << "--------------\n";
				cout << "Index: " << i << endl;			 //show Index of node
				cout << "Sum: " << temp->sum << endl;	 //show Sum of node
				cout << "Count: " << temp->count << endl;//show Count of node
			}
		}
	}
}

int HashTable::hash(int key){
	int index;				//result of the hash function

	index = key % 50;		//use has function (key mod 50)
	return index;			//return the index of given key
}