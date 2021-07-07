#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    int freq;
    node *l, *r;
    node()
    {
        l = r = NULL;
        val = freq = 0;
    }
    node(int x)
    {
        val = x;
        freq = 1;
        l = r = NULL;
    }
};
void in(node *r)
{
    if (r == NULL)
        return;

    in(r->l);
    cout << r->val << " ";
    in(r->r);
}
node *insert_val(int x, node *r)
{
    if (r == NULL)
    {
        node *new_n = new node(x);
        return new_n;
    }
    else if (r->val == x)
    {
        r->freq++;
        return r;
    }
    else if (r->val > x)
        r->l = insert_val(x, r->l);
    else
        r->r = insert_val(x, r->r);
}

node *successor(node *h)
{
    if (h->l == NULL)
        return h;
    else
        return successor(h->l);
}
node *remove(int x, node *r)
{
    if (r == NULL)
        return r;

    else if (r->val == x)
    {
        if (r->freq > 1)
        {
            r->freq--;
            return r;
        }

        if (r->l == NULL && r->r == NULL)
            return NULL;

        else if (r->r == NULL)
            r->l;

        else if (r->l == NULL)
            return r->r;

        else
        {
            node *suc = successor(r->r);
            r->val = suc->val;
            r->r = remove(suc->val, r->r);
            return r;
        }
    }
    else if (r->val > x)
        r->l = remove(x, r->l);

    else
        r->r = remove(x, r->r);
}

int main()
{
    int n, x;
    cin >> n;
    node *h;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        h = insert_val(x, h);
    }
}
