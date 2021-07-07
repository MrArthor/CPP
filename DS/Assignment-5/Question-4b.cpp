#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + arr_size);
    int temp[arr_size];
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {

        temp[j] = arr[i];
        j += 2;
    }

    j = 1;
    for (int i = 0; i < arr_size; i++)
    {
        temp[j] = arr[arr_size - 1 - i];
        j += 2;
        if (j >= arr_size)
        {
            break;
        }
    }
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = temp[i];
    }
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
