//CSCi 115 --Lab 2
//Fibonacci program
//Eric Smrkovsky
//9/12/2020

//This program includes three functions that will calculate the
//nth Fibonacci number. The recursive version is really slow and is
//considered an inefficient algorithm. The two iterative versions can
//calculate large fib numbers quickly. All three functions are only
//accurate to the 46th fib number because I wasn't able to find a
//way to return numbers larger then long long ints.

#include <iostream>
#include <ctime> //needed for the clock function
using namespace std;

//function prototypes
long long fib_rec(int);       //A recursive function to find the nth Fibonacci number
long long fib_it_arr(int);    //An iterative version of the Fibonacci function using an array
long long fib_it_temps(int);  //An iterative version of the Fibonacci function using temp variables


int main(){
//Variables
clock_t func_time;         //create variable of arithmetic type 'clock_t'
int input;             //for the n value of the function input
long long output;
char sel;                  //for user to select function

//display name, class, date and small description
cout << "----------------------------------------------------------------\n";
cout << "----------------------------------------------------------------\n";
cout << "-----------          A Fibonacci Program          -----------\n";
cout << "----------------------------------------------------------------\n";
cout << "-------------------------------------------- Eric Smrkovsky ----\n";
cout << "--------------------------------------------    9/12/2020    ----\n";
cout << "--------------------------------------------    CSCi 115    ----\n";
cout << "----------------------------------------------------------------\n";
cout << "----------------------------------------------------------------\n\n\n\n\n";

//ask for input
cout << "Recursive function (R)\nIterative function with array (A)\nIterative function with variables (V)\n";
cout << "\nPlease enter the letter of the Fibonacci function you would like to test: ";
cin >> sel;
cout << "Please note, this program only returns accurate results up to the 46th Fibonacci number\n";

//switch statement to handle user input calls appropriate code block to run functions
switch(sel){

    case 'R' ://CALLS RECURSIVE FIB
        cout << "\nEnter an input to test the recursive Fibonacci function...\n\n";
        cout << "Input: ";
        cin >> input;                                        //get input

        func_time = clock();                                 //record start time of function
        output = fib_rec(input);                             //call function

        if(input > 46){
            cout << "While execution time will be accurate for this input,\n";
            cout << "The result is incorrect due to an overflow of the long long int type.\n";
            }

        func_time = ((float)clock() - (float)func_time);     //record execution time

        cout << "Output: " << output << endl;                //display output
        cout << "Time: " << (float)func_time/CLOCKS_PER_SEC; //display execution time
        cout << " seconds.\n\n\n";
        break;

    case 'A' ://CALLS ITERATIVE FUNCTION USING ARRAY
        cout << "\nEnter an input to test the iterative Fibonacci function (uses arrays)...\n\n";
        cout << "Input: ";
        cin >> input;                                        //get input

        func_time = clock();                                 //record start time of function
        output = fib_it_arr(input);                          //call function

        if(input > 46){
            cout << "While execution time will be accurate for this input,\n";
            cout << "The result is incorrect due to an overflow of the long long int type.\n";
            }

        func_time = (clock() - func_time);                   //record execution time

        cout << "Output: " << output << endl;                //display output
        cout << "Time: " << (float)func_time/CLOCKS_PER_SEC; //display execution time
        cout << " seconds.\n\n\n";
        break;

    case 'V' ://CALLS ITERATIVE FUNCTION USING VARIABLES
          cout << "\nEnter an input to test the iterative Fibonacci function (uses variables)...\n\n";
        cout << "Input: ";
        cin >> input;                                        //get input

        func_time = clock();                                 //record start time of function
        output = fib_it_temps(input);                          //call function

        if(input > 46){
            cout << "While execution time will be accurate for this input,\n";
            cout << "The result is incorrect due to an overflow of the long long int type.\n";
            }

        func_time = (clock() - func_time);                   //record execution time

        cout << "Output: " << output << endl;                //display output
        cout << "Time: " << (float)func_time/CLOCKS_PER_SEC; //display execution time
        cout << " seconds.\n\n\n";
        break;

    default :
        cout << "Invalid input, please restart and try again.\n\n";
    }
}

//Function definitions

//Recursive Fibonacci function
//finds nth Fibonacci number by calling itself recursively
//takes an int as input and returns a double long
//checks if n is 0 or 1 then return n if so. this is the base case
//if n > 1 then the function calls itself until the base case is reached
long long fib_rec(int n){

    if(n == 0 || n== 1){//checks if n is 0 or 1 then return n if so. this is the base case
        return(n);
    }
    else{//if n > 1 then the function calls itself until the base case is reached
        return(fib_rec(n-1)+fib_rec(n-2));
    }
}

//An iterative version of the Fibonacci function using an array
//finds nth Fibonacci number iteratively by filling an array until the nth spot is reached
//takes an int as input and returns a double long
long long fib_it_arr(int n){

    int arr[n];         //create array of size n
    arr[0] = 0;         //set the element at position zero to zero
    arr[1] = 1;         //set the element at position one to one

    //populate the array from 2 to n until the loop counter reaches the nth position
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-2] + arr[i-1];
    }
    return(arr[n]);     //return the nth value of the array

}

//An iterative version of the Fibonacci function using temp variables
long long fib_it_temps(int n){

    int previous = 0;       //holds previous value
    int current = 1;        //holds current value
    int next;               //holds the next value

    //this loop starts at 2 and adds the current and previous to find the next Fib number,
    //then shifts the variables to make room for the next iteration
    for(int i = 2; i <= n; i++){
        next = previous + current;
        previous = current;
        current = next;
    }
    return(next);           //next variable is the nth Fib number
}
//end program
