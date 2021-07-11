#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right, *bottom;
};
node *newnode(int d)
{
    node *temp = new node();
    temp->data = d;
    temp->right = temp->bottom = NULL;
    return temp;
}
void Insert(node *&root, node *temp)
{
    if (!root)
    {
        root = temp;
    }
    else
    {
        node *p = root;
        while (p->right)
        {
            p = p->right;
        }
        p->right = temp;
    }
    return;
}
int main()
{
    int r, c;
    cout << "enter no. ofstudent" << endl;
    cin >> r;
    cout << "enter no ofsubject" << endl;
    cin >> c;
    node *head[r];
    for (int i = 0; i < r; i++)
    {
        head[i] = NULL;
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int n;
            cin >> n;
            node *temp = newnode(n);
            Insert(head[i], temp);
            n++;
        }
    }
    for (int i = 0; i < r - 1; i++)
    {
        node *p = head[i], *q = head[i + 1];
        while (p && q)
        {
            p->bottom = q;
            p = p->right;
            q = q->right;
        }
    }
    cout << "column wise traversal" << endl;
    for (int i = 0; i < c; i++)
    {
        node *p = head[0];
        int k = i;
        while (k--)
        {
            p = p->right;
        }
        while (p)
        {
            cout << p->data << " ";
            p = p->bottom;
        }
        cout << endl;
    }
    int max_fail = 0, sub = 0;
    for (int i = 0; i < c; i++)
    {
        int fail = 0;
        node *temp = head[0];
        int k = i;
        while (k--)
        {
            temp = temp->right;
        }
        while (temp)
        {
            if (temp->data < 50)
            {
                fail++;
            }
            temp = temp->bottom;
        }
        if (max(max_fail, fail) == fail)
        {
            max_fail = fail;
            sub = i + 1;
        }
    }
    cout << "maximum students failed in subject " << sub << " "
         << "i.e. " << max_fail << endl;
    int max_marks = 0, stu = 0;
    for (int i = 0; i < r; i++)
    {
        int marks = 0;
        node *temp = head[i];
        while (temp)
        {
            marks += temp->data;
            temp = temp->right;
        }
        if (max(max_marks, marks) == marks)
        {
            max_marks = marks;
            stu = i + 1;
        }
    }
    cout << "topper :-" << stu << " scoring " << max_marks << "/500 " << endl;


    return 0;
}