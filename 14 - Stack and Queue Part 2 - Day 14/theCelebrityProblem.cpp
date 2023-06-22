#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int>st;
	 for(int i=0; i<n; i++) st.push(i);
	 while(!st.empty() && st.size() != 1){
		 int a = st.top();
		 st.pop();
		 int b = st.top();
		 st.pop();
		 if(knows(a,b) && knows(b,a)) continue;
		 else if(knows(a,b)) st.push(b);
		 else if(knows(b,a)) st.push(a);
	 }
	 if(st.empty()) return -1;
	 int probableAns = st.top();

	 for(int i=0; i<n; i++) {
		 if(i == probableAns) continue;
		 if(!knows(i,probableAns) && !knows(probableAns,i)) return -1;
	 } 	
	 return probableAns;	 
}