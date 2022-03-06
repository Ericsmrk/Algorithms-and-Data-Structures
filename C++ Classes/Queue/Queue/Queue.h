#pragma once
typedef double MyType;
class MyQueue{

public:
	MyQueue();
	MyQueue(int capacity1);
	~MyQueue();
	bool IsFull();
	bool IsEmpty();
	void Enqueue(MyType x);
	int numInserted();
	int numDequeued();
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

