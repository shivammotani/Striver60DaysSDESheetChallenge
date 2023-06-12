#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL) return true;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> *middle = slow->next;
    LinkedListNode<int> *temp = NULL;

    while(middle != NULL){
        LinkedListNode<int>* nxt = middle->next;
        middle->next = temp;
        temp = middle;
        middle = nxt;
        }
    slow->next = temp;
    slow = slow->next;
    fast = head;

    while(slow){
        if(slow->data != fast->data) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;


}