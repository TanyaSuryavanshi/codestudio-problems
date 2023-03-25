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

Node *removeDuplicates(Node *head)
{
   unordered_map<int,bool>visited;

   Node* temp=head;

   Node* prev=head;

   while(temp!=NULL)

   {

        if(visited[temp->data]==true)

        {

            Node* a=temp;

            prev->next=temp->next;

            temp=temp->next;

            a->next=NULL;

        }

        else

        {

            prev=temp;

            visited[temp->data]=true;

            temp=temp->next;

        }

   }

    return head;
}
