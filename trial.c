#include <stdio.h>
#include <math.h>
void foo();
int main()
{
    int a = 5;
    switch (a)
    {
    case 0:
        printf("0 ");
    case 3:
        printf("3 ");
    case 5:
        printf("5 ");
    default:
        printf("Rabbit ");
    }
    a = 10;
    switch (a)
    {
    case 0:
        printf("0 ");
    case 3:
        printf("3 ");
    case 5:
        printf("5 ");
    default:
        printf("Rabbit ");
    }
    return 0;
}
