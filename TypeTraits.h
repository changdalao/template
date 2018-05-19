#pragma once

#include<iostream>
using namespace std;

struct _TrueType {
	bool Get()
	{
		return true;
	}
};
struct _FalseType {
	bool Get()
	{
		return false;
	}
};

template <class T>
struct TypeTraits {
	typedef _FalseType IsPodType;
};
//特化
template <>
struct TypeTraits<int> {
	typedef _TrueType IsPodType;
};
//使用参数推导萃取处理
template<class T>
void TypeCopy(const T& src, T& dst, size_t size, _FalseType)
{
	cout << "opearator= " << endl;
}
template<class T>
void TypeCopy(const T& src, T& dst, size_t size, _TrueType)
{
	cout << "memcpy " << endl;
}

template<class T>
void Copy(const T& src, T& dst, size_t size)
{
	TypeCopy(src, dst, size,TypeTraits<T>::IsPodType());
}
void Test()
{
	string s1 = "123";
	string s2 = "456";
	Copy(s1, s2, 3);
	int a = 1;
	int b = 2;
	Copy(a, b, 1);
}
