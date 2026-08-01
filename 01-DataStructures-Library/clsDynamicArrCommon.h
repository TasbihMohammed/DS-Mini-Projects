#pragma once
#include<iostream>
#include"clsMyDynamicArray.h"
using namespace std;
template <class T>
class clsDynamicArrCommon
{
protected:
	clsMyDynamicArray<T> _MyArr;

public:
	void Print()
	{
		_MyArr.Print();
	}
	int Size()
	{
		return _MyArr.Size();
	}
	bool IsEmpty()
	{
		return _MyArr.IsEmpty();
	}
	T GetItem(int Index)
	{
		return _MyArr.GetItem();
	}
	void Reverse()
	{
		_MyArr.Reverse();
	}
	void UpdateItem(int Index, T Val)
	{
		_MyArr.SetItem(Index, Val);
	}
	void InsertAfter(int Index, T Val)
	{
		_MyArr.InsertAfter(Index, Val);
	}
	void InsertAtFront(T Val)
	{
		_MyArr.InsertAtBeginning(Val);
	}
	void InsertAtBack(T Val)
	{
		_MyArr.InsertAtEnd(Val);
	}
	void Clear()
	{
		_MyArr.Clear();
	}
};

