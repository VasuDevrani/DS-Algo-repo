#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Insertathead(node*&head, int d)
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

node*glob;
node* reverse(node*head)
{
//   base case
   if(head==NULL || head->next==NULL)
   {
       glob=head;
       return head;
   }

// recursive case
    node *temp=head;
   
    node*prev=reverse(head->next);
    temp->next=NULL;
    prev->next=temp;
    return temp;
}

int main()
{
    node *head = NULL;
    Insertathead(head, 10);
    Insertathead(head, 11);
    Insertathead(head, 12);
    Insertathead(head, 13);
    Insertathead(head, 14);

    print(head);
    cout << endl;

    reverse(head);
    print(glob);
    cout << endl;

    return 0;
}