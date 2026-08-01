#pragma once
#include<iostream>
#include"clsDynamicArrCommon.h"
using namespace std;

template <class T>
class clsMyQueueArr :public clsDynamicArrCommon<T>
{
public:

	void Push(T Item)
	{
		this->_MyArr.InsertAtEnd(Item);
	}
	void Pop()
	{
		this->_MyArr.DeleteFirstItem();
	}

	T Front()
	{
		return this->_MyArr.GetItem(0);
	}
	T Back()
	{
		return this->_MyArr.GetItem(this->Size() - 1);
	}

};

