#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1;
    int size;

   public:
    Stack() {
        // Implement the Constructor.
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (size == 0)? true: false;
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
        int l = size;
        while(l--){
            int val = q1.front();
            q1.pop();
            q1.push(val);
        }
        size++;
    }

    int pop() {
        // Implement the pop() function.
         if(!q1.empty()){
            int val = q1.front();
            q1.pop();
            size--;
            return val;
             
         }
         else return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q1.empty()) return q1.front();
         else return -1;
    }
};