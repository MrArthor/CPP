#include <bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int size)
{
    int *count = new int[sizeof(int) * (size - 2)];
    int i;

    cout << " Repeating elements are ";
    for (i = 0; i < size; i++)
    {
        if (count[arr[i]] == 1)
            cout << arr[i] << " ";
        else
            count[arr[i]]++;
    }
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
    printRepeating(arr, arr_size);
    return 0;
}
