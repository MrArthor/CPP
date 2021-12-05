#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int main()
{
    pid_t pid,p;
    p=fork();
    pid= getpid();
    if(p<0)
    {
        cout<<stderr<<"Fork Failed"<<endl;
        return 1;
    }
    cout<<"Output of fork id: \n"<<p<<endl;
    cout<<"Process id is: \n"<<pid<<endl;
    return 0;
}

