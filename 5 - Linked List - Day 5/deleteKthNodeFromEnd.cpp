/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* slow = head;
    Node* fast = head;
    Node* temp = head;
    while(K--) fast = fast->next;
    if(fast == NULL) return head->next;
    while(fast){
        temp = slow;
        fast = fast->next;
        slow = slow->next;
    }
    temp->next = slow->next;
    return head;
}
