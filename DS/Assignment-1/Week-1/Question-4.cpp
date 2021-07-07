#include <bits/stdc++.h>

using namespace std;
template <class T>
class Node
{
public:
    T Data;
    Node *Next;
};
template <class T>
class LinkedList : public Node<T>
{
private:
    Node<T> *Head;
    Node<T> *Current;

public:
    LinkedList()
    {
        Head = Current = NULL;
    //    Head->Next = Current->Next = NULL;
    }
    int InsertNode(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->Next = NULL;
        temp->Data = data;
        if (Head == NULL)
        {
            Head = temp;
            Current = temp;
        }
        else
        {
            Current->Next = temp;
            Current = temp;
        }
        return 0;
    }
    Node<T> *swap(Node<T> *a1, Node<T> *b1) //BUBBLE SORT
    {
        Node<T> *tmp = b1->Next;
        b1->Next = a1;
        a1->Next = tmp;
        return b1;
    }
    void Sort(Node<T> **head, int c = 0)
    {
        Node<T> **h;
        for (int i = 0; i <= c; i++)
        {
            h = head;

            for (int j = 0; j < c - i - 1; j++)
            {

                Node<T> *a = *h;
                Node<T> *b = a->Next;

                if (a->Data > b->Data)
                {
                    *h = swap(a, b);
                }

                h = &(*h)->Next;
            }
        }
    }
    void DeleteHead()
    {
        Node<T> *temp = Head;
        Head = temp->Next;
        cout << "\n"
             << temp->Data << endl;
        delete temp;
    }
    void Sor()
    {
        Sort(&Head);
    }
};
int main()
{

    int n;
    cout << "Enter The Value Of N ";
    cin >> n;
    LinkedList<int> ll;
    for (int i = 0; i < n; i++)
    {
        ll.InsertNode(rand() % n + 1);
    }
    ll.Sor();
    for (int i = 0; i < n; i++)
    {
        ll.DeleteHead();
    }
    return 0;
}