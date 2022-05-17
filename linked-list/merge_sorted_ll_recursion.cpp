#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(node *head1)
{
    node *temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertatHead(node *&head1, int d)
{
    if (head1 == NULL)
    {
        head1 = new node(d);
        return;
    }
    node *temp = new node(d);
    temp->next = head1;
    head1 = temp;
}

node*sorted(node*a,node*b)
{
   if(a==NULL)
   return b;
   if(b==NULL)
   return a;

   node*c;
   if(a->data<b->data)
   {
       c=a;
       c->next=sorted(a->next,b);
   }
    if(a->data>b->data)
   {
       c=b;
       c->next=sorted(a,b->next);
   }
   return c;
}

int main()
{
    node *head1 = NULL;
    InsertatHead(head1, 8);
    InsertatHead(head1, 6);
    InsertatHead(head1, 4);
    InsertatHead(head1, 2);

    node*head2=NULL;
    InsertatHead(head2, 7);
    InsertatHead(head2, 5);
    InsertatHead(head2, 3);
    InsertatHead(head2, 1);

    print(head1);
    print(head2);
    
    print(sorted(head1,head2));
    
    return 0;
}