#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack, int num) {

    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int ans = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, ans);

}