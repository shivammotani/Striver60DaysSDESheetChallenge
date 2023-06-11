#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL) return second;
    if(second == NULL) return first;
    Node<int>* temp =  new Node<int>(-1);
    Node<int>* head = temp;
    while(first && second){
        if(first->data <= second->data){
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
        else{
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
    if(first != NULL ) temp->next = first;
    if(second != NULL ) temp->next = second;
    return head->next;
}
