#include <iostream>
#include <queue>

using std::cout;
using std::pair;
using std::priority_queue;
using std::vector;

int kthSmallest(int mat[4][4], int n, int k)
{
    auto cmp = [=](std::pair<int, int> a, std::pair<int, int> b)
    {
        return mat[a.first][a.second] > mat[b.first][b.second];
    };

    std::priority_queue<std::pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++)
    {
        pq.push({i, 0});
    }

    for (int i = 1; i < k; i++)
    {
        auto p = pq.top();
        pq.pop();

        if (p.second + 1 < n)
            pq.push({p.first, p.second + 1});
    }
    return mat[pq.top().first][pq.top().second];
}

int main()
{
    int mat[5][4] = {
        {12, 21, 32, 43},
        {16, 24, 36, 45},
        {25, 30, 37, 49},
        {32, 34, 39, 52},
        {35, 36, 42, 55},
    };

    int k;
    cout << "Enter the value of k: ";
    std::cin >> k;
    cout << k << "th smallest element is " << kthSmallest(mat, 4, k);
    return 0;
}