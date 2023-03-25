/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* floydDetectLoop(Node* head){
    if(head == NULL)
        return NULL;
    Node *slow=head;
    Node *fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;

        slow=slow->next;

        if(slow==fast)
            return slow;
    }
    return NULL;
}
Node *getstartingnode(Node *head){
    if(head == NULL)
        return NULL;
    
    Node *slow=head;
    
    Node *intersection=floydDetectLoop(head);
    if(intersection==NULL)
        return NULL;
    
    while(slow!=intersection){
        intersection=intersection->next;
        slow=slow->next;

    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if(head == NULL)
        return NULL;

    Node *startnode=getstartingnode(head);
    if(startnode==NULL)
        return head;
    Node *temp=startnode;
    while(temp->next!=startnode){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
