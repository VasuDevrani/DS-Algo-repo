// linked list
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

// Insertion of node
void insertAtHead(node *&head, int d)
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

// Length of a linked list
int lengthList(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp->next != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void insertAtEnd(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *temp = new node(d);
    tail->next = temp;
}

void insertAtMid(node *&head, int d, int p)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    if (p == 1)
    {
        insertAtHead(head, d);
        return;
    }

    if (p > lengthList(head))
    {
        insertAtEnd(head, d);
        return;
    }

    node *temp = head;
    for (int i = 0; i < p - 2; i++)
    {
        temp = temp->next;
    }
    node *add = new node(d);
    add->next = temp->next;
    temp->next = add;
}

// Deletion of node

void deleteHead(node *&head)
{
    node*temp=head->next;
    delete(head);
    head=temp;
}

void deleteEnd(node *&head)
{
    if(head==NULL)
    return;
    if(head->next==NULL)
    {
    delete(head);
    return;
    }
    node*prev=head;
    while(prev->next->next!=NULL)
    {
        prev=prev->next;
    }
    delete (prev->next);
    prev->next=NULL;
}

void deleteMid(node *&head,int p)
{
    if(head==NULL)
    return;
    if(p==1)
    deleteHead(head);
    else if(p==lengthList(head))
    deleteEnd(head);
    else
    {
        node*temp=head;
        for(int i=0;i<p-2;i++)
        {
           temp=temp->next;
        }
        node*temp1=temp->next->next;

        delete(temp->next);
        temp->next=temp1;
    }

}

// Print list
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Reverse list
void reverse(node *head)
{
    if(head==NULL)
    return;

    node*c=head;
    node*p=NULL;
    node*n;

    while(c->next!=NULL)
    {
           n=c->next;
           c->next=p;
           p=c;
           c=n;
    }
    head=p;
    print(head);
    
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 70);
    insertAtHead(head, 90);

    insertAtEnd(head, 30);

    insertAtMid(head, 50, 2);

    print(head);
    cout << endl;

    deleteHead(head);
    print(head);
    cout << endl;

    deleteEnd(head);
    print(head);
    cout << endl;

    deleteMid(head,3);
    print(head);
    cout << endl;

    reverse(head);
    print(head);
    cout << endl;

    return 0;
}