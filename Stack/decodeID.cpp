#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<int> decode;
    for(int i=0;i<=s.length();i++)
    {
        decode.push(i+1);
        if(s[i]=='I' || i==s.length())
        {
            while(!decode.empty())
            {
                cout<<decode.top();
                decode.pop();
            }
        }
    }
}
