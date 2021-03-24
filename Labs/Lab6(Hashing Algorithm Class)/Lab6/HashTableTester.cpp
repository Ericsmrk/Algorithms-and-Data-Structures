//CSCi 115 --Lab 6
//Eric Smrkovsky
//3/12/2021

//This lab uses arrays and linked lists to implement a Hash Table. 
//The Hash Table is of size 50 and uses an array to store data.
//If the slot in the array is already filled the algorithm    
//will use separate chaining to deal with collisions.

//This is a simple program that accesses a text file called 'numbers.txt that
//includes 100 power-ball numbers. The program then takes the sum of each 
//power-ball number and hashes it into the data structure. Each slot of the 
//array holds a (head) node of a linked list which can lead to a chain of nodes
//if there are multiple collisions that occur when the insertions happens. 

//NOTE: I left some debugging commented out for when I add to this
//planned implementation of other functionalites and more probing techniques
#include <iostream>
#include <fstream>
#include "HashTable.h"
using namespace std;

//this function gets data from input stream object, sums the 7 numbers
//and returns the sum
int sumLine(fstream& numFile) {
	int dataArr[7];		//size of numbers of each line in numbers.txt 
	int sum = 0;		//starts at 0  

										//cout << "\nget/show/sum\n";

	//this loop gets data from input stream object, sums the 7 numbers
	//and returns the sum
	for (int i = 0; i < 7; i++) {
		numFile >> dataArr[i];
										//cout << " " << dataArr[i];
		sum += dataArr[i];
	}
										//cout << "  sum: " << sum;

	return sum;
}

int main()
{
	//show title
	cout << "--------------------------------------------------------------\n";
	cout << "-----Implementation-------------------CSCi 115---Lab 6--------\n";
	cout << "---------of a-------------------------Eric Smrkovsky----------\n";
	cout << "-------Hash Table-----------------------3/12/2021-------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "\nThis lab uses arrays and linked lists to implement a ";
	cout << "Hash Table.\nThe Hash Table is of size 50 and uses an array";
	cout << " to store data.\nIf the slot in the array is already filled the";
	cout << " algorithm will\nuses separate chaining to deal with collisions.";
	cout << "\n\n";
	cout << "This is a simple program that accesses a text file called ";
	cout << "'numbers.txt' that\nincludes 100 powerball numbers. The program";
	cout << " then takes the sum of each\npowerball number and hashes it into";
	cout << " the data structure. Each slot of the\narray holds a (head) node";
	cout << " of a linked list which can lead to a chain of nodes \nif there";
	cout << " are multiple collisions that occur when the insertions happens.";
	cout << "\n\n\n";

	//begin testing
	HashTable myHashTable;		//call constructor from HashTable class
	int sum = 0;				//initialize variable to hold sums

	//get data from file and sum each line
	fstream numFile;						//create a fstream object
	numFile.open("numbers.txt", ios::in);	//open file for reading numbers
	
	//call the insert function 100 times with each line from numbers.txt file
	for (int i = 0; i < 100; i++) {
		sum = sumLine(numFile);
		myHashTable.insert(sum);
	}
	
	//display the results 
	myHashTable.display();		

	//test the find function since it wasn't used
	cout << "\n\nTesting find...\n";
	cout << "150 Found? " << myHashTable.find(150) << " times.\n";
	cout << "151 Found? " << myHashTable.find(151) << " times.\n";
	cout << "250 Found? " << myHashTable.find(250) << " times.\n";
	cout << "164 Found? " << myHashTable.find(164) << " times.\n";
	cout << "0 Found? " << myHashTable.find(0) << " times.\n";

	numFile.close();			 //close the file for reading lottery numbers

}
