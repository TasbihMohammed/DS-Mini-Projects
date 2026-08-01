#pragma once
#include<iostream>
#include"clsLinkedListCommon.h"

template <class T>
class clsMyStack : public clsLinkedListCommon<T>
{
public:
	void Push(T Val)
	{
		this->_MyList.InsertAtBeginning(Val);
	}
	void Pop()
	{
		this->_MyList.DeleteFirstNode();
	}
	T Top()
	{
		return this->_MyList.GetItem(0);
	}
	T Bottom()
	{
		return this->_MyList.GetItem(this->Size()-1);
	}
	
};

