//CSCi 115 --Lab 2
//Factorials, Fibonaccis and Hanoi tower
//Eric Smrkovsky
//1/29/2021
//Version: 1.0 (not done)

//PROGRESS: Compleeted all except for iterative version of towers of hanoi

//Cited: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
//Cited: https://www.mymathtables.com/numbers/100-factorial-tables-chart.html
//Cited: https://en.wikipedia.org/wiki/Tower_of_Hanoi
//Cited: Page 32 of Data Structures & Algorithms with C++ (class text)
//Cited: https://www.geeksforgeeks.org/iterative-tower-of-hanoi/

#include <iostream>
#include <chrono>
#include <math.h>
#include <algorithm>

using namespace std;
using namespace std::chrono;
//NOTE: all of these functions take a number 'n' as input.
//User is asked to specify which algorithm to test and provide a value for 'n'.
//Functions that return void display results and execution time of algorithm

//FUNCTION PROTOTYPES
void factForLoop(int);		//Display the nth factorial number using FOR loop
void factWhileLoop(int);		//Display the nth factorial number using WHILE loop
void factRecursive(int);		//Display the nth factorial number using recursion
unsigned long long factRec(int); //Helper function containing the recursion

void fibForLoop(int);		//Display the nth factorial number using FOR loop
void fibWhileLoop(int);		//Display the nth factorial number using WHILE loop
void fibRecursive(int);		//Display the nth factorial number using recursion
unsigned long long fibRec(int); //Helper function containing the recursion

void hanoiTowerRecursive(int);						//Hanoi tower using recursion (calls helper)
void hanoiTowerRec(int, string, string, string);//Helper function containing the recursion

//THESE 2 NOT FINISHED.. ALMOST!
void hanoiTowerNonRecursive(int);					//Iterative Hanoi tower algorithm (calls helper)
void hanoiTowerNonRec(int, string, string, string);//Helper function containing Hanoi algorithm

//MAIN FUNCTION
int main()

{	//this makes it possible to calculate up until the 20th fib
	unsigned long long factOutput = -1;
	// variables for function calls
	int n = -1, choice = -1, output = -1;
	int num1 = 1, num2 = 20;
	auto start = 0, stop = 0, duration = 0;

	cout << "---------------------------------------CSCi 115---Lab 2-------\n";
	cout << "---------------------------------------Eric Smrkovsky---------\n";
	cout << "---------------------------------------1/29/2021--------------\n";
	cout << "--------------------------------------------------------------\n";
	cout << "------------Factorials, Fibonacci's and Hanoi tower-----------\n";
	cout << "--------------------------------------------------------------";
	cout << "\n\n\n\nChoose which set of algorithms to run...\n";

	cout << "Press 1 for Factorial, 2 for Fibonacci, or...\n";
	cout << "Press 3 for Hanoi Tower with recursion, or...\n";
	//cout << "Press 4 for Hanoi Tower without recursion, or...\n";//NOT DONE!
	cin >> choice;		//get user input for function choice

	//get n value and run functions
	switch (choice)
	{
		case 1:
    	cout << "\nThe Factorial algorithms take a positive number 'n' as input...\n";
			cout << "Choose a positive value for n (from 1-20): ";
			cin >> n;
			if(n >= num1 && n <= num2){
				cout << "Good choice! Running Factorial(" << n << ").\n\n";
			}
			else{
				cout << "That won't work, lets choose 5 for n.\n\n";
				n = 5;
			}
			cout << "---Factorial(" << n << ")--------Output/Execution Time---\n";
			cout << "---with FOR:       ";
			factForLoop(n);
			cout << "\n---with WHILE:     ";
			factWhileLoop(n);
			cout << "\n---with RECURSION: ";
			factRecursive(n);
	  		break;

		case 2:
    	cout << "\nThe Fibonacci algorithms take a positive number 'n' as input...\n";
			cout << "WARNING: Choosing values for n past 45 could take hours or even days!\n";
			cout << "Choose a positive value for n (from 0-93): ";
			cin >> n;
			num1 = 0;
			num2 = 93;//ERROR SOMETIMES ASCII VALUE PRODUCES ERRORS
			if(n >= num1 && n <= num2){
				cout << "Good choice! Running Fibonacci(" << n << ").\n\n";
			}
			else{
				cout << "That won't work, lets choose 40 for n.\n\n";
				n = 40;
			}
			cout << "---Fibonacci(" << n << ")--------Output/Execution Time---\n";
			cout << "---with FOR:       ";
			fibForLoop(n);
			cout << "\n---with WHILE:     ";
			fibWhileLoop(n);
			cout << "\n---with RECURSION: ";
			fibRecursive(n);
	  		break;

    case 3:
    	cout << "\nThe Towers of Hanoi algorithms take a positive number of disks as input...\n";
			cout << "WARNING: Choosing a number of disks past 15 could take hours or even days!\n";
			cout << "Choose a positive number of disks (from 1-30): ";
			cin >> n;
			num1 = 0;
			num2 = 30;
			if(n >= num1 && n <= num2){
				cout << "Good choice! Running Towers_of_Hanoi(" << n << ").\n\n";
			}
			else{
				cout << "That won't work, lets choose 5 disks.\n\n";
				n = 5;
			}
			hanoiTowerRecursive(n);
	  		break;

//    case 4://NOT DONE!
//    	cout << "\nThe Towers of Hanoi algorithms take a positive number of disks as input...\n";
//			cout << "WARNING: Choosing a number of disks past 15 could take hours or even days!\n;
//			cout << "Choose a positive number of disks (from 1-30): ";
//			cin >> n;
//			num1 = 0;
//			num2 = 30;
//			if(n >= num1 && n <= num2){
//				cout << "Good choice! Running Towers_of_Hanoi(" << n << ").\n\n";
//			}
//			else{
//				cout << "That won't work, lets choose 5 disks.\n\n";
//				n = 5;
//			}
//			hanoiTowerNonRecursive(n);
//	  		break;

    default:
			cout << "Invalid selection, choosing Towers of Hanoi with recursion as default!" << endl;
    		cout << "\nThe Towers of Hanoi algorithms take a positive number of disks as input...\n";
			cout << "WARNING: Choosing a number of disks past 15 could take hours or even days!\n";
			cout << "Choose a positive number of disks (from 1-30): ";
			cin >> n;
			num1 = 0;
			num2 = 30;
			if(n >= num1 && n <= num2){
				cout << "Good choice! Running Towers_of_Hanoi(" << n << ").\n\n";
			}
			else{
				cout << "That won't work, lets choose 5 disks.\n\n";
				n = 5;
			}
			hanoiTowerRecursive(n);
	  		break;
	}
	 cout << "\n\n\n\n\n";
}//end main

