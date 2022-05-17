#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

void print(node*head)
{
    node*temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;

}

void insertAtHead(int d,node*&head){
    if(head==NULL)
    {
        head=new node(d);
        head->next=head;  //in order to run the below while loop
        return;
    }
    node*temp=new node(d);
    node*tail=head;

    while(tail->next!=head)
    {
        tail=tail->next;
    }
    temp->next=head;
    tail->next=temp;
    head=temp;

}


int main ()
{
    node*head=NULL;
   insertAtHead(2,head);
   insertAtHead(3,head);
   insertAtHead(4,head);
   insertAtHead(5,head);
   insertAtHead(6,head);
   insertAtHead(7,head);

   print(head);

    return 0;
}