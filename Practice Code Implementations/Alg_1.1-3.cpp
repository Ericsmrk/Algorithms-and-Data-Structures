// This program represents the code given
// in in the class textbook for algorithms:
// 1.1, 1.2, 1.4


//include statements is alg 1.2
#include <iostream> //use cout and cin
#include <chrono> // to use functions related to the time
#include <string> // use string operations
#include <tuple> // work with tuples
#include <fstream> // to use files
#include <algorithm> // use min and max functions
#include <stdlib.h> // use rand
#include <memory> // use unique_ptr

using namespace std;
int main(){

   cout << "alg1.1" << endl;
   //alg 1.1
   const int i = 12;
      int j, l = 12;
      // 1 = 13
      j = i;
      // 56 = i;
      j = 56;
      cout << ((j < 30) ? j : l) << endl;//returns an l value

   ///////////////////////////////////////////////////////////////////
   //alg 1.4  Static/Dynamic Arrays
   cout << endl << "alg1.4" << endl;

         //STATIC ARRAYS
   int s[5]; //array with 5 elements, can't be changed
   int primes[] = {1,2,3,5,7,11,13};//7 elements, can be changed
   int primes1[10] = {1,2,3,5,7};//size 10, first 5 initialized

         //DYNAMIC ARRAYS
   int n = 10;
   int *x = new int[n];//an array of size in
   cout << "Number of elements in Primes: ";
   cout << sizeof(primes)/sizeof(int) << endl;
   cout << "Number of elements in Primes1: ";
   cout << sizeof(primes1)/sizeof(int) << endl;
   cout << "Number of elements in x: ";
   cout << sizeof(*x)/sizeof(double) << endl << endl;
   delete[] x; //free up memory



   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;
   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;

   //cout << endl << "alg" << endl;
}