//FUNCTION DEFINITIONS

/////////////////////////FACTORIAL/////////////////////////////////
//Find the nth factorial number using FOR loop
void factForLoop(int n) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1; //this size int can only go to fib(20)

	//CALCULATED USING FOR LOOP
	for(int i = 1; i <= n; i++)
		result *= i;

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";
}

//Find the nth factorial number using WHILE loop
void factWhileLoop(int n) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1;				//this size int can only go to fib(20)
	int i = 1;											//start counter at one

	//CALCULATED USING WHILE LOOP
	while(i <= n){
		result *= i;
		i++;
	}

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";

}

//Find the nth factorial number using recursion (CALLS HELPER FUNCTION)
void factRecursive(int n) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1; //this size int can only go to fib(20)

	//CALCULATED USING RECURSION BY CALLING HELPER FUNCTION
	result = factRec(n);

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";
}

//Helper function for recursion process in Factorial algorithm
unsigned long long factRec(int n){

	//Recursive Factorial algorithm
	if(n == 1)
		return(n);
	else
		return(n * factRec(n-1));
}

/////////////////////FIBONACCI///////////////////////////////

//Find the nth factorial number using FOR loop
void fibForLoop(int n) {	//can only hold up to 93rd fib number

	auto start = high_resolution_clock::now();//log start time

	unsigned long long result = 1, old = 0, older = 0;

	if(n < 2)//this handles the first two fib numbers
		result = n;

	//CALCULATED USING FOR LOOP
	for(int i = 2; i <= n; i++){
		old = older + result;
		older = result;
		result = old;
	}

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";
}

//Find the nth factorial number using WHILE loop
void fibWhileLoop(int n) {	//can only hold up to 93rd fib number

	auto start = high_resolution_clock::now();//log start time

	unsigned long long result = 1, old = 0, older = 0;
	int i = 2;

	if(n < 2)//this handles the first two fib numbers
		result = n;

	//CALCULATED USING WHILE LOOP
	while(n >= 2 && i <= n){
		old = older + result;
		older = result;
		result = old;
		i++;
	}

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";
}

