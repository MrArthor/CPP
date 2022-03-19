// C++ code to print all possible
// subsequences for given array using
// recursion
#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all
// possible subsequences for given array
int ktastic(int n, int k, vector<int> arr)
{
int count = 0;
    auto printSubsequences = [&](vector<int> arr, int index,
                                 vector<int> subarr, int n)
    {
        // Print the subsequence when reach
        // the leaf of recursion tree
        bool truth = true;
        if (index == n)
        {
            for (auto it : subarr)
            {
                if (it == k && truth)
                {
                    count++;
                    truth == false;
                }
            }
            if (subarr.size() == 0)

                cout << endl;
            return;
        }
        else
        {
            // pick the current index into the subsequence.
            subarr.push_back(arr[index]);

            printSubsequences(arr, index + 1, subarr, n);

            subarr.pop_back();

            // not picking the element into the subsequence.
            printSubsequences(arr, index + 1, subarr, n);
        }
    };
    while (n--)
    {
        count = 0;
        vector<int> vec;
        printSubsequences(arr, 0, vec, n);

        return count;
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    return 0;
}
