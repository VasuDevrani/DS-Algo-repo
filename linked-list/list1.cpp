// linked list, printing and traversing the list, creating list 

#include <bits/stdc++.h>
using namespace std;

// creating nodes
class node{
    public:
   int data;
   node *next;
   node(int data){
       this->data=data;
       this->next=NULL;
   }
};

// length of linked list
int length(node*head)
{int c=0;
node*temp=head;
    while(temp!=NULL)
    {
    temp=temp->next;
        c++;
    }
    return c;
}

// inserting a new node and creating list
void Insertathead(node*&head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}

void Insertattail(node*&head,int d)
{
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    node*temp=new node(d);
    tail->next=temp;
}

void Insertatmid(node*&head,int d, int p)
{
    if(head==NULL || p==0)
     {
         Insertathead(head,d);
     }
     else if(p>length(head))
     Insertattail(head,d);
     else{
         int s=0;
    node*temp=new node(d);
    node*it=head;
      for(int i=0;i<p-1;i++)
      {
          it=it->next;
      }
      temp->next=it->next;
      it->next=temp;
     }
}

// creating the print function
void print(node*head){
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

// delete elements

void deleteHead(node*&head)
{
    if(head==NULL)
    return;
    node*temp=head->next;
    delete head;
    head=temp;
}

void deleteEnd(node*&head)
{
    if(head==NULL)
    return;
    if(head->next==NULL)
    {delete(head);
    return;}
    node*prev=head;
    while(prev->next->next!=NULL)
    {
        prev=prev->next;
    }
    delete (prev->next);
    prev->next=NULL;
}

void deleteMid(node*head, int p)
{
    if(head==NULL)
    return;
    if(head->next==NULL)
    deleteHead(head);
    node*temp=head;
    for(int i=2;i<p;i++)
    {
       temp=temp->next;
    }
    node*del=temp->next;
    temp->next=temp->next->next;
    delete(del);
}

// reverse linked list
void reverse(node *head)
{
    if (head == NULL)
        return;
    node *c = head;
    node *p = NULL;
    node *n;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    print(head);
}

int main ()
{
   node*head=NULL;
   Insertathead(head,10);
   Insertathead(head,8);
   Insertathead(head,9);

   Insertattail(head,6);
   Insertattail(head,5);
   
   Insertatmid(head,2,3);
   
   print(head);
   cout<<endl;
   
   deleteHead(head);
   print(head);
   cout<<endl;

   deleteEnd(head);
   print(head);
   cout<<endl;

   deleteMid(head,3);
    print(head);
   cout<<endl<<"hi"<<endl;

   reverse(head);
   cout<<endl;

    return 0;
}