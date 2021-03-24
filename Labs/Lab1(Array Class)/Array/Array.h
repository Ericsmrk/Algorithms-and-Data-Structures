//CSCi 115 --Lab 1
//An Array Class
//Eric Smrkovsky
//1/29/2021

#ifndef ARRAY_H
#define ARRAY_H

class Array
{
public:

    int arraySize; //size of array
    int* arrayData;//pointer to array

    Array();       //Default Constructor for the class
    Array(int);    //Copy Constructor with size
    Array(int, int*);//EXTRA EXTRA!Copy Constructor with size and data array
    ~Array();      //Destructor for the class

    int getSize();//Function to access the size
    void displayArray();//Display the content of the array
    void addToTop(int);//Function to Add an element at the beginning
    void addToBottom(int);//Function to Add an element at the end
    void removeFromTop();//Function to Remove an element at the beginning
    void removeFromBottom();//Function to Remove an element at the end
    void invertArray();//Function to Inverse the order of the elements in the array
    int returnSum();//Function to Return the sum of the elements in the array
    int* returnOdd();//Function to Return an array that contains the odd numbers only
    char* makeAsciArray(int);//EXTRA EXTRA!Function to create a char array with ascii characters
    void printCharArray(char*);//EXTRA EXTRA!Function to display the content of the char array
    void writeToFile(char*);//Function to Display the content of the array in a file
                            //through fstream
    int* operator+(const Array&) const;//Overload the + operator so you can concatenate
                            //2 arrays of size n and m into a new array of size n+m

};

#endif // ARRAY_H

