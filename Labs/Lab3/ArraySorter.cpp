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
#include <ctime>      //for time()
#include <cstdlib>  //for rand(), srand()   
#include <algorithm> //for swap()
#include "ArraySorter.h"
using namespace std;

//default constructor initializes an array of size 10 with random numbers 
//and stores that information in the proper variables
ArraySorter::ArraySorter() {
  	size = 10;                      
    myArray = new int[size];    //allocate memory to new array object

    srand(time(0));     //seed random generator ONLY ONCE IN WHOLE PROGRAM

    for (int i = 0; i < size; i++) {
        myArray[i] = rand() % 100;      //make numbers less than 10 and fill array
    }    	
}

//default destructor 
ArraySorter::~ArraySorter() {

    delete[] myArray;     //Frees memory to prevent memory leaks
}

//fills the array with random numbers
void ArraySorter::randomizeArray() {
    myArray = new int[size];

    for (int i = 0; i < size; i++) {
        myArray[i] = rand() % 100;      //make numbers less than 10 and fill array
    }
}

//outputs array to the console
void ArraySorter::displayArray() {
    cout << "Array contents: ";

    for (int i = 0; i < size; i++)//loop displays all elements of array
        if (i == size - 1)
            cout << myArray[i] << endl;
        else            //extra else case to display correct amount of commas
            cout << myArray[i] << ", ";
}

//performs selectionSort on myArray ( O(n^2) worst case time complexity)
void ArraySorter::selectionSort() {
    int low = 0;                            //1. Set low to 0  

    for (int j = 0; j < size; j++) {        //5. Repeat 4 until entire list is sorted
        low = j;

        for (int i = j + 1; i < size; i++) {//4. Repeat 2 and 3 until entire sublist has been checked           

            if (myArray[i] < myArray[low])  //2. Find lowest value in array
                low = i;
        }
        if (low != j) {
            swap(myArray[j], myArray[low]); //3. Swap lowest element with current element
        }
    }
}

//performs insertionSort on myArray  ( Ο(n2) average and worst case time complexity)
void ArraySorter::insertionSort() {
    int j = 0;                              

    for (int i = 0; i < (size-1); i++) {        //4. Traverse entire array until sorted
        j = i + 1;                              //1. Find next element for insertion (j)
        
        while ((myArray[j-1] > myArray[j]) && (j >= 0)) {   //2. Compare (j-1) element with (j) element WHILE
                                                            //   backtracking to start of myArray
            swap(myArray[j-1], myArray[j]);     //3. if (j) element is smaller swap  
            --j;
        }
    }
}

//performs bubbleSort on myArray  ( Ο(n2) average and worst case time complexity)
void ArraySorter::bubbleSort() {
    for (int i = 0; i <= size; i++) {//3. Repeat 1 and 2 until entire array until sorted
        
        for (int j = 0; j < size-i-1; j++) {//2. Repeat 2 until entire sublist has been checked skipping last i elements
            
            if (myArray[j] > myArray[j + 1])//1. if (j) element is larger swap  
                swap(myArray[j], myArray[j + 1]);
        }
    }
}	

//performs iterative binary search for the target,
//if found returns the index, else -1 ( Ο(log n) time complexity) 
int ArraySorter::binarySearchIterative(int target) {
    int low = 0, mid = 0, high = size - 1, output = -1;
    
    while (low <= high) {
        mid = low + (high - low) / 2;    //calculat mid value to compare

        if (myArray[mid] == target)      //if we have a match return it's position 
            return mid;                  //FOUND TARGET VALUE return found position

        else if (target < myArray[mid])  //if target value is less then checked value 
            high = mid - 1;              //update high (splits array and keeps checking in bottom half)
        
        else                             //if target value is greater then checked value 
            low = mid + 1;               //update low (splits array and keeps checking in upper half)
    }
    return(-1);     //DID NOT FIND TARGET VALUE return (( -1 ))
}

//performs recursive binary search for the target by calling helper 
//and returning result ( Ο(log n) time complexity) 
int ArraySorter::binarySearchRecursive(int target) {
    
    return binarySearchRecHelper(target, 0, size -1);
}

//performs recursive binary search for the target, if found returns the index, else -1
int ArraySorter::binarySearchRecHelper(int target, int low, int high){
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;    //calculat mid value to compare

        if (myArray[mid] == target)      //if we have a match return it's position 
            return mid;                  //FOUND TARGET VALUE return found position

        else if (target < myArray[mid])  //if target value is less then checked value 
            return binarySearchRecHelper(target, low, mid - 1);//update high (splits array and keeps checking in bottom half)
            //high = mid - 1;              

        else                             //if target value is greater then checked value 
            return binarySearchRecHelper(target, mid + 1, high);
            //low = mid + 1;               //update low (splits array and keeps checking in upper half)
    }
    return(-1);     //DID NOT FIND TARGET VALUE return (( -1 ))
}




