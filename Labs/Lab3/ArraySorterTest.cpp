//CSCi 115 --Lab 3
//Array Sorter Class
//Eric Smrkovsky
//2/12/2021
//
//This lab uses arrays to implement the following algorithms:
//	Selection Sort
//	Insertion Sort
//	Bubble Sort
//	Binary Search 

#include <iostream>
#include "ArraySorter.h"
using namespace std;

int main() {
	int choice = -1;			//show title, get input for program choice
	cout << "---------------------------------------------------------------------\n";
	cout << "----InsertionSort---------------------CSCi 115---Lab 3---------------\n";
	cout << "----SelectionSort---------------------Eric Smrkovsky-----------------\n";
	cout << "----BubbleSort------------------------2/12/2021----------------------\n";
	cout << "----BinarySearchIterative--------------------------------------------\n";
	cout << "----BinarySearchRecursive--------------------------------------------\n";
	cout << "---------------------------------------------------------------------";
	cout << "\n\nThis program will produce random unsorted arrays of size\n";
	cout << "ten and sort them with the above sorting algorithms or \n";
	cout << "perform binary search looking for a target element.\n\n";
	cout << "Press 1 to test sorting algorithims or 2 for binary search algorithms: ";
	cin >> choice; 
	cout << "\n";

	//create array object with constructor and display array
	ArraySorter array;
	int numberToSearchFor = 0, result = -2;
	switch (choice)
	{
	case 1:

		cout << "Unsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Selection Sort...\n";
		array.selectionSort();		//sort array with selection sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements

		cout << "\n\nUnsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Insertion Sort...\n";
		array.insertionSort();		//sort array with insertion sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements

		cout << "\n\nUnsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Bubble Sort...\n";
		array.bubbleSort();			//sort array with selection sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements
		cout << "\n\n\n";
		break;

	case 2:
		// (( array )) needs to be presorted for binary search to be successful 
		array.bubbleSort();			//sort array
		array.displayArray();		//display sorted array
		cout << "Please choose a number to be searched for in the array: ";
		cin >> numberToSearchFor;

		//run binarySearchIterative()
		cout << "\n\nNow searching with the ITERATIVE version of Binary Search...\n";
		result = array.binarySearchIterative(numberToSearchFor);
		if (result == -1)
			cout << "\nSorry! " << numberToSearchFor << " was not found in the array...\n\n";
		else
			cout << "\nSuccess! " << numberToSearchFor << " was found in the array in position " << result << "...\n\n";

		//run binarySearchRecursive()
		cout << "Now searching with the RECURSIVE version of Binary Search...\n";
		result = array.binarySearchRecursive(numberToSearchFor);
		if (result == -1)
			cout << "\nSorry! " << numberToSearchFor << " was not found in the array...\n\n";
		else
			cout << "\nSuccess! " << numberToSearchFor << " was found in the array in position " << result << "...\n\n";
		break;

	default:
		cout << "Invalid choice... So... I guess I'll test both for you.\n";

		cout << "\nTESTING SORTING ALGORITHMS\n\n";

		cout << "Unsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Selection Sort...\n";
		array.selectionSort();		//sort array with selection sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements

		cout << "\n\nUnsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Insertion Sort...\n";
		array.insertionSort();		//sort array with insertion sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements

		cout << "\n\nUnsorted array: ";
		array.displayArray();		//display unsorted array
		cout << "Sorting with Bubble Sort...\n";
		array.bubbleSort();			//sort array with selection sort algorithm
		cout << "Sorted array: ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to new set of random elements
		cout << "\n\n\n";
		
		cout << "TESTING BINARY SEARCH ALGORITHMS\n";
		
		// (( array )) needs to be presorted for binary search to be successful 
		array.bubbleSort();			//sort array
		array.displayArray();		//display sorted array
		cout << "Please choose a number to be searched for in the array: ";
		cin >> numberToSearchFor;

		//run binarySearchIterative()
		cout << "\n\nNow searching with the ITERATIVE version of Binary Search...\n";
		result = array.binarySearchIterative(numberToSearchFor);
		if (result == -1)
			cout << "\nSorry! " << numberToSearchFor << " was not found in the array...\n\n";
		else
			cout << "\nSuccess! " << numberToSearchFor << " was found in the array in position " << result << "...\n\n";

		//run binarySearchRecursive()
		cout << "Now searching with the RECURSIVE version of Binary Search...\n";
		result = array.binarySearchRecursive(numberToSearchFor);
		if (result == -1)
			cout << "\nSorry! " << numberToSearchFor << " was not found in the array...\n\n";
		else
			cout << "\nSuccess! " << numberToSearchFor << " was found in the array in position " << result << "...\n\n";
		break;
	}
}