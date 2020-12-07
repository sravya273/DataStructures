//Detect cycle in a undirected graph
#include <bits/stdc++.h>
using namespace std;

bool topologicalSort(vector <vector<int>> &g, vector <bool> &done, stack <int> &s, int src)
{
    done[src] = true;
    for(int i=0;i<g[src].size();i++)
    {
        if(!done[g[src][i]])
        topologicalSort(g,done,s,g[src][i]);
    }
    s.push(src);
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
    stack <int> s;
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        topologicalSort(g,done,s,i);
    }
    cout<<"Topological sort is:";
    while(!s.empty())
    {
        cout<<s.top()+1<<" ";
        s.pop();
    }
}
/*
Input:
6
6
6 3
6 1
5 1
5 2
3 4
4 2
Output:
Topological sort is:5 4 2 3 1 0 
*/
