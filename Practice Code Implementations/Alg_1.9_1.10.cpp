//Algorithm 1.9,1.10
#include <iostream>
using namespace std;

   void f5(int**, int);
   void f6(int*&, int);
   void f7(int*, int);
   void f8(int*);
   void f9(int&);

int main(){

   int *v1 = nullptr, *v2 = nullptr, *v3 = nullptr;
   int v4, v5;
   f5(&v2, 5);
   f6(v1, 5);
   f7(v3, 5);
   f8(&v4);
   f9(v5);
   cout << v1[3] << endl;
   cout << v2[3] << endl;
   //cout << v3[3] << endl;
   cout << v4 << endl;
   cout << v5 << endl;
}

//pass by pointer a variable v of type int*
   void f5(int** v, int n){
      *v = new int[n];
      for( int i = 0; i < n; i++)
         (*v)[i] = i;
   }

//pass by reference a variable v of type int*
   void f6(int* &v, int n){
      v = new int[n];
      for( int i = 0; i < n; i++)
         v[i] = i;
   }

//pass by value a variable v of type int*
   void f7(int* v, int n){
      v = new int[n];
      for( int i = 0; i < n; i++)
         v[i] = i;
   }

//pass by pointer a variable v of type int
   void f8(int* v){
      *v = 12;
   }

//pass by reference a variable v of type int
   void f9(int &v){
      v = 15;
   }
