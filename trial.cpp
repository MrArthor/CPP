#include <iostream>

using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node *NextList;
};

class linked_list
{
public:
	Node *Head;
	int count;

	linked_list()
	{

		Head = NULL;
		count = 0;
	}

	Node *createNode(int n) //CREATE NODE
	{
		Node *tmp = new Node;
		tmp->data = n;
		tmp->next = NULL;
		count++;
		return tmp;
	}

	void insert_beg(int n) //INSERT AT THE BEGINNING
	{
		Node *Temp = createNode(n);

		Temp->next = Head;
		Head = Temp;
	}

	void insert_end(int n) //INSERT AT THE END
	{
		Node *Temp = createNode(n);
		if (Head == NULL)
		{
			Head = Temp;
		}
		else
		{
			Node *curr = Head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = Temp;
			count++;
		}
	}

	void MakeMultiLIst(Node *Head)
	{
		this->Head = Head;
	}

	void display() //DISPLAY NODE
	{
		cout << "\nList: ";
		Node *Temp = Head;
		while (Temp != NULL)
		{
			cout << Temp->data << " ";
			Temp = Temp->next;
		}
	}

	void del_beg()
	{
		if (Head == NULL)
			cout << "\nList is empty.";
		else
		{
			Node *Temp = Head;
			Head = Head->next;
			delete Temp;
		}
	}

	//search and return Node
};

int main()
{
	linked_list ll[2];

	return 0;
}
