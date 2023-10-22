#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int N)
{
	int max_len = 0; 

	for (int i = 0; i < N; i++) {

	
		int curr_sum = 0;

		for (int j = i; j < N; j++) {
			curr_sum += arr[j];

			
			if (curr_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

int main()
{
	int N;
    cin>>N;
	int arr[N] ;
for(int i=0;i<N;i++)
cin>>arr[i];

	cout<< maxLen(arr, N);
	return 0;
}
