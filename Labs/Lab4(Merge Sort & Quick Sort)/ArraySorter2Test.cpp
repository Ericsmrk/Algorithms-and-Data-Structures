//CSCi 115 --Lab 4
//
//Eric Smrkovsky
//2/22/2021
//
//This lab uses arrays to implement the following algorithms:
//	Merge Sort
//	Quick Sort

#include <iostream>
#include "ArraySorter2.h"
using namespace std;

int main() {
	int choice = -1;			//show title, get input for program choice
	cout << "--------------------------------------------------------------\n";
	cout << "----MergeSort-------------------------CSCi 115---Lab 4--------\n";
	cout << "----QuickSort-------------------------Eric Smrkovsky----------\n";
	cout << "--------------------------------------2/12/2021---------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "--------------------------------------------------------------";
	cout << "\n\nThis program will produce random unsorted arrays of size N\n";
	cout << "and sort them with the above sorting algorithms.\n\n";
	cout << "Press 1 to test MergeSort or 2 for QuickSort: ";
	cin >> choice;
	cout << "\n";

	//if bad choice tell user going to default
	if (choice != 1 && choice != 2)
		cout << "Invalid choice... So... I guess I'll test both for you.\n";

	//create array object with constructor and display array
	ArraySorter2 array;

	switch (choice)
	{
	case 1:

		cout << "Unsorted ";
		array.displayArray();		 //display unsorted array
		cout << "Sorting with MergeSort...\n";
		array.mergeSort(array.myArray, 0, array.sizeN - 1);//call MergeSort
		cout << "Sorted ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to random elements

		cout << "\n\n\n";
		break;

	case 2:

		cout << "Unsorted ";
		array.displayArray();		 //display unsorted array
		cout << "Sorting with QuickSort...\n";
		array.quickSort(array.myArray, 0, array.sizeN - 1);//call QuickSort
		cout << "Sorted ";
		array.displayArray();		//display sorted array

		cout << "\n\n\n";		
		break;

	default:

		cout << "\nTESTING SORTING ALGORITHMS\n\n";

		//running MergeSort
		cout << "Unsorted ";
		array.displayArray();		 //display unsorted array
		cout << "Sorting with MergeSort...\n";
		array.mergeSort(array.myArray, 0, array.sizeN - 1);//call MergeSort
		cout << "Sorted ";
		array.displayArray();		//display sorted array
		array.randomizeArray();		//reinitialize array to random elements

		cout << "\n\n\n";

		//running QuickSort
		cout << "Unsorted ";
		array.displayArray();		 //display unsorted array
		cout << "Sorting with QuickSort...\n";
		array.quickSort(array.myArray, 0, array.sizeN - 1);//call QuickSort
		cout << "Sorted ";
		array.displayArray();		//display sorted array

		cout << "\n\n\n";
		break;
	}
}
