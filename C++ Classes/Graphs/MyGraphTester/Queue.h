//Lab 8/9 CSCI 115 Spring 2021
//Eric Smrkovsky
#pragma once

typedef double MyType;
class Queue{

public:
	Queue();
	Queue(int capacity1);
	~Queue();
	bool IsFull();
	bool IsEmpty();
	void Enqueue(MyType x);
	void EnqueueRear(MyType x);
	int numInserted();
	int numDequeued();
	MyType DequeueBack();
	MyType Dequeue();
	MyType Front();
	MyType Rear();
	void DisplayQueue();
	void DisplayAll();
private:
	int front, rear, size;
	int capacity;
	MyType* q;
	int insertCount;
	int dequeueCount;
};

