#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "enter size of array ";
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        Arr[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] % 2 == 0)
        {
            j++;
            swap(Arr[i], Arr[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}