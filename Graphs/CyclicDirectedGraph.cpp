//Detect cycle in a directed graph
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(vector <vector<int>> &g, vector <bool> &done,vector <bool> &recStack, int src )
{
    done[src] = true;
    recStack[src] = true;
    for(int i=0;i<g[src].size();i++)
    {
        if(!done[g[src][i]] && !recStack[g[src][i]] && isCyclic(g,done,recStack, g[src][i]))
        {
            return true;
        }
        else if (recStack[g[src][i]])
        return true;
    }
    recStack[src] = false;
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
    }
    vector <bool> done(n,false);
    vector <bool> recStack(n,false);
    bool cycle = false;
    for(int i=0;i<n;i++)
    {
        if(!done[i] && isCyclic(g,done,recStack,i))
        {
          cycle = true;
          break;
        }
    }
    if(cycle)
    cout<<"Cycle detected in the given directed graph"<< endl;
    else
    cout<<"No cycle"<<endl;
}

/*
Input:
4
6
1 2
1 3
2 3
3 1
3 4
3 3
output:
Cycle detected in the given directed graph
*/
