#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
public:
    Node *Next;
    T Data;
};
template <class T>
class Queue
{
    Node<T> *Head, *Curr;
    int Count;
    Node<T> *CreateNode(T data);

public:
    Queue()
    {
        Head = Curr = NULL;
        Count = 0;
    };
    //   Node<T> *CreateNode(T data);
    void EnQueue(T data);
    void DeQueue();
    void QueueSize();
    void QueueTop();
    void QueueDisplay();
    bool IsQueueEmpty();
};
template <class T>
Node<T> *Queue<T>::CreateNode(T data)
{
    Node<T> *Temp = new Node<T>;
    Temp->Data = data;
    Temp->Next = NULL;
    Count++;
    return Temp;
}
template <class T>
void Queue<T>::EnQueue(T data)
{
    Node<T> *Temp = CreateNode(data);
    if (IsQueueEmpty())
    {
        Head = Curr = Temp;
    }
    else
    {
        Curr->Next = Temp;
        Curr = Temp;
    }
}
template <class T>
void Queue<T>::DeQueue()
{
    Node<T> *Temp = Head;
    if (IsQueueEmpty())
    {
        cout << "\nQueue Is Already Empty \n";
    }
    else
    {
        cout << "\nData Dequeued= " << Head->Data;
        Head = Head->Next;
        delete Temp;
    }
}
template <class T>
bool Queue<T>::IsQueueEmpty()
{
    if (Head)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template <class T>
void Queue<T>::QueueSize()
{
    cout << "\nSize Of Queue== " << Count << endl;
}
template <class T>
void Queue<T>::QueueTop()
{
    cout << "\nTop Element Of Queue Is= " << Head->Data << endl;
}
template <class T>
void Queue<T>::QueueDisplay()
{
    Node<T> *Temp = Head;
    while (Temp)
    {
        cout << Temp->Data << " ";
        Temp = Temp->Next;
    }
}
int main()
{
    Queue<int> QQ;
    QQ.EnQueue(10);
    QQ.EnQueue(20);
    QQ.EnQueue(30);
    QQ.EnQueue(40);
    QQ.EnQueue(50);
    QQ.QueueSize();
    QQ.QueueTop();
    QQ.QueueDisplay();
    QQ.DeQueue();
    QQ.DeQueue();
    QQ.DeQueue();
    QQ.DeQueue();
    QQ.DeQueue();
    QQ.DeQueue();
    cout << "End Of Program :):";
    return 0;
}