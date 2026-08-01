#pragma once
#include<iostream>
#include"clsDynamicArrCommon.h"

template <class T>
class clsMyStackArr : public clsDynamicArrCommon<T>
{
public:
	void Push(T Val)
	{
		this->_MyArr.InsertAtBeginning(Val);
	}
	void Pop()
	{
		this->_MyArr.DeleteFirstItem();
	}
	T Top()
	{
		return this->_MyArr.GetItem(0);
	}
	T Bottom()
	{
		return this->_MyArr.GetItem(this->Size() - 1);
	}

};


