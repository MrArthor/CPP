#include <bits/stdc++.h>

using namespace std;

int main()
{
    int count[6] = {0, 0, 0, 0, 0, 0};
    cout << "Enter The Number Of Voters";
    int voters;
    cin >> voters;
    int *vote=new int[voters];
    for(int i=0;i<voters;i++)
    {
        cout << "Enter The Vote Of Voter " << i+1 << ": ";
        cin >> vote[i];
        
    }

    return 0;
}