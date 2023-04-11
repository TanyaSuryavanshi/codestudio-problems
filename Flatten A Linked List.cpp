#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* head1, Node* head2) {

	Node* tempHead = new Node(0);
	Node* currNode = tempHead;
	Node* node1 = head1;
	Node* node2 = head2;

	head1->next = NULL; // VERY IMPORTANT
	head2->next = NULL; // VERY IMPORTANT

	while(node1 != NULL && node2 != NULL) {

		if(node1->data <= node2->data) {

			currNode->child = node1;
			currNode = node1;
			node1 = node1->child;
		}

		else {

			currNode->child = node2;
			currNode = node2;
			node2 = node2->child;
		}
	}

	if(node1 != NULL) currNode->child = node1;

	if(node2 != NULL) currNode->child = node2;

	return tempHead->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head->next == NULL) return head;

	return merge(head, flattenLinkedList(head->next));
}
