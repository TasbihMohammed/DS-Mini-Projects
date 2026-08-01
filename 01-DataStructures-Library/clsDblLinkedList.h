#pragma once
#include<iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
	int _Size;

public:
	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};
	Node* Head = nullptr;

	void InsertAtBeginning(T Val)
	{
		Node* NewNode = new Node();
		NewNode->Value = Val;
		NewNode->Next = Head;
		NewNode->Prev = nullptr;
		if (Head != nullptr)
		{
			Head->Prev = NewNode;
		}
		Head = NewNode;

		_Size++;
	}
	void InsertAtEnd(T Val)
	{
		Node* NewNode = new Node();
		NewNode->Value = Val;
		NewNode->Next = nullptr;
		if (Head == nullptr)
		{
			Head = NewNode;
			NewNode->Prev = nullptr;
			return;
		}
		Node* Current = Head;
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
		NewNode->Prev = Current;

		_Size++;
	}
	void InsertAfter(Node* Current, T Val)
	{
		if (Current == nullptr) return;
		Node* NewNode = new Node();
		NewNode->Value = Val;
		NewNode->Prev = Current;
		NewNode->Next = Current->Next;

		if (Current->Next != nullptr)
		{
			Current->Next->Prev = NewNode;
		}
		Current->Next = NewNode;

		_Size++;
	}
	bool InsertAfter(int Index, T Val)
	{
		if (Index < 0 || Index >= _Size) return false ;
		Node* N = GetNode(Index);
		if (N != nullptr)
		{
			InsertAfter(N, Val);
			return true;
		}
		else return false;

		_Size++;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		if (Head == nullptr || NodeToDelete==nullptr) return;
		if (Head == NodeToDelete)
		{
			DeleteFirstNode();
			return;
		}
		if (NodeToDelete->Next != nullptr)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != nullptr)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;

		_Size--;
	}
	void DeleteFirstNode()
	{
		if (Head == nullptr) return;

		Node* temp = Head;
		Head = Head->Next;
		if (Head != nullptr) {
			Head->Prev = nullptr;
		}
		delete temp;

		_Size--;
	}
	void DeleteLastNode()
	{
		if (Head == nullptr) return;
		Node* Current = Head;
		if (Current->Next == nullptr)
		{
			Head = nullptr;
			delete Current;
			return;
		}
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		Current->Prev->Next = nullptr;
		delete Current;

		_Size--;
	}

	void PrintList()
	{
		Node* Current = Head;
		while (Current != nullptr)
		{
			cout << Current->Value << " ";
			Current = Current->Next;
		}
		cout << "\n";
	}
	Node* Find(T Val)
	{
		Node* Current = Head;

		while (Current != nullptr && Current->Value != Val)
		{
			Current = Current->Next;
		}

		return Current;
	}
	int Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{
		return (_Size == 0);
	}
	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}
	void Reverse()
	{
		Node* Current = Head;
		Node* Temp = nullptr;
		while (Current != nullptr)
		{
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;
			Current = Current->Prev;
		}
		if (Temp != nullptr)
		{
			Head = Temp->Prev;
		}
	}
	Node *GetNode(int Index)
	{
		if (Index < 0 || Index >= _Size) return nullptr;

		int Counter = 0;
		Node* Current = Head;
		while (Current != nullptr && Counter != Index)
		{
			Current = Current->Next;
			Counter++;
		}
		return Current;
	}
	T GetItem(int Index)
	{
		Node* N = GetNode(Index);
		if(N==nullptr) return T();

		return N->Value;
	}
	bool UpdateItem(int Index, T Val)
	{
		Node* N = GetNode(Index);
		if (N != nullptr)
		{
			N->Value = Val;
			return true;
		}
		else return false;
	}
};

