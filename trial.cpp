#include <bits/stdc++.h>
using namespace std;

void helper(vector <int> &ans, int i, vector <vector<int>> &cells ,int n, int r, int b, vector<int>&dp){
    if(i == n){
        int c = min(r,b);
        ans.push_back(c);
        return;
    }
    if(dp[i+1]!=1){
        dp[i]=min(r,b)+dp[i+1];
        return;
    }
    helper(ans,i+1,cells,n,r+cells[i][0],b,dp);
    helper(ans,i+1,cells,n,r,b+cells[i][1],dp);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>dp(n,-1);
        vector <vector<int>> cells;
        for(int i=0; i<n; i++){
            int r; cin>>r;
            cells.push_back({r,0});
        }
        for(int i=0; i<n; i++){
            int r; cin>>r;
            cells[i][1] = r;
        }
        vector <int> ans;
        helper(ans,0,cells,n,0,0,dp);
        sort(ans.begin(),ans.end());
        cout<<ans[(int)ans.size()-1]<<endl;
    }
}