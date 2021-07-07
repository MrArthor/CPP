#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T> *left;
	Node<T> *right;
	int is_succ;
	int is_pred;

	Node(T Data)
	{
		data = Data;
		left = NULL;
		right = NULL;
		is_succ = 0;
		is_pred = 0;
	}
};

template <typename T>
class BST
{

	Node<T> *root;
	int count;

public:
	BST()
	{
		root = NULL;
		count = 0;
	}
	Node<T> *createNode(T data);
	void insert(T data);
	void inorder();
	Node<T> *inorderSuccessor(Node<T> *ptr);
};

template <typename T>
Node<T> *BST<T>::createNode(T data)
{
	Node<T> *node = new Node<T>(data);
	return node;
}

template <typename T>
void BST<T>::insert(T data)
{
	Node<T> *temp = root;
	Node<T> *par = NULL;
	while (temp != NULL)
	{
		if (data == (temp->data))
		{
			cout << "\nDuplicate Node";
			return;
		}
		par = temp;

		if (data < temp->data)
		{
			if (temp->is_pred == 0)
				temp = temp->left;
			else
				break;
		}
		else
		{
			if (temp->is_succ == 0)
				temp = temp->right;
			else
				break;
		}
	}
	Node<T> *tmp = new Node<T>(data);
	tmp->is_pred = 1;
	tmp->is_succ = 1;

	if (par == NULL)
	{
		root = tmp;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	else if (data < (par->data))
	{
		tmp->left = par->left;
		tmp->right = par;
		par->is_pred = 0;
		par->left = tmp;
	}
	else
	{
		tmp->left = par;
		tmp->right = par->right;
		par->is_succ = 0;
		par->right = tmp;
	}
}

template <typename T>
void BST<T>::inorder()
{
	if (root == NULL)
		cout << "\nTree is empty";

	Node<T> *ptr = root;
	while (ptr->is_pred == 0)
		ptr = ptr->left;

	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = inorderSuccessor(ptr);
	}
}

template <typename T>
Node<T> *BST<T>::inorderSuccessor(Node<T> *ptr)
{
	if (ptr->is_succ == 1)
		return ptr->right;

	ptr = ptr->right;
	while (ptr->is_pred == 0)
		ptr = ptr->left;
	return ptr;
}

int main()
{
	BST<int> bst;
	int dval;
	char ch;
	int choice;

	while (1)
	{
		cout << "\n 1.Insertion by iterative.";
		cout << "\n 2.Inorder Traversal.";
		cout << "\n 3. Exit ";
		cout << "\n Enter your choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\nEnter the data:";
			cin >> dval;

			bst.insert(dval);
			break;
		}

		case 2:
		{
			cout << "\nInorder Traversal is :";
			bst.inorder();
			break;
		}
		case 3:
		{
			exit(0);
		}

		default:
		{
			cout << "\n\t Wrong Choice";
			break;
		}
		}
	}

	return 0;
}