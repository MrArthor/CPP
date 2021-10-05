#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{
	pid_t pid[5], p[5];
	for (int i = 0; i < 5; i++)
	{
		p = fork();
		pid = getpid();
		if (p < 0)
		{
			cout << stderr << "Fork Failed" << endl;
		}
		cout << "thread " << i << "executing”. \n"
			 << p << endl;
		cout << "Process id is: \n"
			 << pid << endl;
	}
	return 0;
}