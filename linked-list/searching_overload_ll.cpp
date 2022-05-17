#include<bits/stdc++.h>
using namespace std;

//  class for linked list nodes 
class node{
    public:
    int data;
    node*next;
    node(int d){
        this->data=d;
        next=NULL;
    }
};

//  function for inserting the elements in the linked list 
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

void print(node*head)
{
    node*tem=head;
    while(tem!=NULL)
    {
        cout<<tem->data<<" ";
        tem=tem->next;
    }
}

//  search function that returns index 
int search(node*head,int key)
{
    node*temp=head;
    int i=1;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return i;
        temp=temp->next;
        i++;
    }
    return 0;
}

// ostream operator overloading 
ostream &operator<<(ostream &os,node*head)
{
   print(head);
   cout<<endl;
   return os;
}

// reverse a linked list
void reverse(node*head)
{
   node*c=head;
   node*p=NULL;
   node*n;
   while(c!=NULL)
   {
       n=c->next;
       c->next=p;

       p=c;
        c=n;
   }   
   head=p;
   print(head);
}

int main ()
{
    //  taking input 
   int in;
   cin>>in;
   node*head=NULL;
   while(in--)
   {
       int d;
       cin>>d;
       Insertathead(head,d);
   }
   print(head);
   cout<<endl;

//  searching element's index 
   int key;
   cin>>key;
   cout<<endl<<"the ans is "<<search(head,key)<<endl;

//  using overloaded operator 
  cout<<head<<endl<<head<<endl;

//   reverse a linked list 
cout<<"reverse linked list"<<endl;
   reverse(head);

    return 0;
}
