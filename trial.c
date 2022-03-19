// C program of nested function
// with the help of gcc extension
#include <stdio.h>
#include <climits>
#include<math.h>
void function()
{
	int i, j, k;
	unsigned int u, v;
	i = INT_MAX; // 2147483647
	i++;
	printf("i = %d, ", i);
	j = INT_MIN; // -2147483648
	j--;
	printf("j = %d, ", j);
	k = INT_MIN; // -2147483648
	k = abs(k);
	printf("k = %d, ", k);

	u = UINT_MAX; // 4294967295
	u++;
	printf("u = %u, ", u);
	v = 0;
	v--;
	printf("v = %u", v);
}
int main(void)
{
	 function();
}
