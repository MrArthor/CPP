#include <iostream>
#define Max 50
using namespace std;
template <class T>
class Deque
{
private:
    int Front, End, Count, Size;
    T Data[Max];

public:
    Deque(int size)
    {
        Front = End = -1;
        Count = 0;
        Size = size;
    }
    bool IsFull();
    bool IsEmpty();
    void insert_at_beg(T data);
    void insert_at_end(T data);
    T delete_from_beg();
    T delete_from_end();
    T front();
    void display();
    int size();
};
template <class T>
bool Deque<T>::IsFull()
{
    if (Front == -1 && End == Size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
bool Deque<T>::IsEmpty()
{
    if (Front == End && Front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Deque<T>::insert_at_beg(T data)
{
    bool r = IsFull();
    if (r == true)
        cout << "\nDeque is full.";
    else
    {

        if (End < Size - 1 && Front == -1)
        {
            for (int i = End; i >= Front; i--)
            {
                Data[i + 1] = Data[i];
            }
            Data[Front] = data;
            End++;
            Count++;
        }
        else
        {
            Data[Front] = data;
            Count++;
        }
    }
}
template <class T>
void Deque<T>::insert_at_end(T data)
{
    bool r = IsFull();
    if (r == true)
        cout << "\nDeque is full.";
    else
    {

        if (End < Size - 1)
        {
            Data[++End] = data;
            Count++;
        }
    }
}
template <class T>
T Deque<T>::delete_from_end()
{
    bool r = IsEmpty();
    if (r == true)
        cout << "\nDeque is empty.";
    else
    {
        cout << "Data Deleted= " << Data[End];
        T temp = Data[End];
        Data[End] = -2147483648;
        End--;
        Count--;
        return temp;
    }
}
template <class T>
T Deque<T>::delete_from_beg()
{
    bool r = IsEmpty();
    if (r == true)
        cout << "\nDeque is empty.";
    else
    {
        T temp = Data[Front];

        Data[Front++] = -2147483648;

        Count--;
        return temp;
    }
}
template <class T>
T Deque<T>::front()
{
    return Data[Front];
    //cout << "\nData At Front= " << Data[Front];
}
template <class T>
int Deque<T>::size()
{
    return Count;
    //cout << "\nData At Front= " << Data[Front];
}
template <class T>
void Deque<T>::display()
{
    for (int i = Front; i < End; i++)
    {
        cout << Data[i] << " ";
    }
}
int main()
{
    cout << "Enter the size of deque: ";
    int size;
    cin >> size;
    Deque<int> dd(size);
    int item;
    int choice;

    while (1)
    {
        cout << "\n1.Insert at the beginning of deque.";
        cout << "\n2.Insert at the end of deque.";
        cout << "\n3.Delete element from beginning.";
        cout << "\n4.Delete element from end.";
        cout << "\n5.Display first element.";
        cout << "\n6.Display all elements of queue.";
        cout << "\n7.Display the size.";
        cout << "\n8.Quit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter the data: \n";
            cin >> item;
            dd.insert_at_beg(item);
            break;
        case 2:
            cout << "\nEnter the data: \n";
            cin >> item;
            dd.insert_at_end(item);
            break;
        case 3:
        {
            int res = dd.delete_from_beg();
            cout << "\nData deleted: " << res;
            break;
        }
        case 4:
        {
            int res = dd.delete_from_end();
            cout << "\nData deleted: " << res;
            break;
        }
        case 5:
        {
            int res = dd.front();
            cout << "\nFront element: " << res;
            break;
        }
        case 6:
            dd.display();
            break;
        case 7:
        {
            int r = dd.size();
            cout << "\nSize of deque:" << r;
            break;
        }
        case 8:
            exit(1);

        default:
            cout << "Wrong choice \n";
        }
    }
    return 0;
}