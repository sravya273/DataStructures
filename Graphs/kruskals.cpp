/**
Minimum spanning tree weight using kruskals algorithm
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {

    vector<int> p; //parent
    vector<int> r; //rank means max height in the tree

public:
    UnionFind(int size) {
        
        for(int i=0;i<size;i++) {
            p.push_back(i);
            r.push_back(0);
        }
    }
    
    int find(int x) {
        
        if(p[x] == x) {
            return x;
        }
        
        p[x] = find(p[x]); // compression
        return p[x];
    }
    
    void uni(int x, int y) {
        
        int px = find(x);
        int py = find(y);
        
        if(r[px] < r[py]) {
            p[px] = py;
        } else if(r[py] < r[px]) {
            p[py] = px;
        } else {
            p[py] = px;
            r[px]++;
        }
    }
    
    bool isGroupHead(int x) {
        return p[x]==x;
    }
};

int kruskals(vector<vector<int>> &edgeList, UnionFind &uf, int n)
{
    sort(edgeList.begin(), edgeList.end());
    
    int minWeight = 0;
    
    for(auto edge : edgeList)
    {
        int weight = edge[0];
        int x = edge[1];
        int y = edge[2];
        
        if(uf.find(x)!=uf.find(y))
        {
            uf.uni(x,y);
            minWeight += weight;
            cout<<"x:"<<x<<", y:"<<y<<", weight: "<<weight<<endl;
        }
    }
    return minWeight;
}

int main() 
{
	int n;
	cin>> n;
	
	vector<vector<int>> edgeList;
	
	int m;
	cin>>m;
	
	int u,v,weight;
	
	while(m--)
	{
	    cin>>u>>v>>weight;
	    edgeList.push_back({weight,u,v});
	}
	
	UnionFind uf(n);
	int minWeight = kruskals(edgeList,uf,n);
	
	cout<<"Minimum weight of spanning tree is "<<minWeight<<endl;
	return 0;
}


/**
Input:
4
5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5

Output:
x:2, y:3, weight: 4
x:0, y:3, weight: 5
x:0, y:1, weight: 10
Minimum weight of spanning tree is 19
*/
