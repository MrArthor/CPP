#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
    T Data;
    Node<T> *Next, *Prev;
};

template <class T>
class CircularLinkedList
{
public:
    Node<T> *Head, *Curr;
    int Count;
    CircularLinkedList()
    {
        Head = NULL;
        Curr = NULL;
        Count = 0;
    }
    Node<T> *createNode(int n) //CREATE NODE
    {
        Node<T> *tmp = new Node<T>;
        tmp->Data = n;
        tmp->Next = NULL;
        tmp->Prev = NULL;
        Count++;
        return tmp;
    }
    void insert_beg(int n) //INSERT AT THE BEGINNING
    {
        Node<T> *temp = createNode(n);
        if (!Head)
        {
            temp->Next = Head;
            Curr = Head = temp;
        }
        else
        {
            temp->Next = Head;
            Head = temp;
            Head->Prev = Curr;
        }
    }
    void insert_end(int n) //INSERT AT THE END
    {
        Node<T> *temp = createNode(n);
        if (Head == NULL)
        {
            Curr = Head = temp;
        }
        else
        {

            temp->Prev = Curr;
            Curr->Next = temp;
            Curr = temp;
            Curr->Next = Head;
            Head->Prev = Curr;
        }
    }
    void insert_between(int n, int position) //INSERT IN BETWEEN
    {
        Node<T> *temp = createNode(n), *Previous = Head;
        if (position == 0)
        {
            insert_beg(n);
        }
        else if (position == Count)
        {
            insert_end(n);
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                Previous = Previous->Next;
            }
            Node<T> *TempNext = Previous->Next;
            temp->Prev = Previous;
            Previous->Next = temp;
            temp->Next = TempNext;
        }
    }

    Node<T> *LinearSearch(int n) //LINEAR SEARCH
    {
        int pos = 1;
        Node<T> *temp = Head;
        while (temp)
        {

            if (temp->Data == n)
            {
                return temp;
            }
            else
            {
                temp = temp->Next;
                pos++;
            }
        }
        return NULL;
    }

    void Sort()
    {
        Node<T> *start = Head;
        int swapped, i;
        Node<T> *ptr1;
        Node<T> *lptr = NULL;

        if (start == NULL)
            return;

        do
        {
            swapped = 0;
            ptr1 = start;

            while (ptr1->Next != lptr)
            {
                if (ptr1->Data > ptr1->Next->Data)
                {
                    swap(ptr1->Data, ptr1->Next->Data);
                    swapped = 1;
                }
                ptr1 = ptr1->Next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void insert_sort(int n) //INSERT IN A SORTED LIST
    {
        Node<T> *temp = createNode(n);
        Node<T> *curr = Head;

        if (Head == NULL)
        {
            Head = temp;
        }
        else
        {
            int check = 0;
            int r = 0;

            while (curr->Data < n && r <= Count)
            {
                curr = curr->Next;
                r++;

                if (curr == nullptr)
                {
                    check = 1;
                    break;
                }
            }

            if (check == 1)
                insert_end(n);
            else
            {
                Node<T> *previous = Head;
                if (r <= Count)
                {
                    for (int i = 0; i < r - 1; i++)
                    {
                        previous = previous->Next;
                    }
                    Node<T> *TempNext = previous->Next; //0
                    temp->Prev = previous;              //1
                    previous->Next = temp;              //2
                    temp->Next = TempNext;
                }
            }
        }
    }

    void DeletedAtEnd() //DELETE FROM THE END
    {
        if (Head == Curr) // Curr==Head
        {
            Node<T> *Temp = Curr;
            Curr = NULL;
            Head = NULL;
            delete Temp;
        }
        else //Curr!=Head
        {
            Node<T> *Temp = Curr;
            Curr = Curr->Prev;
            Curr->Next = Head;
            Head->Prev = Curr;
            delete Temp;
        }
    }

    void DeleteAtStart()
    {
        Node<T> *Temp = Head;
        Head = Head->Next;
        Curr->Next = Head;
        delete Temp;
    }

    void DeleteByElement(T n) //DELETE AN ELEMENT
    {
        Node<T> *Temp = LinearSearch(n);
        if (Temp == Head)
        {
            Head = Temp->Next;
            Curr->Next = Head;
        }
        else
        {
            Temp->Prev = Temp->Next;
        }

        delete Temp;
    }
    void DeleteByPosition(int Position) //DELETE FROM A POSITION
    {
        cout << Count << endl;
        if (Position == 0)
        {
            DeleteAtStart();
        }
        else if (Position == Count)
        {
            DeletedAtEnd();
        }
        else if (Position < Count)
        {
            Node<T> *Temp = Head;
            for (int i = 0; i < Position; i++)
            {
                Temp = Temp->Next;
            }
            Temp->Prev->Next = Temp->Next;
            delete Temp;
        }
    }
    void display() //DISPLAY
    {
        cout << "\nList: ";
        Node<T> *Temp = Head;
        do
        {
            if (Temp->Next == Head)
            {
                cout << Temp->Data;
                break;
            }

            else
            {
                cout << Temp->Data << " ";
                Temp = Temp->Next;
            }

            //} while (Temp && Temp->Next != Head);
        } while (Temp);
    }
};
int main()
{

    int n, i, n1;
    int choice;
    char ch;
    int result;

    CircularLinkedList<int> ll;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll.insert_beg(rand() % n + 1);
    }
    ll.display();
    // ll.insert_sort();
    ll.Sort();
 //   ll.display();
    for (int i = 0; i < n; i++)
    {
        ll.DeleteAtStart();
       // ll.display();
    }
    return 0;
}