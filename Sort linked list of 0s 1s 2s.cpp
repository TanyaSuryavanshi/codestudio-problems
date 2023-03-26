/********************************
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

********************************/

Node* sortList(Node *head)
{
    int zerocnt=0;
    int onecnt=0;
    int twocnt=0;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==0)
            zerocnt++;
        else if(temp->data==1)
            onecnt++;
        else if(temp->data==2)
            twocnt++;

        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
      if (zerocnt != 0) {
      
      temp->data = 0;
      zerocnt--;
      } 
      else if (onecnt != 0) {
        temp->data = 1;
        onecnt--;
      } 
      else if (twocnt != 0) {
        temp->data = 2;
        twocnt--;
      }
      temp = temp->next;
    }
    return head;
}
