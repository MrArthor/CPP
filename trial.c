#include <stdio.h>
int main()
{
	char r[20];

	printf("enter a string:");
	scanf("%s", r);
	int len = sizeof(r) / sizeof(r[0]);
	for (int i = 0; i < len; i++)
	{
		printf("%c", r[i]);
	}
	return 0;
}