/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/
 
Node * uniqueSortedList(Node * head) {
    if(head == NULL)
        return NULL;
    
    
    Node *curr=head;
    
    
    while(curr!=NULL ){
        
        
        
        if(curr->next!=NULL && curr->data==curr->next->data ){
            
            Node *next_next=curr->next->next;
            Node *todelete=curr->next;
            delete(todelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    return head; 
}
