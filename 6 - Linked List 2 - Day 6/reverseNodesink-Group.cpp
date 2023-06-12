#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head == NULL || head->next == NULL) return head;
	int len=0;
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* pre = dummy, *cur = dummy, *nxt = dummy;
	while(cur->next){
		len++;
		cur= cur->next;
	}
	int i=0;

	while(len>0){
		cur = pre->next;
		nxt = cur->next;
		int t = 0;
		while(b[i] == 0) i++;
		if(i>=n) break;
		t = len-b[i] > 0 ? b[i] : len;
		for(int j=1; j<t; j++){
			cur->next = nxt->next;
			nxt->next = pre->next;
			pre->next = nxt;
			nxt = cur->next;
		}
		pre = cur;
		len = len-b[i];
		i++;
	}
	return dummy->next;

}