#include <stdio.h>

int main()
{
    char B[30];
    scanf("%s", B);
    int count = 0;
    for (int i = 0; B[i] != '\0'; i++)
    {
        if (B[i] == ' ')
        {
            count++;
        }
    }
    printf("%d", count + 1);
    return 0;
}