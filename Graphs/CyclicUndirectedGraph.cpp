//Detect cycle in a undirected graph
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector <vector<int>> &g, vector <bool> &done,int src, int parent)
{
    done[src] = true;
    for(int i=0;i<g[src].size();i++)
    {
        if(!done[g[src][i]] && isCyclic(g, done,g[src][i],src))
        return true;
        else if(done[g[src][i]] && parent!=g[src][i])
        return true;
    }
    return false;
}
int main()
{
    int m,n;
    cin>>n>>m;
    vector <vector<int>> g(n);
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <bool> done(n,false);
    bool cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!done[i] && isCyclic(g,done,i,-1))
        {
          cycle = true;
          break;
        }
    }
    if(cycle)
    cout<<"Cycle detected in the given undirected graph"<< endl;
    else
    cout<<"No cycle"<<endl;
}
/*
Input:
4
3
1 2
1 3
2 3
3 4
Output:
Cycle detected in the given undirected graph
*/
