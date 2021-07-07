#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return BinarySearch(arr, (mid + 1), high, x, n);
        else
            return BinarySearch(arr, low, (mid - 1), x, n);
    }
    return -1;
}
int main()
{
    int arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }
    int count = BinarySearch(arr, 0, arr_size - 1, 1, arr_size);
    cout << count - 1;
    return 0;
}
