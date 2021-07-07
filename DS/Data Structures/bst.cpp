#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Queue>
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
struct Stack
{
    int size;
    int top;
    Node<T> *S;
};
template <class T>

void Stackcreate(Stack<T> *st, int size)
{
    printf("Enter Size");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (Node<T> *)malloc(size * sizeof(int));
}
template <class T>

void Display(Stack<T> st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
template <class T>

void push(Stack<T> *st, Node<T> *x)
{
    if (st->top == st->size - 1)
        printf("Stack<T>overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = *x;
    }
}
template <class T>

Node<T> *pop(Stack<T> *st)
{
    Node<T> *x;
    if (st->top == -1)
        printf("Stack<T>Underflow\n");
    else
    {
        x = &st->S[st->top--];
    }
    return x;
}
template <class T>
int peek(Stack<T> st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.S[st.top - index + 1];

    return x;
}
template <class T>
int isEmptyStack(Stack<T> st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
template <class T>
int isFull(Stack<T> st)
{
    return st.top == st.size - 1;
}
template <class T>
int stackTop(Stack<T> st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();
    bool isEmpty()
    {
        if (rear == size - 1)
            return true;
        else
        {
            return false;
        }
    }
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

template <class T>
class BST
{
private:
    int leaf, NonLeaf;

public:
    Node<T> *root;
    BST()
    {
        leaf = NonLeaf = 0;
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

    void Preorder(Node<T> *p)
    {
        if (p)
        {
            printf("%d ", p->data);
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Leaf(Node<T> *p)
    {
        if (p)
        {
            if (!p->lchild && !p->rchild)
            {
                leaf++;
            }
            else if (p->lchild)
                Leaf(p->lchild);
            else if (p->rchild)
                Leaf(p->rchild);
        }
    }
    void mirror(Node<T> *node)
    {
        if (node == NULL)
            return;
        else
        {
            Node<T> *temp;

            /* do the subtrees */
            mirror(node->lchild);
            mirror(node->rchild);

            /* swap the pointers in this node */
            temp = node->lchild;
            node->lchild = node->rchild;
            node->rchild = temp;
        }
    }
    void Non(Node<T> *p)
    {
        if (p)
        {
            if (!p->lchild && !p->rchild)
            {
            }
            else if (p->lchild)
            {

                NonLeaf++;
                Non(p->lchild);
            }
            else if (p->rchild)
            {
                NonLeaf++;
                Non(p->rchild);
            }
        }
    }

    void Inorder(Node<T> *p)
    {
        if (p)
        {
            Inorder(p->lchild);
            printf("%d ", p->data);
            Inorder(p->rchild);
        }
    }
    void Postorder(Node<T> *p)
    {
        if (p)
        {
            Postorder(p->lchild);
            Postorder(p->rchild);
            printf("%d ", p->data);
        }
    }
    void Levelorder(Node<T> *root)
    {
        Queue q(100);

        printf("%d ", root->data);
        q.enqueue(root);

        while (!q.isEmpty())
        {
            root = q.dequeue();
            if (root->lchild)
            {
                printf("%d ", root->lchild->data);
                q.enqueue(root->lchild);
            }
            if (root->rchild)
            {
                printf("%d ", root->rchild->data);
                q.enqueue(root->rchild);
            }
        }
    }
    void IPreorder(Node<T> *p)
    {
        Stack<T> stk;
        Stackcreate(&stk, 100);

        while (p || !isEmptyStack(stk))
        {
            if (p)
            {
                printf("%d ", p->data);

                push(&stk, p);
                p = p->lchild;
            }
            else
            {
                p = pop(&stk);
                p = p->rchild;
            }
        }
    }
    void IInorder(Node<T> *p)
    {
        Stack<T> stk;
        Stackcreate(&stk, 100);

        while (p || !isEmptyStack(stk))
        {
            if (p)
            {
                push(&stk, p);
                p = p->lchild;
            }
            else
            {
                p = pop(&stk);
                printf("%d ", p->data);
                p = p->rchild;
            }
        }
    }
    void postOrderIterative(Node<T> *root)
    {
        if (root == NULL)

            Stack<T> s1, s2;
        s1.push(root);
        Node<T> *node;

        while (!s1.empty())
        {
            node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->lchild)
                s1.push(node->lchild);
            if (node->rchild)
                s1.push(node->rchild);
        }

        while (!s2.empty())
        {
            node = s2.top();
            s2.pop();
            cout << node->data << " ";
        }
    }
};
int main()
{
    BST<int> Tree;
    int choice;

    while (1)
    {
        cout << "\nOptions";
        cout << "\n\n1. Insert in Binary Search Tree";
        cout << "\n2. Depth Of Tree";
        cout << "\n3. Search Node";
        cout << "\n4. Breadth Of The Tree";
        cout << "\n5. RecurSive Postoder ";
        cout << "\n6. RecurSive Inorder ";
        cout << "\n7. RecurSive Preorder ";
        cout << "\n8. Iterative PostOrder ";
        cout << "\n9 Iterative Inorder ";
        cout << "\n10. Iterative Preorder ";
        cout << "\n11. Count Leave Nodes ";
        cout << "\n12. Count Non-Leave Nodes";
        cout << "\n13. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n1. Insertion through iteration.";
            cout << "\n2. Insertion through recursion";
            cout << "\nEnter your choice:";
            int opt;
            cin >> opt;
            if (opt == 1)
            {
                cout << "\nEnter The Leaf Element: ";
                int n;
                cin >> n;
                if (!Tree.root)
                {
                    Tree.root = Tree.RInsert(Tree.root, n);
                }
                else
                {
                    Tree.Insert(n);
                }
            }
            else if (opt == 2)
            {
                cout << "\nEnter The Leaf Element: ";
                int n;
                cin >> n;
                if (!Tree.root)
                {
                    Tree.root = Tree.RInsert(Tree.root, n);
                }
                else
                {
                    Tree.RInsert(Tree.root, n);
                }
            }
            else
            {
                cout << "\nWrong choice";
            }

            break;
        }
        case 2:
        {
            cout << "\nDepth of the tree: ";
            cout << Tree.Height(Tree.root) << " ";
            break;
        }
        case 3:
        {
            cout << "\nEnter The Element you Have To Search: ";
            int n;
            cin >> n;
            Node<int> *temp = Tree.Search(n);
            if (temp)
                cout << "\nElement Found ";
            else
            {
                cout << "\nElement Not Found ";
            }

            break;
        }
        case 4:
            cout << "\nBreadth of the tree: ";
            cout << Tree.getMaxWidth();
            break;

        case 5:
            Tree.Postorder(Tree.root);
            break;
        case 6:
            Tree.Inorder(Tree.root);
            break;
        case 7:
            Tree.Preorder(Tree.root);
            break;
        case 8:
            Tree.postOrderIterative(Tree.root);
            break;
        case 9:
            Tree.IInorder(Tree.root);
            break;

        case 10:
            Tree.IPreorder(Tree.root);
            break;
        case 11:
            Tree.Leaf(Tree.root);
            break;
        case 12:
            Tree.Non(Tree.root);
            break;
        case 13:
            exit(0);
            break;
        default:
            cout << "\nWrong Option ";
            break;
        }
    }
    return 0;
}