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
    void insert_beg(int n) //INSERT AT THE BEGINNING
    {
        Node<t> *temp = createNode(n);
        if (!head)
        {
            temp->next = head;
            Curr = head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
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
    void insert_between(int n, int position) //INSERT IN BETWEEN
    {
        Node<t> *temp = createNode(n), *previous = head;
        if (position <= count)
        {
            for (int i = 0; i < position - 1; i++)
            {
                previous = previous->next;
            }
            Node<t> *TempNext = previous->next;
            temp->prev = previous;
            previous->next = temp;
            temp->next = TempNext;
        }
    }

    Node<t> *LinearSearch(int n) //LINEAR SEARCH
    {
        int pos = 1;
        Node<t> *temp = head;
        while (temp)
        {

            if (temp->data == n)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
        return NULL;
    }

    void Sort()
    {
        Node<t> *start = head;
        int swapped, i;
        Node<t> *ptr1;
        Node<t> *lptr = NULL;

        if (start == NULL)
            return;

        do
        {
            swapped = 0;
            ptr1 = start;

            while (ptr1->next != lptr)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void insert_sort(int n) //INSERT IN A SORTED LIST
    {
        Node<t> *temp = createNode(n);
        Node<t> *curr = head;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            int check = 0;
            int r = 0;

            while (curr->data < n && r <= count)
            {
                curr = curr->next;
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
                Node<t> *previous = head;
                if (r <= count)
                {
                    for (int i = 0; i < r - 1; i++)
                    {
                        previous = previous->next;
                    }
                    Node<t> *TempNext = previous->next; //0
                    temp->prev = previous;              //1
                    previous->next = temp;              //2
                    temp->next = TempNext;
                }
            }
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

    void DeletedAtEnd()
    {
        Node<t> *Temp = Curr;
        Curr = Curr->prev;
        delete Temp;
    }
    void DeleteAtStart()
    {
        Node<t> *Temp = head;
        head = head->next;
        delete Temp;
    }
    void DeleteByElement(t n)
    {
        Node<t> *Temp = LinearSearch(n);
        Temp->prev->next = Temp->next;
        delete Temp;
    }
    void DeleteByPosition(int Position)
    {
        if (Position < count)
        {
            Node<t> *Temp = head;
            for (int i = 0; i < Position; i++)
            {
                Temp->next;
            }
            Temp->prev->next = Temp->next;
            delete Temp;
        }
        else if (Position == 0)
        {
            DeleteAtStart();
        }
        else if (Position == count)
        {
            DeletedAtEnd();
        }
    }
    void merger(DoubleLinkedList<t> *List2)
    {
        Node<t> *Temp = List2->head;
        while (Temp)
        {

            insert_end(Temp->data);
            Temp = Temp->next;
        }
    }
    //DoubleLinkedList<t> operator+(DoubleLinkedList<t> *List2)
    DoubleLinkedList<t> operator+(DoubleLinkedList<t> *List2)
    {
        Node<t> *Temp = List2->head;
        while (Temp)
        {

            insert_end(Temp->data);
            Temp = Temp->next;
        }
    }
    Node<t> *middle() //MIDDLE ELEMENT WITHOUT KNOWING COUNT
    {
        Node<t> *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void Union(DoubleLinkedList<t> List2)
    {
        Node<t> *Temp = List2.head;
        while (Temp)
        {
            if (!LinearSearch(Temp->data))
            {
                insert_end(Temp->data);
            }
            Temp = Temp->next;
            //Sort();
        }
    }
    DoubleLinkedList<t> intersection(DoubleLinkedList<t> *List2)
    {
        Node<t> *Temp = List2->head;
        DoubleLinkedList<t> List3;
        while (Temp)
        {
            if (LinearSearch(Temp->data))
            {
                List3.insert_end(Temp->data);
            }
            Temp = Temp->next;
            //Sort();
        }
        return List3;
    }
    // void intersection(DoubleLinkedList<t> *List2)
    // {
    // 	Node<t> *Temp = List2->head;
    // 	DoubleLinkedList<t> List3;
    // 	while (Temp)
    // 	{
    // 		if (LinearSearch(Temp->data))
    // 		{
    // 			List3.insert_end(Temp->data);
    // 		}
    // 		Temp = Temp->next;
    // 		//Sort();
    // 	}
    // 	//return &List3;
    // 	List3.display();
    // }
    void reverse()
    {
        Node<t> *temp = head;
        head = Curr;
        Curr = temp;
    }
};
int main()
{

    int n, i, n1;
    int choice;
    char ch;
    int result;

    DoubleLinkedList<int> ll[2];

    do
    {
        cout << "\n1.Insert at the beginning.";
        cout << "\n2.Insert at a position.";
        cout << "\n3.Insert at the end.";
        cout << "\n4.Linear Search.";
        cout << "\n5.Insert in a sorted list.";
        cout << "\n6.Delete from the beginning.";
        cout << "\n7.Delete from the end.";
        cout << "\n8.Delete from a position.";
        cout << "\n9.Delete an element.";
        cout << "\n10.Reverse the list.";
        cout << "\n11.Merge two lists.";
        cout << "\n12.Merge two lists using + operator.";
        cout << "\n13.Union of two lists.";
        cout << "\n14.Intersection of two lists.";
        cout << "\n15.Middle element without knowing count";
        cout << "\nEnter your choice:";

        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the data:";
            cin >> n;
            ll[i].insert_beg(n);
            ll[i].display();
            break;

        case 2:

            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the data:";
            cin >> n;
            cout << "\nEnter the position where you want to enter:";
            cin >> n1;
            ll[i].insert_between(n, n1);
            ll[i].display();
            break;

        case 3:

            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the data:";
            cin >> n;
            ll[i].insert_end(n);
            ll[i].display();
            break;

        case 4:
        {
            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the element to be searched:";
            cin >> n;
            Node<int> *Result = ll[i].LinearSearch(n);
            if (Result)
                cout << "\nNot found.";
            else
                cout << "\nFound " << endl;
            break;
        }

        case 5:

            cout << "\nEnter the list number";
            cin >> i;
            cout << "\n Enter the data:";
            cin >> n;
            cout << "\nSorted ";
            ll[i].Sort();
            ll[i].display();
            ll[i].insert_sort(n);
            ll[i].display();
            break;

        case 6:

            cout << "\nEnter the list number";
            cin >> i;
            ll[i].DeleteAtStart();
            ll[i].display();
            break;

        case 7:

            cout << "\nEnter the list number";
            cin >> i;
            ll[i].DeletedAtEnd();
            ll[i].display();
            break;

        case 8:
        {
            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the Position: ";
            int position;
            cin >> position;
            ll[i].DeleteByPosition(position);
            ll[i].display();
            break;
        }

        case 9:
        {
            cout << "\nEnter the list number";
            cin >> i;
            cout << "\nEnter the element to be deleted: ";
            int element;
            cin >> element;
            ll[i].DeleteByElement(element);
            ll[i].display();
            break;
        }

        case 10:

            cout << "\nEnter the list number";
            cin >> i;
            ll[i].reverse();
            ll[i].display();
            break;

        case 11:

            cout << "\nMerging Two Linked List \n";
            ll[0] = ll[0] + &ll[1];
            ll[0].display();

            break;

        case 12:

            cout << "\nMerging using + operator.";
            ll[0].merger(&ll[1]);
            ll[0].display();
            break;

        case 13:
        {
            if (ll[0].head && ll[1].head)
            {
                cout << "Union of Two Linked List";
                ll[1].Union(ll[0]);
                ll[1].display();
            }

            else
            {
                cout << "\nOne of the 2 lists are empty";
            }
            break;
        }

        case 14:
        {
            if (ll[0].head && ll[i].head)
            {
                cout << "Intersection of Two Linked List";
                ll[0] = ll[0].intersection(&ll[1]);
                //ll[0].intersection(&ll[1]);
                ll[0].display();
            }
            else
            {
                cout << "\nOne of the 2 lists are empty";
            }
            break;
        }

        case 15:

            cout << "Enter the list number";
            cin >> i;
            cout << ll[i].middle()->data;
            break;

        default:
            cout << "\nWrong choice.";
        }
        cout << "\nDo you want to continue?(y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}