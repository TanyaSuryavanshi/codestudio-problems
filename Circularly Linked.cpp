#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    if(head == NULL) {
        return true;
    }
    //if(head->next==head)
       // return true;

    Node* slow=head;

    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;

        fast=fast->next->next;

        if (slow == fast) {

          if (slow == head)
            return 1;
          else
            return 0;
        }
    }
    return 0;
}
