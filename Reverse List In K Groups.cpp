#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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

Node *reverseLinkedList(Node *head,int k) 
{   
    if(head==NULL)
        return NULL;
    int cnt = 0; 

    Node *prev=NULL;
    Node *curr=head;
    Node *forward=NULL;//=curr->next;
    while(curr!=NULL && cnt<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
        
    }
    if(forward!=NULL)
        head->next=reverseLinkedList(forward,k);
    return prev;
    
}

Node *kReverse(Node *head, int k) { 
   reverseLinkedList(head,k);

}














