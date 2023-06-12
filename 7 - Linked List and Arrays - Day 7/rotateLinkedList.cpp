/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head == NULL || head->next == NULL) return head;
     Node* temp = head;
     int len = 1;
     while(temp->next){
          len++;
          temp = temp->next;
     }
     
      if(k%len == 0) return head;
     k = k%len;
     k = len-k;
     temp->next = head;

     while(k--){
          temp = temp->next;
     }
     head = temp->next;
     temp->next = NULL;

     return head;

}