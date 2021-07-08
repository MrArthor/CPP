#include <bits/stdc++.h>

using namespace std;
int height(struct node *ptr)
{
	int h_left, h_right;

	if (ptr == NULL) /*Base Case*/
		return 0;

	h_left = height(ptr->lchild);
	h_right = height(ptr->rchild);

	if (h_left > h_right)
		return 1 + h_left;
	else
		return 1 + h_right;
}
int isAVL(struct node *ptr)
{
	int h_l, h_r, diff;
	if (ptr == NULL)
		return 1;
	h_l = height(ptr->lchild);
	h_r = height(ptr->rchild);
	diff = h_l > h_r ? h_l - h_r : h_r - h_l;
	if (diff <= 1 && isAVL(ptr->lchild) && isAVL(ptr->rchild))
		return 1;
	return 0;
}

int main()
{

	cout << "Hie Death";
	return 0;
}