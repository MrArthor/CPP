#include <iostream>
using namespace std;

const int Size = 10;
int Q[Size];
void add(int Q[], int front, int &rear, int num)
{
    if ((rear + 1) % Size == front)
        cout << "Queue is full";
    else
    {
        rear = (rear + 1) % Size;
        Q[rear] = num;
    }
}
int del(int Q[], int &front, int rear)
{
    if (front == rear)
    {
        cout << "Empty Queue";
        return -1;
    }
    else
    {
        front++;
        int num = Q[front];
        return num;
    }
}
void show(int Q[], int front, int rear)
{
    int i = front;
    if (front == rear)
        cout << "Empty Queue";
    else
    {
        cout << "The queue contains :";
        while (i != rear)
        {
            i = (i + 1) % Size;
            cout << Q[i] << "lt";
        }
    }
}

int main()
{

    cout << "Hey";
    return 0;
}