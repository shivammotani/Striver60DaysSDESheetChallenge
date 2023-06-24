 #include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int ans = 0;
   stack<int>st;
   vector<int>v;
   for(int i=0; i<=heights.size(); i++){
     while(!st.empty() && (i==heights.size() || heights[st.top()] >= heights[i])){
       int width = i, height = heights[st.top()];
       st.pop();
       if(!st.empty()) width = i-st.top()-1;
       ans = max(ans, width*height);
     }
     st.push(i);
   }
   return ans;
 }