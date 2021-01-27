//Algorithm 1.5,1.6
#include <iostream>
using namespace std;


   void f1(int*, int);
   void f2(int**, int);
   int* f3(int);
   void displayArray(int*, int);

int main(){

   //tests
   int n = 10;
   int* a = nullptr;
   cout << "Evaluate f1" << endl;
   f1(a, n);
   //displayArray(a,n);
   cout << "Evaluate f2" << endl;
   f2(&a, n);
   displayArray(a,n);
   cout << "Evaluate f3" << endl;
   a = nullptr;
   a = f3(n);
   displayArray(a,n);
}

   void f1(int* a, int n){
      a = new int[n];
      for(int i = 0; i < n; i++)
         a[i] = i;
   }

   void f2(int** a, int n){
      *a = new int[n];
      for(int i = 0; i < n; i++)
         (*a)[i] = i;
   }

   int* f3(int n){
      int *a = new int[n];
      for(int i = 0; i < n; i++)
         a[i] = i;
      return a;
   }

   void displayArray(int* a, int n){
      for(int i = 0; i < n; i++)
         cout << a[i] << ",";
      cout << endl;
   }
