#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
    int data;
    Node<T> *Next;
};
template <class T>

class MyVector
{
public:
    Node<T> *Head;
    int count;

    MyVector()
    {

        Head = NULL;
        count = 0;
    }

    Node<T> *createNode(int n) //CREATE NODE
    {
        Node<T> *tmp = new Node<T>;
        tmp->data = n;
        tmp->Next = NULL;
        count++;
        return tmp;
    }

    void Assign(int n, int position) //INSERT IN BETWEEN
    {
        Node<T> *temp = createNode(n), *nex = Head;
        if (position <= count)
        {
            for (int i = 0; i < position - 1; i++)
            {
                nex = nex->Next;
            }
            Node<T> *tempp = nex->Next;
            nex->Next = temp;
            temp->Next = tempp;
        }
    }

    void Push_Back(int n) //INSERT AT THE END
    {
        Node<T> *temp = createNode(n);
        if (Head == NULL)
        {
            Head = temp;
        }
        else
        {
            Node<T> *curr = Head;
            while (curr->Next != NULL)
            {
                curr = curr->Next;
            }
            curr->Next = temp;
        }
    }

    void display() //DISPLAY NODE
    {
        cout << "\nList: ";
        Node<T> *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->Next;
        }
    }

    void Pop_Back() //DELETE FROM THE END
    {
        if (Head == NULL)
        {
            cout << "\nList is empty.";
            return;
        }
        else if (Head->Next == NULL)
        {
            cout << endl
                 << Head->data;
            delete Head;
            Head = NULL;
            return;
        }
        else
        {
            Node<T> *temp = Head;
            while (temp->Next->Next != NULL)
                temp = temp->Next;
            cout << endl
                 << temp->data;
            delete temp->Next;
            temp->Next = NULL;
        }
        count--;
    }
    void Clear() //DELETE FROM THE END
    {
        if (Head == NULL)
        {
            cout << "\nList is empty.";
            return;
        }
        else if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
            return;
        }
        else
        {
            Pop_Back();
            Clear();
        }
    }

    void Erase(int position) //DELETE FROM A POSITION
    {
        Node<T> *temp = Head;
        if (position <= count)
        {
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->Next;
            }
            Node<T> *tempp = temp->Next;
            delete tempp;
            temp = temp->Next;
        }
        count--;
    }
    //Size Function Is Used to tell the current Size or NUmber of elements saved in myvector
    int Size()
    {
        return count;
    }
    //Resize Function Used To Increase Or Decrease the Storage Size  Of MyVector
    void Resize(int n)
    {
        if (n > count)
        {
            while (n >= count)
            {
                Push_Back(-1);
            }
        }
        else if (n < count)
        {
            Pop_Back();
        }
        else
        {
            cout << "\n\nSize of MyVector Is Already " << n;
        }
        cout << "Final ";
        display();
    }
};

int main()
{
    MyVector<int> ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll.Push_Back(rand() % (n + 1));
    }
    cout << endl
         << "Size Of MyVector= " << ll.Size();

    ll.display();
    int random = rand() % 10;
    cout << "\n\nRandom Position Selected To Insert Value Is " << random;
    ll.Assign(rand() % (n + 100), random);
    cout << endl;
    ll.display();
    //Pop_back Funtion Calling
    ll.Pop_Back();

    ll.Clear();
    ll.display();
    return 0;
}