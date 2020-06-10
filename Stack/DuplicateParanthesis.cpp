#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char> sta;
    int i=0;
   for(int i=0; i<s.length();i++)
    {
        if(s[i]!=')')
         sta.push(s[i]);
         
        else
        {
           if(sta.top()=='(')
           {
           cout<<"duplicate paranthesis found1"<<endl;
           return 0;
           }
           else
           {
               while(sta.top()!='(')
               sta.pop();
               
               sta.pop();
           }
        }
    }
    cout<<"nothing found"<<endl;
}
