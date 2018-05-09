#pragma once
#include"List.h"
#include"Vector.h"

template<class T,class Container>
class Queue {
public:
	void Push(const T& data)
	{   
		con.PushBack(data);
	}
	void Pop()
	{
		con.PopFront();
	}
	T& Top()
	{
		return con.Front();
	}
	bool Empty()
	{
		return con.Empty();
	}
protected:
	Container con;
};

void TestQueue()
{
	Queue<int, List<int>> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	while (!q1.Empty())
	{
		cout << q1.Top() << " ";
		q1.Pop();
	}
	cout << endl;

	Queue<string, List<string>> q2;
	q2.Push("11");
	q2.Push("22");
	q2.Push("33");
	q2.Push("44");

	while (!q2.Empty())
	{
		cout << q2.Top() << " ";
		q2.Pop();
	}
	cout << endl;
}
