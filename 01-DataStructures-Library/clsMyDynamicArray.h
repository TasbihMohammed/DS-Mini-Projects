#pragma once
#include<iostream>
using namespace std;

template <class T>
class clsMyDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;
	void _Swap(T& A, T& B)
	{
		T Temp = A;
		A = B;
		B = Temp;
	}
public:
	T* OriginalArray;

	clsMyDynamicArray(int Size)
	{
		if (Size < 0) Size = 0;
		_Size = Size;

		OriginalArray = new T[_Size];
	}
	clsMyDynamicArray()
	{
	}
	~clsMyDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Val)
	{
		if (Index < 0 || Index >= _Size) return false;

		OriginalArray[Index] = Val;
		return true;
	}
	int Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{
		return (_Size == 0);
	}
	void Print()
	{
		for (int i = 0; i < _Size;i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}
	void Resize(int NewSize)
	{
		if (NewSize < 0) NewSize = 0;
		if (NewSize == _Size) return;

		_TempArray = new T[NewSize];

		int CopySize = min(_Size, NewSize);
		for (int i = 0; i < CopySize ; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	T GetItem(int Index)
	{
		if (Index > _Size) return T();
		return OriginalArray[Index];
	}
	void Reverse()
	{
		for (int i = 0; i < _Size/2 ; i++)
		{
			_Swap(OriginalArray[i], OriginalArray[(_Size-1) - i]);
		}
	}
	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0) return false;
		_Size--;
		_TempArray = new T[_Size];
		
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}
	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}
	int Find(T Val)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Val) return i;
		}
		return -1;
	}
	bool DeleteItem(T Val)
	{
		return DeleteItemAt(Find(Val));
	}
	bool InsertAt(int Index, T Val)
	{
		if (Index > _Size || Index < 0) return false;
		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i] ;
		}
		_TempArray[Index] = Val;
		for (int i = Index + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}
	bool InsertAtBeginning(T Val)
	{
		return InsertAt(0, Val);
	}
	bool InsertAtEnd(T Val)
	{
		return InsertAt(_Size , Val);
	}
	bool InsertBefore(int Index, T Val)
	{
		if (Index < 1) return InsertAt(0, Val);
		else return InsertAt(Index, Val);
	}
	bool InsertAfter(int Index, T Val)
	{
		if (Index >= _Size) return InsertAt(_Size, Val);
		else return InsertAt(Index + 1, Val);
	}
};

