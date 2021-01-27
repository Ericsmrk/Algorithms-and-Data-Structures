//Algorithm 1.4
#include <iostream>
using namespace std;

int main(){

   //Static array
   int s[5]; // 5 elements only
   int primes[] = {1,2,3,4,5,6,7}; //7 elements only
   int primes1[10] = {1,2,3,4,5}; //size 10, 5 initialized
   int n = 10;
   int *x = new int[n]; //an array of n int
   cout << "Number of elements in primes: ";
   cout << sizeof(primes)/sizeof(int) << endl; // 7
   cout << "Number of elements in primes1: ";
   cout << sizeof(primes1)/sizeof(int) << endl; // 10
   cout << "Number of elements in primes: ";
   cout << sizeof(x);//sizeof(double) << endl; // 0
   delete[] x; // delete the array


}

