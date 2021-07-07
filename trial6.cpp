#include <bits/stdc++.h>
using namespace std;

struct HeapNode
{
    int val;
    int r;
    int c;
};

void swap(HeapNode *x, HeapNode *y)
{
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

void MinHeapify(HeapNode HeapArr[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int smallest = i;
    if (l < heap_size && HeapArr[l].val < HeapArr[i].val)
        smallest = l;
    if (r < heap_size && HeapArr[r].val == 0)
    {
        MinHeapify(HeapArr, i, heap_size);
        i--;
    }
}

int KThSmallest(int mat[][4], int n, int k)
{
    if (k < 0 && k >= n * n)
        return INT_MAX;

    HeapNode HeapArr[n];
    for (int i = 0; i < n; i++)
        HeapArr[i] = {mat[0][i], 0, i};

    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
        hr = HeapArr[0];

        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]   : INT_MAX;

        HeapArr[0] = {nextval, (hr.r) + 1, hr.c};

        MinHeapify(HeapArr, 0, n);
    }

    return hr.val;
}

int main()
{
    // int row, col, k;
    // cout << "Enter Number Of Columns ";
    // cin >> col;
    // cout << "Enter Number Of Rows ";
    // cin >> row;
    // int mat[row][4];
    // cout << "Enter Value Of K ";
    // cin >> k;
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cin >> mat[i][j];
    //     }
    // }
      int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
         << KThSmallest(mat, 4, 7);
    return 0;
}