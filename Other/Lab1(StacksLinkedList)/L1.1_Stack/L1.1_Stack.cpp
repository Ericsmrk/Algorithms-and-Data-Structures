//CSCi 115 --Lab 1.1
//Stack program
//Eric Smrkovsky
//9/1/2020

//This program is a stack that supports push, pop, peek, print and clear
//The stack is simulated in the form of an array
//When an array value is '-1' this means that the slot is considered empty

# include <iostream>
using namespace std;
const int STACKSIZE = 10; //size of the simulated stack
                //changing STACKSIZE will alter the size of the array throughout the class

class Stack {
    private:
        int stackTop;
        int myStack[STACKSIZE];
    public:
        void setTop();    //initializes stackTop variable to -1
        void clearStack();//initializes or clears stack and replaces with -1 values
        bool fullCheck(); //check to see if stack is full
        void push(int);   //push integers onto the stack(error checking)
        bool isEmpty();   //check to see if stack is empty
        int pop();        //pop the top-most element of the stack print it and return it(error checking)
        int peek();       //peek the top-most element of the stack and ONLY print it(error checking)
        void print();     //prints the contents of the simulated stack
};

//initializes stackTop variable to -1
void Stack::setTop(){

    stackTop = -1;
}

//initializes or clears stack and replaces with -1 values
void Stack::clearStack(){

    for(int i=0; i<=STACKSIZE; i++){
        myStack[i] = -1;//-1 serves as a signal to be an empty slot in the simulated stack
    }
}

//check to see if stack is full
bool Stack::fullCheck(){

    if(stackTop == STACKSIZE-1){
        return true;//if the top of the stack is equal to the size of the stack return true
    }
    else{
        return false;
    }
}

//check if stack is full, push integers onto the stack or display error message
void Stack::push(int num){

    if(!fullCheck()){//if stack is not full increment stacktop and insert argument into stack
        stackTop++;
        myStack[stackTop] = num;
    }
    else{//if the stack is full, push fails and error thrown and program exits
        cout << "\nError: Stack overflow!\n";
        exit(0);
    }
}

//check to see if stack is empty
bool Stack::isEmpty(){

    if(stackTop < 0){//checks if the stack top is less than the minimum array subscript
        return true;
    }
    else{
        return false;
    }

}

//pop the top-most element of the stack and print it
int Stack::pop(){

    if(isEmpty()){//if the stack is empty, pop fails and error thrown
        cout << "\nError: Stack underflow!\n";
        exit(0);
    }
    else{//if stack is not empty, display element, decrement stacktop and return value
        cout << "Popped item is " << myStack[stackTop] << endl;
        stackTop--;
        return myStack[stackTop+1];
    }
}

//peek the top-most element of the stack and ONLY print it
int Stack::peek(){

    if(isEmpty()){//if the stack is empty, peek fails and error thrown
        cout << "\nError: Stack is empty, can't peek!\n";
        exit(0);
    }
    else{//if stack is not empty, display element and return value without decrementing stack
        cout << "Peeked item is " << myStack[stackTop] << endl;
        stackTop--;
        return myStack[stackTop+1];
    }
}

//prints the contents of the simulated stack
void Stack::print(){

    if(isEmpty()){
        cout << "The stack is empty." << endl;
    }
    else{
        cout << "Items in the stack: ";

        for(int i=stackTop; i>=0; i--){ //loop checks every element in array

                cout << myStack[i];

                if(i > 0){
                    cout << ", " ; //adds commas after all but the last element
                }
                else{
                    cout << endl; //skips to next line if at end of array
                }
            }
        }
}


int main() {

    //Display name, class, date and small description
    cout << "----------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------\n";
    cout << "-----------          A Simple Stack Program          -----------\n";
    cout << "----------------------------------------------------------------\n";
    cout << "-------------------------------------------- Eric Smrkovsky ----\n";
    cout << "--------------------------------------------    9/1/2020    ----\n";
    cout << "--------------------------------------------    CSCi 115    ----\n";
    cout << "----------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------\n\n\n\n\n";

    Stack myStack;          //create object of Stack class
    myStack.setTop();       //set the stack top to -1
    myStack.clearStack();   //clear the stack from any values that don't belong
    cout << "...Creating stack and pushing values 20, 40 and 60 onto stack...\n\n";
    myStack.push(20);       //push the value 20 onto the stack
    myStack.push(40);       //push the value 40 onto the stack
    myStack.push(60);       //push the value 60 onto the stack
    myStack.print();        //print the items in the stack
    myStack.pop();          //pop the topmost value from stack(60)
    myStack.peek();         //peek the topmost value from stack(40)
    myStack.print();        //print the items in the stack
    cout << "\n\n\n\n";
}
