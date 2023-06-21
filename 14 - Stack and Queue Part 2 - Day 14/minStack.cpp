#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int> st;
	int mn;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			while(!st.empty()) st.pop();
			mn = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				st.push(num);
				mn = num;
			}
			else if(num < mn){
				int val = 2*num-mn;
				mn = num;
				st.push(val);
			}
			else st.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty()) return -1;
			else{
				int val = st.top();
				st.pop();
				if(val < mn){
					int a = mn;
					mn = 2*mn - val;
					return a;
				} 
				return val;
			}			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty()) return -1;
			if(st.top() < mn) return mn;
			return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty()) return -1;
			return mn;
		}
};