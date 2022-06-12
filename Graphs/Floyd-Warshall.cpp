/**
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
Floyd warshall algorithm implementation
*/

#include <bits/stdc++.h>
using namespace std;

void printFloyd(vector<vector<int>> &ans, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floyd(vector<vector<pair<int,int>>> &g, int n,vector<vector<int>> &ans)
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<g[i].size();j++)
       {
           ans[i][g[i][j].first] = g[i][j].second;  
       }
   }
   
   for(int k=0;k<n;k++)
   {
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(ans[i][k]!=INT_MAX && ans[k][j]!=INT_MAX && ans[i][j]>ans[i][k]+ans[k][j])
               {
                   ans[i][j]=ans[i][k]+ans[k][j];
               }
           }
       }
   }
}

int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	
	vector<vector<pair<int,int>>> g(n);
	
	int u,v,weight;
	
	while(m--)
	{
	    cin>>u;
	    cin>>v;
	    cin>>weight;
	    g[u].push_back(make_pair(v,weight));
	}
	
	vector<vector<int>> ans(n, vector<int>(n,INT_MAX));
	for(int i=0;i<n;i++)
	{
	    ans[i][i]=0;
	}
	floyd(g,n,ans);
	printFloyd(ans,n);
	return 0;
}


/**

Input:

4
4
0 1 5
0 3 10
2 3 1
1 2 3

Output:
0 5 8 9 
2147483647 0 3 4 
2147483647 2147483647 0 1 
2147483647 2147483647 2147483647 0 
