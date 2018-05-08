#pragma once
#include"List.h"
#include"Vector.h"
//模板的模板参数
//template<class T,template<class> class container>
template<class T,class container>
class Stack {
public:
	void Push(const T& data)
	{
		con.PushBack(data);
	}
	void Pop()
	{
		con.PopBack();
	}
	T& Top()
	{
		return con.Back();
	}
	bool Empty()
	{
		return con.Empty();
	}
	size_t Size()
	{
		return con.Size();
	}
protected:
	container con;
};

void TestStack()
{
	Stack<int,Vector<int>> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	while (!s.Empty())
	{
		cout << s.Top() << " ";
		s.Pop();
	}
	cout << endl;

	Stack<string, Vector<string>> s1;
	s1.Push("11");
	s1.Push("22");
	s1.Push("33");
	s1.Push("44");
	while (!s1.Empty())
	{
		cout << s1.Top() << " ";
		s1.Pop();
	}
	cout << endl;

	Stack<int, List<int>> s2;
	s2.Push(1);
	s2.Push(2);
	s2.Push(3);
	s2.Push(4);
	s2.Push(5);
	while (!s2.Empty())
	{
		cout << s2.Top() << " ";
		s2.Pop();
	}
	cout << endl;
}