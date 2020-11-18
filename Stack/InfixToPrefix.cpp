#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) 
{ 
    return (!isalpha(c) && !isdigit(c)); 
}

int getPriority(char ch) 
{ 
    if (ch == '-' || ch == '+') 
        return 1; 
    else if (ch == '*' || ch == '/') 
        return 2; 
    else if (ch == '^') 
        return 3; 
    return 0; 
} 

string infixToPrefix(string s)
{
    stack <char> operators;
    stack <string> operands;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        operators.push(s[i]);
        
        else if(s[i]==')')
        {
            while(!operators.empty() && operators.top()!='(')
            {
                string op1 = operands.top(); 
                operands.pop(); 
  
                string op2 = operands.top(); 
                operands.pop(); 
  
                char op = operators.top(); 
                operators.pop(); 
  
                string temp = op + op2 + op1; 
                operands.push(temp); 
            }
            
            operators.pop(); 
        }
        else if (!isOperator(s[i])) { 
            operands.push(string(1, s[i])); 
        } 
        else { 
            while (!operators.empty() &&  
                   getPriority(s[i]) <=  
                     getPriority(operators.top())) { 
  
                string op1 = operands.top(); 
                operands.pop(); 
  
                string op2 = operands.top(); 
                operands.pop(); 
  
                char op = operators.top(); 
                operators.pop(); 
  
                string tmp = op + op2 + op1; 
                operands.push(tmp); 
            } 
  
            operators.push(s[i]); 
        } 
        
    }
    while (!operators.empty()) { 
        string op1 = operands.top(); 
        operands.pop(); 
  
        string op2 = operands.top(); 
        operands.pop(); 
  
        char op = operators.top(); 
        operators.pop(); 
  
        string tmp = op + op2 + op1; 
        operands.push(tmp); 
    } 
    
    return operands.top(); 
}


int main() {
    string s;
    cin>>s;
    cout<<infixToPrefix(s);
	return 0;
}
