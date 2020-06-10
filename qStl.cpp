#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> numqueue;
    for(int i=0;i<10;i++)
    numqueue.push(i);
    
    while(!numqueue.empty())
    {
        cout<<numqueue.front()<<" ";
        numqueue.pop();
    }
    cout<<endl;
}
