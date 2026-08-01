#pragma once
#include<iostream>
#include"clsLinkedListCommon.h"
using namespace std;

template <class T>
class clsMyQueue :public clsLinkedListCommon<T>
{
public:

	void Push(T Item)
	{
		this->_MyList.InsertAtEnd(Item);
	}
	void Pop()
	{
		this->_MyList.DeleteFirstNode();
	}
	
	T Front()
	{
		return this->_MyList.GetItem(0);
	}
	T Back()
	{
		return this->_MyList.GetItem(this->Size() - 1);
	}
	
};

