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

int length(node *head)
{
    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void mid(node *head, int l)
{
    node*temp=head;
    if(l%2==0)
    {
        int half=l/2;
        for(int i=1;i<half;i++)
        {
            temp=temp->next;
        }
         cout<<temp->data<<endl;
    }
    else{
        int half=l/2;
        for(int i=0;i<half;i++)
        {
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
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
    
    int l=length(head);
    mid(head,l);

    return 0;
}