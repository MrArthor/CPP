#include<iostream>
#include<conio.h>
using namespace std;

template<class swap>

void swapp(swap &i, swap &j)
{
    swap t;
    t=i;
    i=j;
    j=t;
}
 
int main() {
    int e,f;
    char g,r;
    float x,y;

    cout<<"\n Please insert 2 Integer Values:"; cin>>e>>f;
    swapp(e,f);
    cout<<"\nInteger values after Swapping:";
    cout<<e<<"\t"<<f<<"\n\n";
    
    cout<<"\n Please insert 2 Character Values:"; cin>>g>>r;
    swapp(g,r);
    cout<<"\n Character Values after Swapping:";
    
    cout<<g<<"\t"<<r<<"\n\n";
    cout<<"\n please insert 2 Float Values:"; cin>>x>>y;
    swapp(x,y);
    cout<<"\n The resultatnt float values after swapping:";
    cout<<x<<"\t"<<y<<"\n\n";
}