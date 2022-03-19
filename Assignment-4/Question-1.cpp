#include <bits/stdc++.h>
#include <iterator>
#include <set>
using namespace std;
int SET()
{
    // empty set container
    set<int, greater<int>> s1;

    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // only one 50 will be added to the set
    s1.insert(50);
    s1.insert(10);

    // printing set s1
    set<int, greater<int>>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}

int VECTOR()
{
    vector<int> v{2, 3, 4, 1, 9, 6, 7, 6, 8};
    cout<<"\nThe vector v is : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;
    sort(v.begin(), v.end(), greater<int>());

    // for(auto x : v)
    cout<<"\nThe vector v after sorting is : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    sort(v.begin(), v.end());

    // for(auto x : v)
    cout << endl;
    cout<<"\nThe vector v after sorting is : \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

int main()
{

    SET();
    VECTOR();
    return 0;
}