
#include <bits/stdc++.h>
using namespace std;
 
int fun1() { return 10; }
char fun2() { return 'g'; }
 
int main()
{
    
    decltype(fun1()) x;
    decltype(fun2()) y;
 
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
 
    return 0;
}