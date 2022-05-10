#include <bits/stdc++.h>
 
using namespace std;
unordered_multiset<long long> us;
 
 
int main() 
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
 
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int long long i=1;i<=n;i++)
		{
			int long long x;
            cin>>x;
			us.insert(x);
		}
		for(int long long i=1;i<=m;i++)
		{
			int long long p;
			cin>>p;
			auto it=us.find(p);
			if(it!=us.end())
			{
				cout<<"YES\n";
			}
			else 
			{
				cout<<"NO\n";
				us.insert(p);
 
			}
		}
		us.clear();
 
	}
	return 0;
}