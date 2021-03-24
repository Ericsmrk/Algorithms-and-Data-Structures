//CSCi 115 --Lab 4
//
//Eric Smrkovsky
//2/22/2021
//
//This lab uses arrays to implement the following algorithms:
//	Merge Sort
//	Quick Sort

#include <iostream>
#include <ctime>      //for time()
#include <cstdlib>  //for rand(), srand()   
#include <algorithm> //for swap()
#include "ArraySorter2.h"
using namespace std;

//default constructor initializes an array of size N with random numbers       
//and stores that information in the proper variables
ArraySorter2::ArraySorter2() {
    
    cout << "What size array to sort (1-100)? ";
    cin >> sizeN;                       //get size of array from user
    cout << "\n";
    if(sizeN >= 1 && sizeN <= 100){
        cout << "Input is good. ";
        cout << "Creating random array of size " << sizeN << ".\n";
    }
    else {
        cout << "Bad input.. Let's go with array of size 20.\n";
        sizeN = 20;
    }

    myArray = new int[sizeN];    //allocate memory to new array object

    //srand(time(0));     //seed random generator ONLY ONCE IN WHOLE PROGRAM
    srand(10);     //seed random generator ONLY ONCE IN WHOLE PROGRAM

    for (int i = 0; i < sizeN; i++) {
        myArray[i] = rand() % 100;   //make numbers less than 10 and fill array
    }    	
}

//default destructor 
ArraySorter2::~ArraySorter2() {

    delete[] myArray;     //Frees memory to prevent memory leaks
}

//fills the array with random numbers
void ArraySorter2::randomizeArray() {
    myArray = new int[sizeN];

    for (int i = 0; i < sizeN; i++) {
        myArray[i] = rand() % 100;   //make numbers less than 10 and fill array
    }
}

//outputs array to the console
void ArraySorter2::displayArray() {
    cout << "array contents: ";

    for (int i = 0; i < sizeN; i++)//loop displays all elements of array
        if (i == sizeN - 1)
            cout << myArray[i] << endl;
        else            //extra else case to display correct amount of commas
            cout << myArray[i] << ", ";
}

//performs MergeSort on myArray /// time complexity is  O(nlog(n))
void ArraySorter2::mergeSort(int* arr, int start, int end) {
    
    if (start < end) {
        int mid = (end + start) / 2;
        //devide
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        //conquer
        merge(arr, start, mid, end);
    }
}

//performs merge on an array sorting in ascending order 
void ArraySorter2::merge(int* arr, int start, int mid, int end) {
    
    //allocate memory and create temp arrays
    int size1 = mid - start + 1;    //add 1 to account starting at element 0
    int size2 = end - mid;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int i = 0, j = 0, k= start;     //to keep track of original array contents
    
    //initialize temp array 1 to first sub array
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[i + start];

    //initialize temp array 2 to first sub array
    for (int j = 0; j < size2; j++) 
        arr2[j] = arr[mid + j + 1];
    
    //compare values of arr1 and arr2 until the end of an array is reached 
    while (i < size1 && j < size2) {
        
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    //append the output array with the remaining values
    while (i < size1)
        arr[k++] = arr1[i++];

    while (j < size2)
        arr[k++] = arr2[j++];

    //free up memory used
    delete[] arr1;
    delete[] arr2;
}

//performs a partition on myArray (uses middle for pivot)
int ArraySorter2::partition(int* arr, int start, int end) {
    
    int pivot = arr[end];  //choose highest index for pivot value
    int low = start, hi = end-1;            //assign hi and lo index
    bool done = false;      //using a flag to leave while loop

    //find new partition value
    while (not done) {
        
        //while the value at index lo is < than pivot, advance 
        while (arr[low] < pivot)
            low++;
        
        //while the value at index hi is > than pivot, backtrack               
        while (arr[hi] > pivot && hi > start)
            hi--;
   
        //swap values if indexes cross
        if (hi > low)
            swap(arr[hi], arr[low]);
        else
            done = true;
    }    
    swap(arr[low], arr[end]);
    return low;
}

//performs QuickSort on myArray   ///    time complexity isO(nlog(n))
void ArraySorter2::quickSort(int* arr, int start, int end){
    
    if(start < end){

        //devide
        int newP = partition(arr, start, end); //get pivot for split
        //conquer
        quickSort(arr, start, newP - 1); //recursive call with left of pivot
        quickSort(arr, newP + 1, end); //recursive call with right of pivot
    }
}