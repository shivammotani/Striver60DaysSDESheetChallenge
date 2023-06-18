#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int* arr;
    int tail;
    int max_size;

    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        tail = 0;
        max_size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(tail != max_size){
            arr[tail] = num;
            tail++;
        }
    }

    int pop() {
        // Write your code here.
        if(tail != 0){
            tail--;
            return arr[tail];
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        return (tail != 0)?(arr[tail - 1]):(-1);
    }
    
    int isEmpty() {
        // Write your code here.
        return (tail == 0);
    }
    
    int isFull() {
        // Write your code here.
        return (tail == max_size);
    }
    
};