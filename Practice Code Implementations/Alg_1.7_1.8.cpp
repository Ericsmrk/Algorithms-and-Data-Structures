//Algorithm 1.7,1.8
#include <iostream>
using namespace std;

   int f0(int);
   int f1(int);
   void f2(int*);
   void f3(int*);
   void f4(int&);

int main(){

   int x = f0(5);
   cout << "f0->>>  x: " << x << endl;
   int y = f1(5);
   cout << "f1->>>  y: " << y << endl;
   int z = 6;
   f2(&z);
   cout << "f2->>>  z: " << z << endl;
   f3(&z);
   cout << "f3->>>  z: " << z << endl;
   f4(z);
   cout << "f4->>>  z: " << z << endl;
}

   int f0(int x){
      return x++; //x incremented after return
   }

   int f1(int x){
      return ++x; //x incremented before return
   }

   void f2(int* z){//pass mem address in f2(&z);
      cout << "z: " << z << "  " << "*z: " << *z << endl;
      *z++; //show mem address and data
      cout << "z: " << z << "  " << "*z: " << *z << endl;
      //show incremented mem address and data
      //BUT Z ONLY CHANGES WITHIN THE SCOPE OF THIS FUNCTION
   }

   void f3(int* z){//pass by pointer
      cout << "z: " << z << "  " << "*z: " << *z << endl;
      (*z)++; //show mem address and data
      cout << "z: " << z << "  " << "*z: " << *z << endl;
   }

   void f4(int& z){//pass by reference
      cout << "z: " << z << endl;
      z++; //show mem address and data
      cout << "z: " << z << endl;
   }
