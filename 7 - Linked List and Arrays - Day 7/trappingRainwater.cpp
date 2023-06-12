#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long lmax=0, rmax=0, l=0, r=n-1;
    long ans=0;
    while(l<=r){
        if(arr[l] <= arr[r]){
            if(arr[l] >= lmax) lmax = arr[l];
            else ans += lmax-arr[l];
            l++;
        }
        else{
            if(arr[r] >= rmax ) rmax = arr[r];
            else ans += rmax - arr[r];
            r--;
        }
    }
    return ans;
}



LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Hare Krishna 
    LinkedListNode<int>* ans; bool f = 1;
    while(head != NULL){
        LinkedListNode<int>* tmp = new LinkedListNode<int>(head -> data);
        if(f) ans = tmp, f = 0;
        tmp -> next = head -> next;
        tmp -> random = head -> random;
        head = head -> next;
        tmp = tmp -> next;

    }
    return ans;
}