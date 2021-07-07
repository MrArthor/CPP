#include <bits/stdc++.h>
 
using namespace std;
 
int arr[5][4] = {
       {16, 21, 32, 47},
       {26, 33, 37, 41},
       {5, 9, 15, 17},
       {11, 16, 22, 28},
       {37, 45, 48, 51},
    };
 
bool compare(pair<int, int> a, pair<int, int> b)
{
  return arr[a.first][a.second] > arr[b.first][b.second];
};
 
int kthSmallest(int arr[5][4], int m, int n, int k)
{
 
    queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < m; i++)
    {
     for (int j = 0; j < n; j++)
     {
       pq.push({i, j});
     }
    }
 
    for (int i = 1; i < k; i++)
    {
     auto p = pq.top();
     pq.pop();
 
     if (p.second + 1 < n)
       pq.push({p.first, p.second + 1});
    }
    return arr[pq.top().first][pq.top().second];
}
 
int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << k << "th smallest element is " << kthSmallest(arr, 5, 4, k);
    return 0;
}
