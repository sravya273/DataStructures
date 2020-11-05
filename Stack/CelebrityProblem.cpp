/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0.

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
*/
#include <bits/stdc++.h>
using namespace std;

void checkCelebrity(vector <vector <int>> &acquiantance, int n,int a)
{
    for(int i=0;i<n;i++)
    {
        if(i!=a && (acquiantance[a][i]==1 || !acquiantance[i][a]))
        {
            cout<<"No celebrity"<<endl;
            return;
        }
    }
    cout<<"celebrity is "<<a<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector <vector <int>> acquiantance(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>acquiantance[i][j];
        }
    }
    int a =0, b=n-1;
    while(a<b)
    {
        if(acquiantance[a][b]==1)
        a++;
        else
        b--;
    }
    
    checkCelebrity(acquiantance,n,a);
}
