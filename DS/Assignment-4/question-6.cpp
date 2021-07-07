#include <bits/stdc++.h>
#define MAX 100
using namespace std;

template <class T>
class Stack
{
public:
    int top;
    T arr[MAX];
    int size;

    Stack(int s)
    {
        top = -1;
        size = s;
        //arr[s];
    }
    void push(T data);
    T pop();
    bool isFull();
    bool isEmpty();
    T peek();
    void display();
};
template <class T>
void Stack<T>::push(T data)
{
    bool r = isFull();
    if (r == true)
        cout << "\nStack is full.";
    else
    {
        top++;
        arr[top] = data;
    }
}

template <class T>
T Stack<T>::pop()
{
    bool r = isEmpty();
    if (r == true)
        cout << "\nStack is empty.";
    else
    {
        T x = arr[top];
        top--;
        return x;
    }
}

template <class T>
bool Stack<T>::isFull()
{
    if (top >= size - 1)
        return true;
    else
        return false;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (top < 0)
        return true;
    else
        return false;
}

template <class T>
T Stack<T>::peek()
{
    bool r = isEmpty();
    if (r == true)
        cout << "\nStack is empty";
    else
    {
        return arr[top];
    }
}

template <class T>
void Stack<T>::display()
{
    for (int i = 0; i < top + 1; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int S;
    cout << "\nEnter the size of stack.";
    cin >> S;
    Stack<int> st(S);
    int choice;
    int item;

    while (1)
    {
        cout << "\n1. Push in stack.";
        cout << "\n2. Pop from stack.";
        cout << "\n3. Display peek/top element.";
        cout << "\n4. Display entire stack.";
        cout << "\n5. Quit.";
        cout << "\nEnter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the element to be pushed:";
            cin >> item;
            st.push(item);
            break;

        case 2:
        {
            int r = st.pop();
            cout << "\nElement popped: " << r;
            break;
        }
        case 3:
        {
            int r = st.peek();
            cout << "\nElement at top: " << r;
            break;
        }
        case 4:
            st.display();
            break;

        case 5:
            exit(0);

        default:
            cout << "\nWrong choice.";
        }
    }
    return 0;
}
