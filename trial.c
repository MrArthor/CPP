#include <stdio.h>
#include <math.h>

int main()
{
    fflush(stdin);
    int number;
    scanf("%d", &number);
    if (number >= 0)
    {
        printf("\nPositive Numbre ");
    }
    else
    {
        printf("\nNegative Number");
    }
    return 0;
}