#include <bits/stdc++.h> 
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
//method-1
Node *getMiddle(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    
    if(head->next->next==NULL)
        return head->next;

    Node *slow=head;
    Node *fast=head->next;
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
//method-2
int getlength(Node *head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node *findMiddle(Node *head) {
    int len=getlength(head);
    int mid=len/2;
    int cnt=0;
    Node *temp=head;
    while(cnt<mid){
        temp=temp->next;
        cnt++;
    }
    return temp;
    
}
