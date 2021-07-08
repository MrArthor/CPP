#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    Node<T> *lchild;
    int data;
    Node<T> *rchild;
};
template <class T>
class BST
{
public:
    Node<T> *root;
    BST<T>()
    {
        root = NULL;
    }
    void Insert(int key)
    {
        Node<T> *t = root;
        Node<T> *r = NULL, *p;

        if (root == NULL)
        {
            p = new Node<T>;
            p->data = key;
            p->lchild = p->rchild = NULL;
            root = p;
            return;
        }
        while (t != NULL)
        {
            r = t;
            if (key < t->data)
                t = t->lchild;
            else if (key > t->data)
                t = t->rchild;
            else
                return;
        }
        p = new Node<T>;
        p->data = key;
        p->lchild = p->rchild = NULL;

        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
    void Inorder(Node<T> *p)
    {
        if (p)
        {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }
    Node<T> *Search(int key)
    {
        Node<T> *t = root;

        while (t != NULL)
        {
            if (key == t->data)
                return t;
            else if (key < t->data)
                t = t->lchild;
            else
                t = t->rchild;
        }
        return NULL;
    }
    Node<T> *RInsert(Node<T> *p, int key)
    {
        Node<T> *t = NULL;

        if (p == NULL)
        {
            t = new Node<T>;
            t->data = key;
            t->lchild = t->rchild = NULL;
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);

        return p;
    }
    int Height(Node<T> *p)
    {
        int x, y;
        if (p == NULL)
            return 0;
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }
    Node<T> *InPre(Node<T> *p)
    {
        while (p && p->rchild != NULL)
            p = p->rchild;

        return p;
    }
    Node<T> *InSucc(Node<T> *p)
    {
        while (p && p->lchild != NULL)
            p = p->lchild;

        return p;
    }
    Node<T> *Delete(Node<T> *p, int key)
    {
        Node<T> *q;

        if (p == NULL)
            return NULL;
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            free(p);
            return NULL;
        }

        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);
        else
        {
            if (Height(p->lchild) > Height(p->rchild))
            {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
    }
    int getMaxWidth()
    {
        int maxWidth = 0;
        int width;
        int h = Height(root);
        int i;

       
        for (i = 1; i <= h; i++)
        {
            width = getWidth(root, i);
            if (width > maxWidth)
                maxWidth = width;
        }

        return maxWidth;
    }

    int getWidth(Node<T> *child, int level)
    {

        if (root == NULL)
            return 0;

        if (level == 1)
            return 1;

        else if (level > 1)
            return getWidth(root->lchild, level - 1) + getWidth(root->rchild, level - 1);
    }
};
int main()
{
    BST<int> Tree;

    cout << "Options\n\n1. Insert in Binary Search Tree\n\n2.Depth Of Tree\n\n3. Search Node\n\n4. Breath Of The Tree\n\n5. Delete Node";
    int opt = 1;
    do
    {
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            cout << "Enter The Leaf Element";
            int n;
            cin >> n;
            Tree.RInsert(Tree.root, n);
            break;
        }
        case 2:
        {
            cout << Tree.Height(Tree.root);
            break;
        }
        case 3:
        {
            cout << "Enter Element you Have To Search ";
            int n;
            cin >> n;
            Tree.Search(n);
        }
        case 4:
            cout << Tree.getMaxWidth();
            break;
        case 5:
            cout << "Enter Element Ment To Be Deleted ";
            int n;
            cin >> n;
            Tree.Delete(Tree.root, n);
        default:
            cout << "Wrong Option ";
            break;
        }
        cout << "Wanna Start Again(press 1) ";
        cin >> opt;
    } while (opt == 1);
    return 0;
}