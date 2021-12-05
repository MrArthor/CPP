#include <iostream>
#include  <stdio.h>
#include  <sys/types.h>

using namespace std;

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int main()
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();

    return 0;
}

void  ChildProcess()
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          cout<<"\nThis line is from child, value =\n"<< i;
     cout<<"*** Child process is done ***\n";
}

void  ParentProcess()
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          cout<<"This line is from parent, value =\n"<< i;
     cout<<"*** Parent is done ***\n";
}