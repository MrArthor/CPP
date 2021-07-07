#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;

	sort(A, A + arr_size);

	
	for (int i = 0; i < arr_size - 2; i++) {

		
		l = i + 1; 

		r = arr_size - 1;
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				printf("Triplet is %d, %d, %d", A[i],
					A[l], A[r]);
				return true;
			}
			else if (A[i] + A[l] + A[r] < sum)
				l++;
			else 
				r--;
		}
	}

	return false;
}





int main()
{
    int sum = 16;
    int arr_size;
    cin >> arr_size;
    int A[arr_size];
    cin >> sum;
    for (int i = 0; i < arr_size; i++)
    {
        cin >> A[i];
    }
    // Function calling
   	find3Numbers(A, arr_size, sum);

    return 0;
}
