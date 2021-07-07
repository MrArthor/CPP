/*
Made By: -
Vansh Sachdeva 
19103194
B6
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	char val;
	Node *left = nullptr, *right = nullptr;
	Node(char val) : val(val) {}
};

void InOder(Node *Temp)
{
	if (!Temp)
		return;
	InOder(Temp->left);
	cout << Temp->val << " ";
	InOder(Temp->right);
}

void PostOrder(Node *Temp)
{
	if (!Temp)
		return;
	PostOrder(Temp->left);
	PostOrder(Temp->right);
	cout << Temp->val << " ";
}

Node *Contruct(string &s, int &i, int d)
{
	if (d == 0 or i < 0)
		return nullptr;

	Node *Temp = new Node(s[i--]);

	Temp->right = Contruct(s, i, d - 1);
	Temp->left = Contruct(s, i, d - 1);

	return Temp;
}

int main()
{
	string String = "HIDJKEBLMFNOGCA";

	int Size = String.size() - 1;
	int Height = log2(Size + 2);
	Node *Temp = Contruct(String, Size, Height);
	cout << "\nPostOrder Transversal: ";
	PostOrder(Temp);
	cout << "\n\nInOrder Transversal: ";
	InOder(Temp);
}