/*
An string of words is given, the task is to reverse the string using stack.

Input Format:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string s of words without spaces.

Output Format:
For each test case ,print the reverse of the string in new line. 

Constraints:
1 <= T <= 100
1 <= length of the string <= 100

Example:
Input:
2
GeeksQuiz
GeeksforGeeks
Output:
ziuQskeeG
skeeGrofskeeG
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {   
        string str;
        cin>>str;
        stack <char> s;
        int length = str.length();
    
        for(int i=0;i<length;i++)
        s.push(str[i]);
    
        for(int i=0;i<length;i++)
        {
        cout<<s.top();
        s.pop();
        }
        cout<<endl;
    }
	return 0;
}
