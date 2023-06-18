#include <bits/stdc++.h> 
class Queue {
public:
    int* arr;
    int frontt, rear, len;
    Queue() {
        // Implement the Constructor
        arr = new int[10000];
        frontt = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontt == rear) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[rear++] = data;

    }

    int dequeue() {
        // Implement the dequeue() function
        if(frontt != rear){
            int val = arr[frontt++];
            if(frontt == rear) {
                frontt = 0;
                rear = 0;
            }
            return val;
        }
        return -1;
    }

    int front() {
        // Implement the front() function
        return (frontt ==rear)?-1:arr[frontt];
    }
};