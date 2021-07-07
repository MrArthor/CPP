#include <bits/stdc++.h>

using namespace std;
template <class T>

class Node
{
public:
    Node *prev, *next;
    T data;
};
template <class t>
class DoubleLinkedList
{
public:
    int count;
    Node<t> *head, *Curr;

    DoubleLinkedList()
    {
        head = NULL;
        Curr = NULL;
        count = 0;
    }
    Node<t> *createNode(int n) //CREATE NODE
    {
        Node<t> *tmp = new Node<t>;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = NULL;
        count++;
        return tmp;
    }

    void insert_end(int n) //INSERT AT THE END
    {
        Node<t> *temp = createNode(n);
        if (head == NULL)
        {
            Curr = head = temp;
        }
        else
        {

            temp->prev = Curr;
            Curr->next = temp;
            Curr = temp;
        }
    }

    void display() //DISPLAY NODE
    {
        cout << "\nList: ";
        Node<t> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    //DoubleLinkedList<t> operator+(DoubleLinkedList<t> *List2)
};
int main()
{
    DoubleLinkedList<int> Dll;
    ;
    Node<int> *temp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Dll.insert_end(rand() % n + 1);
    }
    Dll.display();
    cout << endl;
    if (Dll.head)
    {
        temp = Dll.head;

        int rows = n;
        for (int i = 0; i < rows; i++)
        {
            temp = Dll.head;
            for (int space = 2; space <= (rows - i)&&temp; space++)
            {
                cout << "  ";
                temp = temp->next;
            }

            for (int j = 0; j <= i&&temp; j++)
            {

                cout << temp->data << "   ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    return 0;
}
