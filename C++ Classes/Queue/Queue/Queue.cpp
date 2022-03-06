# include <iostream>
#include "Queue.h"
using namespace std;

MyQueue::MyQueue(){
	capacity = 0;
	front = size = 0;
	rear = capacity -1;
	q = nullptr;
	insertCount = 0;
	dequeueCount = 0;
}

MyQueue::MyQueue(int capacity1){
	capacity = capacity1;
	front = size = 0;
	rear = capacity -1;
	q = new MyType[capacity];
	insertCount = 0;
	dequeueCount = 0;
}

MyQueue::~MyQueue(){
	delete[] q;
}

//Returns true if the Queue has reached it's capacity
bool MyQueue::IsFull(){
	return (size == capacity);
}

//Returns true if the Queue is empty
bool MyQueue::IsEmpty(){
	return ( size == 0);
}


void MyQueue::Enqueue(MyType x){
	if (not IsFull()) {
		insertCount++;
		rear = (rear + 1) % capacity;
		q[rear] = x;
		size++;
	}
}

int MyQueue::numInserted() {
	return insertCount;
}

int MyQueue::numDequeued() {
	return dequeueCount;
}

MyType MyQueue::Dequeue(){
	if (IsEmpty())
		return INT_MIN;
	MyType item = q[front];
	front = (front + 1) % capacity;
	size--;	
	return item;
}

MyType MyQueue::Front(){
	if (IsEmpty())
		return INT_MIN;
	return q[front];
}

MyType MyQueue::Rear(){
	if (IsEmpty())
		return INT_MIN;
	return q[rear];
}


//Display all elements in order that should be dequeued
void MyQueue::DisplayQueue() {
	if (IsEmpty())
		cout << "\nEmpty Queue!!\n";
	cout << "Size of queue: " << size << endl;
	for (int i = 0; i < size; i++)
		cout << "Element: " << q[(front + i) % capacity] << " at position " << i << endl;
	cout << endl;
}

//Display all elements in q sorted
void MyQueue::DisplayAll(){
	if (IsEmpty())
		cout << "\nEmpty Queue!!\n";
	cout << "Capacity of queue: " << capacity << endl;
	for (int i = 0; i < capacity; i++)
		cout << "Element: " << q[i] << " at position " << i << endl;
	cout << endl;
}
