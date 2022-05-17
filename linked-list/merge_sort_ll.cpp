// O(nlogn) time complexity


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

node*midpoint(node*head)
{
    node*s=head;
    node*f=head->next;
    
    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
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
    if(a->data>=b->data)
   {
       c=b;
       c->next=sorted(a,b->next);
   }
   return c;
}

node*merge_sort(node*head)
{
//  base case
      if(head->next==NULL || head==NULL)
      {
          return head;
      }

// recursive case
    node*c;
    node*mid=midpoint(head);
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;

    a=merge_sort(a);
    b=merge_sort(b);

    c=sorted(a,b);
    return c;
}


int main()
{
    node *head1 = NULL;
    InsertatHead(head1, 2);
    InsertatHead(head1, 5);
    InsertatHead(head1, 1);
    InsertatHead(head1, 66);
     InsertatHead(head1, 4);
    InsertatHead(head1, 8);
    InsertatHead(head1, 0);
    InsertatHead(head1, 1);

    head1=merge_sort(head1);

    print(head1);
   
    return 0;
}