/*
Implement Special Stack Data Structure that supports get minimum at O(1)
*/
#include <bits/stdc++.h>
using namespace std;

void push_operation(stack<int> &numbers, stack<int> &minstack, int x)
{
    numbers.push(x);
    if(minstack.empty() || minstack.top()>=x) minstack.push(x);
}

void pop_operation(stack<int> &numbers, stack<int> &minstack)
{
    cout<<"popping..!"<<endl;
    if(numbers.top()!=minstack.top() && !numbers.empty() && !minstack.empty() )
    {
        numbers.pop();
    }
    else
    {
        numbers.pop();
        minstack.pop();
    }
    cout<<"Current min element of stack is "<<minstack.top()<<endl;
}
int main() {
   
    //maintain 2 stacks;
    stack <int> numbers;
    stack <int> minstack;
    
    push_operation(numbers,minstack,18);
    push_operation(numbers,minstack,19);
    push_operation(numbers,minstack,29);
    push_operation(numbers,minstack,15);
    push_operation(numbers,minstack,16);
    
    pop_operation(numbers,minstack);
    pop_operation(numbers,minstack);
    
	return 0;
}
