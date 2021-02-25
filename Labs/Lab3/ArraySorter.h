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

#pragma once
class ArraySorter{
	public:
		int *myArray;
		int size;
		 
		ArraySorter();			//default constructor initializes an array of size 10 with random numbers and stores that information in the proper variables
		~ArraySorter();			//default destructor 
		void randomizeArray();	//fills the array with random numbers
		void displayArray();	//outputs array to the console
		void selectionSort();	//performs selectionSort on myArray
		void insertionSort();	//performs insertionSort on myArray
		void bubbleSort();		//performs bubbleSort on myArray
		int binarySearchIterative(int);//performs iterative binary search for the target, if found returns the index, else -1
		int binarySearchRecursive(int);//performs recursive binary search for the target by calling helper and returning result
		int binarySearchRecHelper(int, int, int);//performs recursive binary search for the target, if found returns the index, else -1
};

