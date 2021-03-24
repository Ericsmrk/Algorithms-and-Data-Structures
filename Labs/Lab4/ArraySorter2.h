//CSCi 115 --Lab 4
//
//Eric Smrkovsky
//2/22/2021
//
//This lab uses arrays to implement the following algorithms:
//	Merge Sort
//	Quick Sort

#pragma once
class ArraySorter2{
	public:
		int *myArray;
		int sizeN;
		 
		~ArraySorter2();//default destructor frees up memory 
		ArraySorter2();	//default constructor initializes an array of size N 
						//with random numbers and stores that information 
						//in the proper variables
		
		void randomizeArray();	//fills the array with random numbers
		void displayArray();	//outputs array to the console
		void merge(int*, int, int, int); //merges two arrays in ascending order
		void mergeSort(int*, int, int);	 //performs selectionSort on myArray
		void quickSort(int*, int, int);	//performs insertionSort on myArray
		int partition(int*, int, int); //partitions the array using pivot
};

