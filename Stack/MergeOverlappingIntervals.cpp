/* Merge Overlapping Intervals

Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. 
Let the intervals be represented as pairs of integers for simplicity. 
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8}}. 
The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. 
Similarly, {5, 7} and {6, 8} should be merged and become {5, 8}
*/
#include <bits/stdc++.h>
using namespace std;

void mergeIntervals(vector <pair<int,int>> &intervals)
{
    int n= intervals.size();
    if(n<=0)
    return;
    
    //sort the elements of vector by ascending order of first elements
    
    stack <pair<int,int>>stk;
    stk.push(intervals[0]);
    pair <int,int> temp;
    for(int i=1;i<n;i++)
    {
        if(intervals[i].first)>stk.top().second)
        stk.push(intervals[i]);
        
        else if(stk.top().second<intervals[i].second)
        temp = make_pair(stk.top.first,in[].second);
        stk.pop();
        stk.push(temp);
    }
    
}
int main() {
	vector <pair<int,int>>intervals;
	int n;
	cin>>n;
	int a,b;
	while(n--)
	{
	    cin>>a>>b;
	    intervals.push_back(make_pair(a,b));
	}
	mergeIntervals(intervals);
	return 0;
}
