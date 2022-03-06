#include "Queue.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "\n\nTesting Queue class\n\n";
    MyQueue* Q = new MyQueue(4);
    cout << "Empty: " << Q->IsEmpty() << endl;
    cout << "Full: " << Q->IsFull() << endl;
    Q->DisplayQueue();
    Q->Enqueue(4);
    Q->DisplayQueue();
    Q->DisplayAll();
    cout << "Empty: " << Q->IsEmpty() << endl;
    Q->Enqueue(6);
    Q->Enqueue(8);
    Q->Enqueue(10);
    cout << "Full: " << Q->IsFull() << endl;
    Q->DisplayQueue();
    Q->DisplayAll();
    Q->Enqueue(12);
    cout << "Full: " << Q->IsFull() << endl;
    Q->Enqueue(16);
    Q->DisplayQueue();
    Q->DisplayAll();
    Q->Enqueue(18);

    Q->DisplayQueue();
    Q->DisplayAll();
    
    cout << "Num of inserted: " << Q->numInserted() << endl;
    cout << "Num of dequeued: " << Q->numDequeued() << endl;
    cout << "Dequeue: " << Q->Dequeue() << endl;
    cout << "Dequeue: " << Q->Dequeue() << endl;
    Q->DisplayQueue();
    Q->DisplayAll();
    Q->Enqueue(20);
    Q->Enqueue(22);
    delete Q;


}