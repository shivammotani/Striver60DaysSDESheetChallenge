/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* sortTwoLists(Node* first, Node* second){
	if(first == NULL) return second;
    if(second == NULL) return first;
    Node* temp =  new Node(0);
    Node* head = temp;
	
    while(first && second){
        if(first->data <= second->data){
            temp->child = first;
            temp = temp->child;
            first = first->child;
        }
        else{
            temp->child = second;
            temp = temp->child;
            second = second->child;
        }
    }
	if(first) temp->child = first;
	if(second) temp->child = second;
        
    return head->child;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL) return head;
    Node *right = head->next;
    right = flattenLinkedList(right);
    head->next = NULL;
    head = sortTwoLists(head, right);
    return head;
}
