#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template <class T>
class clsLinkedListCommon
{
protected:
	clsDblLinkedList<T> _MyList;

public:
	void Print()
	{
		_MyList.PrintList();
	}
	int Size()
	{
		return _MyList.Size();
	}
	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}
	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}
	void Reverse()
	{
		_MyList.Reverse();
	}
	void UpdateItem(int Index, T Val)
	{
		_MyList.UpdateItem(Index, Val);
	}
	void InsertAfter(int Index, T Val)
	{
		_MyList.InsertAfter(Index, Val);
	}
	void InsertAtFront(T Val)
	{
		_MyList.InsertAtBeginning(Val);
	}
	void InsertAtBack(T Val)
	{
		_MyList.InsertAtEnd(Val);
	}
	void Clear()
	{
		_MyList.Clear();
	}
};


