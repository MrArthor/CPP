#include <iostream>

using namespace std;
template <class T>

class Node
{
public:
	Node *prev, *next;
	T Data;
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
		tmp->Data = n;
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
			Node<t> *TempNext = previous->next; //0
			temp->prev = previous;				//1
			previous->next = temp;				//2
			temp->next = TempNext;				//3
		}
	}

	Node<t> *LinearSearch(int n) //LINEAR SEARCH
	{
		int pos = 1;
		Node<t> *temp = head;
		while (temp)
		{

			if (temp->Data == n)
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
	//Harkate band karde bht disturbance aarhi hai tri avaj nhi aarhi hai
	// void swap(t *a1, t *b1) //BUBBLE SORT
	// {
	// 	t *temp = a1;
	// 	a1 = b1;
	// 	b1 = temp;
	// }

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
				if (ptr1->Data > ptr1->next->Data)
				{
					swap(ptr1->Data, ptr1->next->Data);
					swapped = 1;
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped);
	}
	/*
Two Golden Rules Of Programming
	1. User Or Client Gawahar Hai Usko Kuch Nhi Aata
	2. Tumhri Faculty or Client Dono Same Bread Ke Log Hai
*/
	//isko last mai karenge abhi drame nhi chahiye zindagi mai

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

			while (curr->Data < n && r <= count)
			{
				curr = curr->next;
				r++;

				if (curr == NULL)
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
					temp->prev = previous;				//1
					previous->next = temp;				//2
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
			cout << temp->Data << " ";
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
		Node<t> Temp = List2->head;
		while (Temp)
		{

			insert_end(Temp->Data);
			Temp = Temp->next;
		}
	}
	DoubleLinkedList<t> operator+(DoubleLinkedList<t> *List2)
	{
		Node<t> Temp = List2->head;
		while (Temp)
		{

			insert_end(Temp->Data);
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
	void Union(DoubleLinkedList<t> *List2)
	{
		Node<t> Temp = List2->head;
		while (Temp)
		{
			if (!LinearSearch(Temp->Data))
			{
				insert_end(Temp->Data);
			}
			Temp = Temp->next;
			//Sort();
		}
	}
	DoubleLinkedList<t> *intersection(DoubleLinkedList<t> *List2)
	{
		Node<t> Temp = List2->head;
		DoubleLinkedList<t> *List3;
		while (Temp)
		{
			if (LinearSearch(Temp->Data))
			{
				List3->insert_end(Temp->Data);
			}
			Temp = Temp->next;
			//Sort();
		}
		return List3;
	}
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

	DoubleLinkedList<int> ll;

	do
	{
		cout << "\n1.Insert at the beginning.";
		cout << "\n2.Insert at a position.";
		cout << "\n3.Insert at the end.";
		cout << "\n4.Linear Search.";

		cin >> choice;

		switch (choice)
		{

		case 1:

			cout << "\nEnter the Data:";

			cin >> n;
			ll.insert_beg(n);
			ll.display();
			break;

		case 2:

			cout << "\nEnter the Data:";
			cin >> n;
			cout << "\nEnter the position where you want to enter:";
			cin >> n1;
			ll.insert_between(n, n1);
			ll.display();
			break;

		case 3:

			cout << "\nEnter the Data:";
			cin >> n;
			ll.insert_end(n);
			ll.display();
			break;

		case 4:
		{

			cout << "\nEnter the element to be searched:";
			cin >> n;
			Node<int> *Result = ll.LinearSearch(n);
			if (Result)
				cout << "\nNot found.";
			else
				cout << "\nFound " << endl;
			break;
		}
		case 5:

			cout << "\n Enter the Data:";
			cin >> n;
			//ll.Sorting();
			cout << "\nSorted ";
			ll.Sort();
			ll.display();

			ll.insert_sort(n);
			ll.display();
			break;
		default:
			cout << "\nWrong choice.";
		}
		cout << "\nDo you want to continue?(y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return 0;
}