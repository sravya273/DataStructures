#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char> balance;
    int i=0;
    while(s[i]!='\0')
    {
       if(s[i]=='{' || s[i]=='(' || s[i]=='[')
         balance.push(s[i]);
         
        else
        {
            
            if(!balance.empty() && (((s[i]=='}' && balance.top()=='{') || 
            (s[i]==']' && balance.top()=='[') || (s[i]==')' && balance.top()=='('))))
            {
                balance.pop();
            }
            else 
            {
                cout<<"not balanced" <<endl;
                return 1;
            }
        }
      i++; 
      
    }
    if(balance.empty()) cout<<"balanced"<<endl;
    else cout<<"not balanced"<<endl;
    return 0;
}
