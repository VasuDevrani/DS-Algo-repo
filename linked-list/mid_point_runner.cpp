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

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertatHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

node*mid(node*head)
{
    if(head==NULL && head->next==NULL)
    return head;
    node*s=head;
    node*f=head->next;
    while(f!=NULL || f->next!=NULL)
    {
        f=f->next->next; 
        s=s->next;
    }
     return s;
}

int main()
{
    node *head = NULL;
    InsertatHead(head, 10);
    InsertatHead(head, 5);
    InsertatHead(head, 6);
    InsertatHead(head, 2);
    InsertatHead(head, 11);

    print(head);
    
    node*ans=mid(head);
    cout<<ans->data<<endl;

    return 0;
}

    // if(l%2==0)
    // {
    //     s=head;
    //     f=head->next;
    //     while(f->next!=NULL)
    //     {
    //         s=s->next;
    //         f=f->next->next;
    //     }
    //    cout<<s->data<<endl;
    // }
    // else{
    //     s=head;
    //     f=head;
    //     while(f->next!=NULL)
    //     {
    //         s=s->next;
    //         f=f->next->next;
    //     }
       
    //     cout<<s->data<<endl;
    // }
