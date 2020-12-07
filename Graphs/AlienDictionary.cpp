#include <bits/stdc++.h>
using namespace std;

void findAlphaOrder(vector <vector<int>> &g,vector <bool> &done,stack <int> &s,int src)
{
    
    done[src]=true;
    for(int i=0;i<g[src].size();i++)
    {
        if(!done[g[src][i]])
        {
            findAlphaOrder(g,done,s,g[src][i]);
        }
    }
    s.push(src);
}
int min(int x, int y) 
{ 
    return (x < y)? x : y; 
} 
int main() 
{
    int n;
    cin>>n;
	vector <string> words(n);
	for(int i=0;i<n;i++)
	{
	    cin>>words[i];
	}
	vector <vector<int>>g(26);
	
	//graph formation
	for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<min(words[i].length(),words[i+1].length());j++)
	    {
	        if(words[i][j]!=words[i+1][j])
	        {
	            g[words[i][j]-'a'].push_back(words[i+1][j]-'a');
	            cout<<"Created an edge between "<<words[i][j]<<"and "<<words[i+1][j]<<endl;
	            break;
	        }
	    }
	}
	stack <int> s;
	vector <bool>done(26,false);
	for(int i=0;i<26;i++)
	{
	    if(!done[i])
	    {
	        	findAlphaOrder(g,done,s,i);
	    }
	}
	cout<<"The order of characters in Alien dictionary is:";
	while(!s.empty())
	{
	    cout<<char(s.top()+'a')<<" ";
	    s.pop();
	}
	return 0;
}
