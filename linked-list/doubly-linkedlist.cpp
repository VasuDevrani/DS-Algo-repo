#include<bits/stdc++.h>
using namespace std;

class dnode
{
    public:
    int data;
    dnode* next;
    dnode* prev;

    dnode(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};

void print(dnode*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void insertAtHead(int d,dnode*&head)
{
     if(head==NULL)
     {
         head=new dnode(d);
         return;
     }
     dnode*temp=new dnode(d);
     temp->next=head;
     head->prev=temp;
     head=temp;
}


int main ()
{
    dnode*head=NULL;
    insertAtHead(2,head);
    insertAtHead(3,head);
    insertAtHead(4,head);
    insertAtHead(5,head);
    insertAtHead(6,head);
    insertAtHead(7,head); 
    
    print(head);
    return 0;
}