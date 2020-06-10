#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
ll n,m,u,v;
vll g[103];
bool done[103];
void dfs(int v)
{
	done[v]=true;
	cout<<v<<" ";
	vll:: iterator it;
	for(it=g[v].begin();it!=g[v].end();it++)
	{
		if(!done[*it])
		{
		dfs(*it);
		}
	}
}
void connectedComponents()
{
	memset(done,false, sizeof done);
	for(int i=0;i<n;i++)
	{
		if(done[i]==false)
		{
			dfs(i);
			cout<<endl;
		}
	}
}

int main()
{
	cin>>n;
	cin>>m;
	while(m--)
	{
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
	}
	connectedComponents();
}
