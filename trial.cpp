#include <stdio.h>
struct student
{
    int roll_no;
    char name[50];
    int marks;
} s;
int main()
{
    int i;
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    for (i = 0; i < 5; i++)
    {
        printf("enter the details of student:");
        scanf("%d %s %d", &s.roll_no, &s.name, &s.marks);
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d %s %d", &s.roll_no, &s.name, &s.marks);
    }
    for (i = 0; i < 5; i++)
    {
        if (s.marks >= 60)
        {
            count_1++;
            printf("\nmarks above or equal to 60:%d", count_1);
        }
        else if (s.marks < 60 && s.marks >= 50)
        {
            count_2++;
            printf("\nmarks between 50 to 60:%d", count_2);
        }
        else if (s.marks < 50 && s.marks >= 40)
        {
            count_3++;
            printf("\nmarks between 40 to 50:%d", count_3);
        }
        else if (s.marks < 40)
        {
            count_4++;
            printf("\nmarks less than 40:%d", count_4);
        }
    }
    return 0;
}