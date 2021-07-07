#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	char data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

int height(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + max(height(root->left), height(root->right));
}

void build(Node *&root, char *a, int sz)
{
	int i = 0;
	queue<Node *> q;
	char c = a[i++];
	root = new Node(c);
	q.push(root);

	while (!q.empty())
	{
		Node *n = q.front();
		q.pop();

		if (i < sz)
		{
			n->left = new Node(a[i]);
			q.push(n->left);
		}
		i += 1;
		if (i < sz)
		{
			n->right = new Node(a[i]);
			q.push(n->right);
		}
		i += 1;
	}
}

void levelorder(Node *root)
{
	queue<pair<Node *, int>> q;
	pair<Node *, int> p;
	Node *temp;
	int level;
	q.push({root, 1});
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		temp = p.first;
		level = p.second;

		cout << temp->data << " ";

		if (temp->left != NULL)
			q.push({temp->left, level + 1});

		if (temp->right != NULL)
			q.push({temp->right, level + 1});
	}
}

void spiralorder(Node *root)
{
	queue<pair<Node *, int>> q;
	pair<Node *, int> p;
	Node *temp;
	int level;
	q.push({root, 1});

	vector<char> v{root->data};

	while (!q.empty())
	{
		p = q.front();
		temp = p.first;
		level = p.second;

		if (level % 2 == 0)
		{
			cout << temp->data << " ";
			if (temp->left != NULL)
			{
				q.push({temp->left, level + 1});
				v.push_back(temp->left->data);
			}

			if (temp->right != NULL)
			{
				q.push({temp->right, level + 1});
				v.push_back(temp->right->data);
			}
			q.pop();
		}
		else
		{
			reverse(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i] << " ";
				p = q.front();
				q.pop();
				temp = p.first;
				level = p.second;
				if (temp->left != NULL)
					q.push({temp->left, level + 1});

				if (temp->right != NULL)
					q.push({temp->right, level + 1});
			}
			v.clear();
		}
	}
}

void printKthLevel(Node *root, int k)
{
	if (root == NULL)
	{
		return;
	}

	if (k == 1)
	{
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
	return;
}

void printAllLevels(Node *root)
{
	int H = height(root);

	for (int i = 1; i <= H; i++)
	{
		printKthLevel(root, i);
	}
}

void printKthLevelDir(Node *root, int k, int s)
{
	if (root == NULL)
	{
		return;
	}

	if (k == 1)
	{
		cout << root->data << " ";
		return;
	}

	if (s == 0)
	{
		printKthLevelDir(root->left, k - 1, s);
		printKthLevelDir(root->right, k - 1, s);
	}
	else
	{
		printKthLevelDir(root->right, k - 1, s);
		printKthLevelDir(root->left, k - 1, s);
	}
	return;
}

void printSpiral(Node *root)
{
	int H = height(root);

	for (int i = 1; i <= H; i++)
	{
		printKthLevelDir(root, i, i % 2);
	}
}

int main()
{
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

	Node *root = NULL;
	build(root, a, 9);
	cout << "Level Order: " << endl;
	printAllLevels(root);
	cout << endl
		 << "Level Order Iterative: " << endl;
	levelorder(root);
	cout << endl
		 << "Sprial Order: " << endl;
	printSpiral(root);
	cout << endl
		 << "Sprial Order Iterative: " << endl;
	spiralorder(root);
	return 0;
}