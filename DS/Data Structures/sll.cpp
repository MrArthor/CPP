#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head;
    int count;

    linked_list()
    {

        head = NULL;
        count = 0;
    }

    node *createNode(int n) //CREATE NODE
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        count++;
        return tmp;
    }

    void insert_beg(int n) //INSERT AT THE BEGINNING
    {
        node *temp = createNode(n);

        temp->next = head;
        head = temp;
    }

    void insert_between(int n, int position) //INSERT IN BETWEEN
    {
        node *temp = createNode(n), *nex = head;
        if (position <= count)
        {
            for (int i = 0; i < position - 1; i++)
            {
                nex = nex->next;
            }
            node *tempp = nex->next;
            nex->next = temp;
            temp->next = tempp;
        }
    }

    void insert_end(int n) //INSERT AT THE END
    {
        node *temp = createNode(n);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            count++;
        }
    }

    int LinearSearch(int n)
    {
        int pos = 1;
        node *temp = head;
        while (temp->next)
        {

            if (temp->data == n)
            {
                return pos;
            }
            else
            {
                temp = temp->next;
                pos++;
            }
        }
        return -1;
    }

    node *swap(node *a1, node *b1) //BUBBLE SORT
    {
        node *tmp = b1->next;
        b1->next = a1;
        a1->next = tmp;
        return b1;
    }

    void Sort(node **head, int c)
    {
        node **h;
        for (int i = 0; i <= c; i++)
        {
            h = head;

            for (int j = 0; j < c - i - 1; j++)
            {

                node *a = *h;
                node *b = a->next;

                if (a->data > b->data)
                {
                    *h = swap(a, b);
                }

                h = &(*h)->next;
            }
        }
    }

    void insert_sort(int n) //INSERT IN A SORTED LIST
    {
        node *temp = createNode(n);
        node *curr = head;

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
                node *nex = head;
                if (r <= count)
                {
                    for (int i = 0; i < r - 1; i++)
                    {
                        nex = nex->next;
                    }
                    node *tempp = nex->next;
                    nex->next = temp;
                    temp->next = tempp;
                }
            }
        }
    }

    void display() //DISPLAY NODE
    {
        cout << "\nList: ";
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void Sorting()
    {
        Sort(&head, count);
    }

    void del_beg()
    {
        if (head == NULL)
            cout << "\nList is empty.";
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void del_end()
    {
        if (head == NULL)
            cout << "\nList is empty.";
        else if (head->next == NULL)
            delete head;
        else
        {
            node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            delete temp->next;
            temp->next = NULL;
        }
    }

    void del_pos(int position)
    {
        node *temp = head;
        if (position <= count)
        {
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
            }
            node *tempp = temp->next;
            delete tempp;
            temp = temp->next;
        }
    }

    void del_by_element(int n)
    {
        node *temp = head;
        node *prev = head;
        while (temp->data != n && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data != n && temp->next == NULL)
        {
            cout << "\nElement not found.";
        }

        prev->next = temp->next;
        delete temp;
    }

    void reverse_list()
    {
        node *curr = head;
        node *prev = NULL, *next = curr->next;

        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        head = prev;
    }
    node *middle()
    {
        node *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    //search and return node
    node *SearchNode(int n)
    {
        node *temp = head;
        while (temp->next)
        {

            if (temp->data == n)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
            }
        }
        return NULL;
    }
    void unionll(linked_list l2)
    {
        node *temp2;
        temp2 = l2.head;

        while (temp2->next)
        {
            if (SearchNode(temp2->data) == NULL)
            {
                insert_end(temp2->data);
            }
            temp2->next;
        }
    }
    linked_list intersectionll(linked_list l2)
    {
        node *temp2, *temp1 = head;
        //temp1 = head;
        temp2 = l2.head;
        linked_list l3;

        while (temp2->next)
        {
            if (SearchNode(temp2->data))
            {
                l3.insert_end(temp2->data);
            }
            temp2->next;
        }

        return l3;
    }

    linked_list operator+(linked_list k2)
    {
        node *temp2 = k2.head, *temp = head;
        linked_list l3;
        while (temp)
        {
            l3.insert_end(temp->data);
            temp = temp->next;
        }
        while (temp2)
        {
            l3.insert_end(temp2->data);
            temp2 = temp2->next;
        }
        return l3;
    }
};
class sparse
{
public:
    int data, row, col;
    sparse *next;
};
class sparselinkedlist
{
public:
    sparse *head = NULL, *curr = NULL, *RevHead = NULL, *Curr = NULL;
    int count = 0;
    sparse *createNode(int a, int r, int c) //CREATE NODE
    {
        sparse *tmp = new sparse;
        tmp->data = a;
        tmp->col = c;
        tmp->row = r;
        tmp->next = NULL;
        count++;
        return tmp;
    }
    void insertelement(int A[][5], int Row, int Col) //o(n^2)
    {

        for (int i = 0; i < Row; i++)
        {

            for (int j = 0; j < Col; j++)
            {
                if (A[i][j] != 0)
                {
                    sparse *temp = createNode(A[i][j], i, j);
                    if (head == NULL)
                    {
                        curr = head = temp;
                    }
                    else
                    {
                        curr->next = temp;
                        curr = temp;
                        count++;
                    }
                }
            }
        }
    }
    void display()
    {
        sparse *temp = head;
        cout << endl;
        while (temp)
        {
            cout << temp->row << " " << temp->col << " " << temp->data;
            temp = temp->next;
            cout << endl;
        }
    }
    void deleteelement(int element)
    {
        sparse *temp = head, *prev = head;

        while (temp->next)
        {
            if (temp->data == element)
            {
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }

    sparse *sparseinput()
    {
        cout << "\nEnter Number Of Rows In Matrix \n";
        int numb;
        cin >> numb;
        sparse *temp;

        cout << "You Have To Enter Matrix Elements In Seq Of Row Column Data\n";
        for (int i = 0; i < numb; i++)
        {
            int a, c, r;
            cout << "Enter Row " << i + 1 << " Elements ";
            cin >> r >> c >> a;
            sparse *Temp = new sparse;
            Temp->data = a;
            Temp->col = c;
            Temp->row = r;
            Temp->next = NULL;
            //  cout << "\nI Am Bored \n";
            if (!RevHead)
            {
                //  cout << "\nI Am Bored \n";

                RevHead = Temp;
                Curr = Temp;
            }
            else
            {
                //    cout << "\nI Am Bored \n";

                Curr->next = Temp;
                Curr = Temp;
            }
        }

        return NULL;
    }
    int searchrowncol(int r, int j)
    {
        sparse *temp = RevHead;
        while (temp)
        {
            if (temp->row == r && temp && temp->col == j)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }

    int maxRow()
    {
        sparse *temp = RevHead;
        int max = 0;
        while (temp)
        {
            if (max < temp->row)
            {
                max = temp->row;
            }
            temp = temp->next;
        }
        return max + 1;
    }
    int maxCol()
    {
        sparse *temp = RevHead;
        int max = 0;
        while (temp)
        {
            if (max < temp->col)
            {
                max = temp->col;
            }
            temp = temp->next;
        }
        return max + 1;
    }
    void NonToZero()
    {
        sparse *temp = RevHead;

        int r = maxRow(), c = maxCol();
        cout << r << " " << c;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (searchrowncol(i, j) && temp)
                {

                    cout << temp->data << " ";
                    temp = temp->next;
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    linked_list ll[2]; //ll[0] ll[1]
    int n, i, n1;
    int choice;
    char ch;
    int result;
    sparselinkedlist Sparse;
    do
    {
        cout << "\n1.Insert at the beginning.";
        cout << "\n2.Insert at a position.";
        cout << "\n3.Insert at the end.";
        cout << "\n4.Linear Search.";
        cout << "\n5.Insert in a sorted list.";
        cout << "\n6 Union Of The Two Linked List ";
        cout << "\n7 Intersection of the two Linked List ";
        cout << "\n8 Middle of LinkedList without knowing count.";
        cout << "\n9. Merging Two Linked List";
        cout << "\n10 Deleting node by element value.";
        cout << "\n11 Deleting node by position value.";
        cout << "\n12 Deleting node by Begning Node";
        cout << "\n13 Deleting node by End Node";
        cout << "\n14 Searching Element And Returing Node";
        cout << "\n15 Reversing A Linked LIst";
        cout << "\n16 Add Sparse Matrix";
        cout << "\n17 Display Sparse Matrix";
        cout << "\n18 Delete Element Of Sparse Matrix";

        cout << "\n19 Enter Non Zero Sparse Matrix ";
        cout << "\n20 Print Normal Matrix Via Sparse Matrix";
        cout << "\nEnter your choice.";
        // cout << "\n choice for list ={0,1}\n";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "enter list number";
            cin >> i;
            cout << "\nEnter the data:";

            cin >> n;
            ll[i].insert_beg(n);
            ll[i].display();
            break;

        case 2:
            cout << "enter list number";
            cin >> i;
            cout << "\nEnter the data:";
            cin >> n;
            cout << "\nEnter the position where you want to enter:";
            cin >> n1;
            ll[i].insert_between(n, n1);
            ll[i].display();
            break;

        case 3:
            cout << "enter list number";
            cin >> i;
            cout << "\nEnter the data:";
            cin >> n;
            ll[i].insert_end(n);
            ll[i].display();
            break;

        case 4:
            cout << "enter list number";
            cin >> i;
            cout << "\nEnter the element to be searched:";
            cin >> n;
            result = ll[i].LinearSearch(n);
            if (result == -1)
                cout << "\nNot found.";
            else
                cout << "\nFound at: " << result;
            break;

        case 5:
            cout << "enter list number";
            cin >> i;
            cout << "\n Enter the data:";
            cin >> n;
            //ll[i].Sorting();
            cout << "\nSorted ";
            ll[i].display();
            ll[i].insert_sort(n);
            ll[i].display();
            break;
        case 6:
        {
            if (ll[0].head && ll[i].head)
            {
                cout << "Union of Two Linked List";
                ll[1].unionll(ll[0]);
                ll[1].display();
            }

            else
            {
                cout << "\nOne of the 2 lists are empty";
            }
            break;
        }
        case 7:
        {
            if (ll[0].head && ll[i].head)
            {
                cout << "intersection of Two Linked List";
                linked_list ll3 = ll[0].intersectionll(ll[1]);
                ll3.display();
            }
            else
            {
                cout << "\nOne of the 2 lists are empty";
            }
            break;
        }
        case 8:
        {
            cout << "\n Middle Of Linkedlist Without Knowing Size Of Linkedlist \n";
            cout << "enter list number";
            cin >> i;
            cout << ll[i].middle()->data;
            break;
        }
        case 9:
        {
            cout << "Merging Two Linked List \n";
            //ll[0].merge(ll[1]);
            ll[0] = ll[0] + ll[1];
            ll[0].display();

            break;
        }

        case 10:
        {
            cout << "Delete Node By Element Value";
            cout << "Enter The Element ";
            int element;
            cin >> element;
            ll[0].del_by_element(element);
            break;
        }
        case 11:
        {
            cout << "Delete Node By Position Value";
            cout << "Enter The Position ";
            int postion;
            cin >> postion;
            ll[0].del_pos(postion);
            break;
        }
        case 12:
        {
            cout << "Delete Node By begining Node";

            ll[0].del_beg();
            break;
        }
        case 13:
        {
            cout << "Delete Node By End Node";
            ll[0].del_end();
            break;
        }
        case 14:
        {
            cout << "\nSearching Element And Returning Node";
            cout << "\nEnter The Element ";
            int element;
            cin >> element;
            node *result = ll[0].SearchNode(element);
            break;
        }
        case 15:
        {
            cout << "\nReversing A Linked List \n";
            ll[0].reverse_list();
            break;
        }
        case 16:
        {
            cout << "Enter Number Of Rows And Column of Sparse Matrix";
            int r, c;
            int a[5][5];
            cin >> r >> c;
            cout << "enter matrix";

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    cin >> a[i][j];
                }
            }
            Sparse.insertelement(a, r, c);
            break;
        }
        case 17:
        {
            cout << "\nDisplay Sparse Matrix ";
            Sparse.display();
            break;
        }
        case 18:
        {
            cout << "Delete Element In Sparse Matrix";
            cout << "Enter Elemeent Which Is Supposed To Be Deleted";
            int d;
            cin >> d;
            Sparse.deleteelement(d);
            break;
        }
        case 19:
        {
            cout << "Non Zero Sparse Matrix ";
            Sparse.sparseinput();
            break;
        }
        case 20:
        {
            cout << "\nDisplay Matrix Created From Sparse Matrix \n";
            Sparse.NonToZero();
            cout << "hello word";
            break;
        }
        default:
            cout << "\nWrong choice.";
        }
        cout << "\nDo you want to continue?(y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
