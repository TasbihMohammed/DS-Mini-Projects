#include <iostream>
#include "clsMyDynamicArray.h"
#include "clsMyStackArr.h"
#include "clsMyQueueArr.h"
#include "clsMyStack.h"
#include "clsMyQueue.h"

using namespace std;

int main()
{
    cout << "========== Dynamic Array ==========\n";

    clsMyDynamicArray<int> Arr;
    Arr.InsertAtEnd(10);
    Arr.InsertAtEnd(20);
    Arr.InsertAtEnd(30);
    Arr.Print();

    cout << "\n\n========== Stack (Array) ==========\n";

    clsMyStackArr<int> Stack;

    Stack.Push(5);
    Stack.Push(10);
    Stack.Push(15);
    Stack.Print();

    cout << "\nTop = " << Stack.Top();

    Stack.Pop();

    cout << "\nAfter Pop:\n";
    Stack.Print();

    cout << "\n\n========== Queue (Array) ==========\n";

    clsMyQueueArr<int> Queue;

    Queue.Push(100);
    Queue.Push(200);
    Queue.Push(300);
    Queue.Print();

    Queue.Pop();

    cout << "\nAfter Pop:\n";
    Queue.Print();

    cout << "\n\n========== Stack (Linked List) ==========\n";

    clsMyStack<int> LStack;

    LStack.Push(1);
    LStack.Push(2);
    LStack.Push(3);

    LStack.Print();

    cout << "\nTop = " << LStack.Top();

    cout << "\n\n========== Queue (Linked List) ==========\n";

    clsMyQueue<int> LQueue;

    LQueue.Push(11);
    LQueue.Push(22);
    LQueue.Push(33);

    LQueue.Print();

    cout << "\nFront = " << LQueue.Front();

    cout << "\n";

    return 0;
}