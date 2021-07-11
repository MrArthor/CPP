#include <bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int age;
    node *next_alpha, *next_age;
};
node *newnode(string s, int n)
{
    node *temp = new node();
    temp->name = s;
    temp->age = n;
    temp->next_alpha = NULL;
    temp->next_age = NULL;
    return temp;
}
class multi_list
{
    node *by_name, *by_age;

public:
    multi_list()
    {
        by_name = NULL;
        by_age = NULL;
    }
    void insert_name(node *t)
    {
        if (!by_name)
        {
            by_name = t;
            return;
        }
        node *p = by_name, *q;
        q = p;
        while (p && p->name.compare(t->name) < 0)
        {
            q = p;
            p = p->next_alpha;
        }
        if (!p)
        {
            q->next_alpha = t;
        }
        else if (p == by_name)
        {
            t->next_alpha = p;
            by_name = t;
        }
        else
        {
            t->next_alpha = q->next_alpha;
            q->next_alpha = t;
        }
        return;
    }
    void insert_age(node *t)
    {
        if (!by_age)
        {
            by_age = t;
            return;
        }
        node *p = by_age, *q;
        q = p;
        while (p && p->age < t->age)
        {
            q = p;
            p = p->next_age;
        }
        if (!p)
        {
            q->next_age = t;
        }
        else if (p == by_age)
        {
            t->next_age = p;
            by_age = t;
        }
        else
        {
            t->next_age = q->next_age;
            q->next_age = t;
        }
        return;
    }
    void insert(node *t)
    {
        insert_name(t);
        insert_age(t);
    }
    void del_byname(string n)
    {
        node *p = by_name;
        node *q = p;
        while (p && p->name != n)
        {
            q = p;
            p = p->next_alpha;
        }
        node *x, *y;
        x = y = by_age;
        while (x != p)
        {
            y = x;
            x = x->next_age;
        }
        y->next_age = x->next_age;
        x->next_age = NULL;
        if (p == by_name)
        {
            by_name = p->next_alpha;
            p->next_alpha = NULL;
        }
        else if (!p->next_alpha)
        {
            q->next_alpha = NULL;
        }
        else
        {
            q->next_alpha = p->next_alpha;
            p->next_alpha = NULL;
        }
        delete (p);
    }
    void del_byage(int n)
    {
        node *p = by_age;
        node *q = p;
        while (p && p->age != n)
        {
            q = p;
            p = p->next_age;
        }
        node *x, *y;
        x = y = by_name;
        while (x != p)
        {
            y = x;
            x = x->next_alpha;
        }
        y->next_alpha = x->next_alpha;
        x->next_alpha = NULL;
        if (p == by_age)
        {
            by_age = p->next_age;
            p->next_age = NULL;
        }
        else if (!p->next_age)
        {
            q->next_age = NULL;
        }
        else
        {
            q->next_age = p->next_age;
            p->next_age = NULL;
        }
        delete (p);
    }
    void display_byname()
    {
        node *p = by_name;
        while (p)
        {
            cout << p->name << " " << p->age << endl;
            p = p->next_alpha;
        }
    }
    void display_byage()
    {
        node *p = by_age;
        while (p)
        {
            cout << p->name << " " << p->age << endl;
            p = p->next_age;
        }
    }
};
int main()
{
    multi_list M;
    node *n[4];
    n[0] = newnode("abhi", 18);
    n[1] = newnode("ravi", 22);
    n[2] = newnode("gill", 19);
    n[3] = newnode("suppy", 15);
    for (int i = 0; i < 4; i++)
    {
        M.insert(n[i]);
    }
    cout << "display alphabetically" << endl;
    M.display_byage();
    cout << endl;
    cout << "displaybyage" << endl;
    M.display_byage();
    cout << endl;
    M.del_byage(22);
    cout << "after deleting age 22" << endl;
    M.display_byage();
    cout << endl;
    cout << "after deleting abhi" << endl;
    M.del_byname("abhi");
    M.display_byname();
}