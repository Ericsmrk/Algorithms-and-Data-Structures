//CSCi 115 --Lab 1
//An Array Class
//Eric Smrkovsky
//1/29/2021


#include "Array.h"
#include <iostream>
using namespace std;

int main() { 

	cout << "Test file for lab 1 in CSci 115 at FSU.";
	cout << "\n\n-------------------------------------------------------------\n";

	//testing default constructor
	Array arr1;
	cout << "Default constructor success with array1.\n";

	//testing getSize()
	cout << "Size of array1: " << arr1.getSize() << endl;

	//testing copy constructor with size
	Array arr2(20);
	cout << "Copy constructor success with array2.\n";

	//testing getSize()
	cout << "Size of array2: " << arr2.getSize() << endl;

	//testing displayArray()
	arr2.displayArray();

	//testing addToTop(newElement)
	cout << "Testing addToTop()...\n";
	arr2.addToTop(20);
	arr2.displayArray();

	//testing addToBottom(newElement)
	cout << "Testing addToBottom()...\n";
	arr2.addToBottom(20);
	arr2.displayArray();

	//testing removeFromTop()
	cout << "Testing removeFromTop()...\n";
	arr2.removeFromTop();
	arr2.displayArray();

	//testing removeFromBottom()
	cout << "Testing removeFromBottom()...\n";
	arr2.removeFromBottom();
	arr2.displayArray();

	//testing invertArray()
	cout << "Testing invertArray() with even number of input elements...\n";
	arr2.invertArray();
	arr2.displayArray();

	//testing invertArray()
	arr2.addToBottom(20);
	arr2.displayArray();
	cout << "Testing invertArray() with odd number of input elements...\n";
	arr2.invertArray();
	arr2.displayArray();

	//testing returnSum()
	cout << "Testing returnSum()...\n";
	cout << "Sum of previous array is " << arr2.returnSum() << ".\n";

	//testing returnOdd()
	int* oddArray;
	cout << "Testing returnOdd() with previous array...\n";
	oddArray = arr2.returnOdd();
	
	//testing Copy Constructor with size and data array
	int input;
	cout << "What is INPUT? ";
	cin >> input;
	Array arr3(input, oddArray);
	//Array arr3(10, oddArray);
	arr3.displayArray();
	arr2.displayArray();

	//testing Function to create a char array with ascii characters
	Array arr4;
	char* charArray;
	charArray = arr4.makeAsciArray(100);

	//testing function to Display the content of the char array
	arr4.printCharArray(charArray);

	//testing Display the content of the array in a file
	arr4.writeToFile(charArray);

	//testing overload the + operator to concat two arrays of size n and m
	cout << "Testing overload + with previous two arrays..." << endl;
	int* arr = arr3 + arr2;
	Array arr5(arr3.arraySize + arr2.arraySize, arr);
	arr5.displayArray();
}

