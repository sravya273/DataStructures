#include <bits/stdc++.h>
using namespace std;

void printPatterns(string s, int i)
{
    if(i==s.length())
    {
        cout<<s<<endl;
        return;
    }
    if(s[i]=='?')
    {
            s[i]='0';
            printPatterns(s,i+1);
            s[i]='1';
            printPatterns(s,i+1);
            // s[i]='?';
             return;
    }
    printPatterns(s,i+1);
}

int main()
{
   string s;
   cin>>s;
   printPatterns(s,0);
}
