#include <bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int A[], int arr_size,
                           int sum)
{
    int l, r;

    sort(A, A + arr_size);

    l = 0;
    r = arr_size - 1;
    while (l < r)
    {
        if (A[l] + A[r] == sum)
        {
            cout << "First Element is " << A[l] << " Second Element Is " << A[r] << " So ";
            return 1;
        }
        else if (A[l] + A[r] < sum)
            l++;
        else
            r--;
    }
    return 0;
}

int main()
{
    int n = 16;
    int arr_size;
    cin >> arr_size;
    int A[arr_size];
    cin >> n;
    for (int i = 0; i < arr_size; i++)
    {
        cin >> A[i];
    }
    // Function calling
    if (hasArrayTwoCandidates(A, arr_size, n))
        cout << "Array has two elements"
                " with given sum";
    else
        cout << "Array doesn't have two"
                " elements with given sum";

    return 0;
}
