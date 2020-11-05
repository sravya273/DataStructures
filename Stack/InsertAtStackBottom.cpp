/*
Implement a method to insert an element at its bottom without using any other data structure.
*/
#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack <int> &stk, int newnum)
{
    if(stk.empty())
    stk.push(newnum);
    
    else
    {
        int a= stk.top();
        stk.pop();
        insert_at_bottom(stk,newnum);
        stk.push(a);
    }
}
int main()
{
    stack <int> stk;
    int n,input,newnum;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        stk.push(input);
    }
    cin>>newnum;
    insert_at_bottom(stk,newnum);
    cout<<"Printing stack contents"<<endl;
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