//Find the nth factorial number using recursion
void fibRecursive(int n) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1; //this size int can only go to fib(20)

	//CALCULATED USING RECURSION BY CALLING HELPER FUNCTION
	result = fibRec(n);

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << result << "   " << duration.count() << " microseconds";
}

//Helper function for recursion process in Fib algorithm
unsigned long long fibRec(int n){

	//Recursive Fibonacci algorithm
	if(n <= 1)
		return(n);
	else
		return(fibRec(n-1) + fibRec(n-2));

}

//////////////////HANOI TOWER///////////////////////////////

//Hanoi tower function with recursion (just calls helper and clocks time)
void hanoiTowerRecursive(int disks) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1; //this size int can only go to fib(20)

	//CALCULATED USING RECURSION BY CALLING HELPER FUNCTION
	hanoiTowerRec(disks, "A", "B", "C");

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << "\n\n---Towers of Hanoi(" << disks << ") ran with RECURSION.\n";
	cout << "---Execution Time: " << duration.count() << " microseconds.\n\n";
}

//Helper function containing recursive algorithm
void hanoiTowerRec(int disks, string start, string aux, string dest){

	if(disks == 1)
		cout << "Move " << start << " to " << dest << "..."; //make only move
	else{//make necessary moves
		hanoiTowerRec(disks - 1, start, dest, aux);
		cout << "Move " << start << " to " << dest << "\n";
		hanoiTowerRec(disks - 1, aux, start, dest);
	}
}

//Hanoi tower algorithm without recursion (just calls helper[NOT DONE] and clocks time)
void hanoiTowerNonRecursive(int disks) {

	auto start = high_resolution_clock::now();//log start time
	unsigned long long result = 1; //this size int can only go to fib(20)

	//CALCULATED USING RECURSION BY CALLING HELPER FUNCTION
	hanoiTowerNonRec(disks, "A", "B", "C");

	auto stop = high_resolution_clock::now();//log end time
	//calculate the duration and cast to microseconds
	auto duration = duration_cast<microseconds>(stop - start);

	//display results
	cout << "\n\n---Towers of Hanoi(" << disks << ") ran without RECURSION.\n";
	cout << "---Execution Time: " << duration.count() << " microseconds.\n\n";

}

//NOT DONE
//Helper function containing iterative algorithm
void hanoiTowerNonRec(int disks, string start, string aux, string dest){

	int temp;
	int sTop = 1, aTop = 0, dTop = 0, zero = 0;
	int startCount = disks;
	int auxCount = 0, destCount = 0;
	int sizeArr[disks];
	// initialize array of sizes
	for(int i = 1; i <= disks; i++){//initialize array for disk sizes
		sizeArr[i] = i;
	}

	//First calculate total moves
	int totalMoves = (pow(2, disks)) - 1;
	cout << "total:" << totalMoves << endl;

	//If disks is even swap dest and aux contents
	if(disks % 2 == 0){

		string temp = dest;
		dest = aux;
		aux = temp;
	}

	//make moves until out of moves
	for(int i = 1; 1 <= totalMoves; i++){
		if(i % 3 == 1){ //make legal move between start/dest

			if(sTop > dTop && dTop != zero){
				cout << "Move " << dest << " to " << start << "...";
				temp = sTop;
				sTop = dTop;
				dTop = temp;
			}
			else{
				cout << "Move " << start << " to " << dest << "...";
				temp = dTop;
				dTop = sTop;
				sTop = temp;
			}
		}
		//break;
		else if(i % 3 == 2){ //make legal move between start/aux
			if(sTop > aTop && aTop != zero){
				cout << "Move " << aux << " to " << start << "...";
				temp = sTop;
				sTop = aTop;
				aTop = temp;
			}
			else{
				cout << "Move " << start << " to " << aux << "...";
				temp = aTop;
				aTop = sTop;
				sTop = temp;
			}
		}
		//break;
		else if(i % 3 == 0){ //make legal move between aux/dest
			if(dTop > aTop && dTop != zero){
				cout << "Move " << dest << " to " << aux << "...";
				temp = aTop;
				aTop = dTop;
				dTop = temp;
			}
			else{
				cout << "Move " << aux << " to " << dest << "...";
				temp = aTop;
				aTop = dTop;
				dTop = temp;
			}
		}
	}
}


