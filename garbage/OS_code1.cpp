#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t process_id;
    pid_t p_process_id;

    process_id = getpid();
    p_process_id = getppid();

    cout << "\nThe process id:\n"
         << process_id;
    cout << "\nThe process id of parent function:\n"
         << p_process_id;

    return 0;
}