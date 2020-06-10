#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
    int l=0;
    int m=0;
    stack<string> words;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ' || i==s.length()-1)
        {
            words.push(s.substr(l,m-l+1));
            l=i+1;
            m=i+1;
        }
        else
        m=i;
    }
    while(!words.empty())
    {
        cout<<words.top()<<" ";
        words.pop();
        
    }
}
