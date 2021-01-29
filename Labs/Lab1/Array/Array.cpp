//CSCi 115 --Lab 1
//An Array Class
//Eric Smrkovsky
//1/29/2021

#include "Array.h"
#include <iostream>
#include <fstream>
using namespace std;

//Default Constructor for the class
Array::Array() {
    arraySize = 0;          //initialize default size of array
    arrayData = nullptr;    //assure that arrayData does not point to an object
}

//Copy Constructor with size
Array::Array(int size) {
    arraySize = size;                  //initialize size
    arrayData = new int[size];         //allocate memory
    for (int i = 0; i < arraySize; i++)//initialize array with subscript values
        arrayData[i] = i;
}

//Copy Constructor with size and data array
Array::Array(int size, int* data) {
    arraySize = size;                  //initialize size
    arrayData = new int[size];         //allocate memory
    for (int i = 0; i < arraySize; i++)//initialize array with subscript values
        arrayData[i] = data[i];
}

//Destructor for the class
Array::~Array() {   
    cout << "Destructor ran.\n";
    delete[] arrayData;     //Frees memory to prevent memory leaks
}

//Function to access the size
int Array::getSize() {
    return arraySize;       //output is size of array object
}

//Display the content of the array
void Array::displayArray() {
    cout << "Array contents: ";
    
    for (int i = 0; i < arraySize; i++)//loop displays all elements of array
        if (i == arraySize-1)
            cout << arrayData[i] << endl;
        else            //extra else case to display correct amount of commas
            cout << arrayData[i] << ", ";
}

//Function to Add an element at the beginning
void Array::addToTop(int newElement) {
    arraySize++;                        //increment size of object
    int* newArray = new int[arraySize]; //allocate memory for temp array
    newArray[0] = newElement;           //assign the new element to the start 
    
    for (int i = 1; i < arraySize; i++) //copy elements to temp variable
        newArray[i] = arrayData[i-1];   //elements in the correct position
    arrayData = newArray;  //replace old starting address of array with new one 
}

//Function to Add an element at the end
void Array::addToBottom(int newElement) {
    arraySize++;                        //increment size of object
    int* newArray = new int[arraySize]; //allocate memory for temp array
    
    for (int i = 0; i < arraySize; i++) //copy elements to temp variable
        newArray[i] = arrayData[i];     //elements in the correct position
    newArray[arraySize-1] = newElement; //assign the new element to the end
    arrayData = newArray;  //replace old starting address of array with new one 
}

//Function to Remove an element at the beginning
void Array::removeFromTop() {
    arraySize--;                        //decrement size of object
    int* newArray = new int[arraySize]; //allocate memory for temp array
    
    for (int i = 0; i < arraySize; i++) //copy elements to temp variable
        newArray[i] = arrayData[i+1];   //elements in the correct position
    arrayData = newArray;  //replace old starting address of array with new one 
}

//Function to Remove an element at the end
void Array::removeFromBottom() {
    arraySize--;                        //decrement size of object
    int* newArray = new int[arraySize]; //allocate memory for temp array
    
    for (int i = 0; i < arraySize; i++) //copy elements to temp variable
        newArray[i] = arrayData[i];     //elements in the correct position
    arrayData = newArray;  //replace old starting address of array with new one 
}

//Function to Inverse the order of the elements in the array
void Array::invertArray() {
    int tempSize = arraySize-1; //preserve record of array size by using a temp
    int* newArray = new int[arraySize];     //allocate memory for temp array
    
    for (int i = 0; tempSize >= 0; i++) {   //copy elements to temp variable
        newArray[i] = arrayData[tempSize];  //copy elements in correct position
        tempSize--;//decrement temp size, copying from end of original array
    }
    arrayData = newArray;  //replace old starting address of array with new one 
}

//Function to Return the sum of the elements in the array
int Array::returnSum() { 
    int sum = 0;                        //create variable to hold sum
    
    for (int i = 0; i < arraySize; i++) //update variable while traversing
        sum = sum + arrayData[i];       
    return sum;                         //return the variable holding sum
}

//Function to Return an array that contains the odd numbers only
int* Array::returnOdd() { 
    int newSize = 0;                        //variable to hold size of odd arry
    
    for (int i = 0; i < arraySize; i++) {   //loop to find odd elements
        if (arrayData[i] % 2 == 1)          //increment size var for each odd #
            newSize++;              
    }
    
    cout << "INPUT: " << newSize << endl;
    int* newArray = new int [newSize];      //allocate memory for temp array
    newSize = 0;                            //reset odd number counter
    
    for (int i = 0; i < arraySize; i++) {   //for each member of input array
        if (arrayData[i] % 2 == 1) {    //insert odd elements into new array
            newArray[newSize] = arrayData[i];
            newSize++;                  //increment counter
        }
    }
    return newArray; //return array with all of the odd elements
}

//function to make a char array of ascii characters
char* Array::makeAsciArray(int size) {
    char* charArray = new char[size];   //allocate memory for new char array

    for (int i = 0; i < size; i++) {
        charArray[i] = (char)50 + i;// adds elements to array starting with...
    }                           //ascii(50) to ascii(50+size)

    return charArray;// return an array of type char* filled with ascii chars
}

//Function to Display the content of the char array
void Array::printCharArray(char* arr) {
    cout << "Char Array contents: " << arr << endl;
}

//Function to Display the content of the array in a file
//through fstream
void Array::writeToFile(char* arr) {
    ofstream file;          //create file to represent output file stream
    file.open("ascii_output.txt");  //create and open new file
    file << "The contents of the ASCII array is: " << arr;//write contents
    file.close();                   //close the file
}

//Overload the + operator so you can concatenate 2 arrays of
//size n and m into a new array of size n+m
int* Array::operator+(const Array& array) const { 
    int nm = array.arraySize + this->arraySize; //add input sizes (n+m)
    int* nmArray = new int[nm];                 //create new array
    
    for (int i = 0; i < array.arraySize; i++) {//i counter starts at zero
        nmArray[i] = array.arrayData[i];//get data from first array object
    }

    int j = 0;                          //set counter for second array
    for (int i = array.arraySize; i < nm; i++) {//i continues from end of arr 1
        nmArray[i] = this->arrayData[j];//get data from second array object
        j++;  //loop stops when the total size of both array objects is reached
    }

    return nmArray; //returns new array of size n+m
}

