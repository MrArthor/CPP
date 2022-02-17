#include <stdio.h>
#include <stdlib.h>
void BigEl(double* arr, double arrSize);

void BigEl(double* arr, double arrSize)
{
    int i;
    double  maximum, *x;
    maximum = arr[0];
    for (i = 1; i < arrSize; i++)
    {
        if (arr[i]>maximum)
        {
            maximum = arr[i];
        }
    }
    *x = maximum;
}
int main()
{
    double myarr[10];
    int i;
    printf("Please insert 10 numbers to the array\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &myarr[i]);
    }
    BigEl(myarr, 10);


}