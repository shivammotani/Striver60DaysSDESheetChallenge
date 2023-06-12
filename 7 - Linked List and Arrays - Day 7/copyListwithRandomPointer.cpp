#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head == NULL ) return NULL;
    LinkedListNode<int>* item = head;
    while(item){
        LinkedListNode<int>* temp = new LinkedListNode<int>(item->data);
        temp->next = item->next;
        item->next = temp;
        item = temp->next;
    }

    item = head;
    while(item){
        if(item->random == NULL) item->next->random = NULL;
        else item->next->random = item->random->next;
        item = item->next->next;
    }

    item = head;
    LinkedListNode<int>* dummy = item->next;
    LinkedListNode<int>* ans = dummy; 
    
    while(item){
        LinkedListNode<int>* fwd = dummy->next;
        item->next = fwd;
        item = fwd;
        if(fwd == NULL) {
            dummy->next = NULL;
            break;
        }
        dummy->next = fwd->next;
        dummy = dummy->next;
    }

    return ans;

}
