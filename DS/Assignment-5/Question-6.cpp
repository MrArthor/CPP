#include <iostream>

using namespace std;
class Node
{
public:
    int Data;
    Node *Next;
};

class linked_list
{
public:
    Node *Head;
    int Count;

    linked_list()
    {

        Head = NULL;
        Count = 0;
    }

    Node *createNode(int n) //CREATE NODE
    {
        Node *tmp = new Node;
        tmp->Data = n;
        tmp->Next = NULL;
        Count++;
        return tmp;
    }

    void insert_beg(int n) //INSERT AT THE BEGINNING
    {
        Node *TempNode = createNode(n);

        TempNode->Next = Head;
        Head = TempNode;
    }

    void insert_end(int n) //INSERT AT THE END
    {
        Node *TempNode = createNode(n);
        if (Head == NULL)
        {
            Head = TempNode;
        }
        else
        {
            Node *curr = Head;
            while (curr->Next != NULL)
            {
                curr = curr->Next;
            }
            curr->Next = TempNode;
            Count++;
        }
    }

    Node *swap(Node *a1, Node *b1) //BUBBLE SORT
    {
        Node *tmp = b1->Next;
        b1->Next = a1;
        a1->Next = tmp;
        return b1;
    }

    void BubleSort(Node **Head, int c)
    {
        Node **h;
        for (int i = 0; i <= c; i++)
        {
            h = Head;

            for (int j = 0; j < c - i - 1; j++)
            {

                Node *a = *h;
                Node *b = a->Next;

                if (a->Data > b->Data)
                {
                    *h = swap(a, b);
                }

                h = &(*h)->Next;
            }
        }
    }

    void display() //DISPLAY NODE
    {
        cout << "\nList: ";
        Node *TempNode = Head;
        while (TempNode != NULL)
        {
            cout << TempNode->Data << " ";
            TempNode = TempNode->Next;
        }
    }

    void BubleSorting()
    {
        BubleSort(&Head, Count);
    }
    void selectionSort(Node *Head)
    {
        Node *TempNode = Head;

        while (TempNode)
        {
            Node *min = TempNode;
            Node *r = TempNode->Next;

            while (r)
            {
                if (min->Data > r->Data)
                    min = r;

                r = r->Next;
            }

            int x = TempNode->Data;
            TempNode->Data = min->Data;
            min->Data = x;
            TempNode = TempNode->Next;
        }
    }
    void SelectionSorting()
    {
        selectionSort(Head);
    }
    void del_beg() //DELETE FROM BEGINNING
    {
        if (Head == NULL)
            cout << "\nList is empty.";
        else
        {
            Node *TempNode = Head;
            Head = Head->Next;
            delete TempNode;
        }
    }
    void FrontBackSplit(Node *source,
                        Node **frontRef, Node **backRef)
    {
        Node *Fast;
        Node *Slow;
        Slow = source;
        Fast = source->Next;

        while (Fast != NULL)
        {
            Fast = Fast->Next;
            if (Fast != NULL)
            {
                Slow = Slow->Next;
                Fast = Fast->Next;
            }
        }

        *frontRef = source;
        *backRef = Slow->Next;
        Slow->Next = NULL;
    }
    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->Data <= b->Data)
        {
            result = a;
            result->Next = SortedMerge(a->Next, b);
        }
        else
        {
            result = b;
            result->Next = SortedMerge(a, b->Next);
        }
        return (result);
    }

    void MergeSort(Node **headRef)
    {
        Node *Head = *headRef;
        Node *a;
        Node *b;

        if ((Head == NULL) || (Head->Next == NULL))
        {
            return;
        }

        FrontBackSplit(Head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
    }

    void MergeSorting()
    {
        MergeSort(&Head);
    }
    void del_end() //DELETE FROM THE END
    {
        if (Head == NULL)
            cout << "\nList is empty.";
        else if (Head->Next == NULL)
            delete Head;
        else
        {
            Node *TempNode = Head;
            while (TempNode->Next->Next != NULL)
                TempNode = TempNode->Next;

            delete TempNode->Next;
            TempNode->Next = NULL;
        }
    }

    void QuickSorting()
    {
    }
};

int main()
{
    int n;
    cin >> n;
    linked_list LinkedList;

    for (int i = 0; i < n; i++)
    {
        int TempNode;
        cin >> TempNode;
        LinkedList.insert_end(TempNode);
    }

    LinkedList.display();
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        LinkedList.SelectionSorting();
        cout << "Linked List After Sorting ";
        LinkedList.display();
        break;
    case 2:
        LinkedList.BubleSorting();
        cout << "Linked List After Sorting ";
        LinkedList.display();
        break;
    case 3:
        LinkedList.MergeSorting();
        cout << "Linked List After Sorting ";
        LinkedList.display();
        break;
    case 4:
        LinkedList.QuickSorting();
        cout << "Linked List After Sorting ";
        LinkedList.display();
        break;
    default:
        cout << "Wrong Option ";
        break;
    }
    return 0;
}