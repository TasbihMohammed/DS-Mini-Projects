#pragma once
#include<iostream>
#include<stack>
using namespace std;

class clsUndoRedo
{
private:
	string _Value;
	stack <string> _Undo;
	stack <string> _Redo;
public:
	void Set(string Val)
	{
		_Undo.push(_Value);
		_Value = Val;

		while (!_Redo.empty())
			_Redo.pop();
	}
	string Get()
	{
		return _Value;
	}
	__declspec(property(get = Get, put = Set)) string Value;
	 
	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}

	
};

