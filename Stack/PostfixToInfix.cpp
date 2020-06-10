#include <bits/stdc++.h>
using namespace std;

bool isOperand(char op)
{
    return (op>='a' && op<='z')|| (op>='A' && op<='Z');
}

int main()
{
    string expression;
    cin>> expression;
    stack<string> operands;
    string a,b;
    for(int i=0;i<expression.length();i++)
    {
        if(isOperand(expression[i]))
        {
            string op(1,expression[i]);
        operands.push(op);
        }
        
        else if(!operands.empty())
        {
            a=operands.top();
            operands.pop();
            if(!operands.empty())
            {
                b=operands.top();
                operands.pop();
                operands.push("(" + b + expression[i] + a +")");
            }
            else
            {
                cout<<"Invalid expression"<<endl;
                return 0;
            }
        }
    }
    
    if(operands.size()==1) cout<<operands.top();
    else cout<<"Invalid expression"<<endl;
    return 0;
}
