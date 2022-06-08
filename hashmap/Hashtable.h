#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T val;
    Node<T>*next;

    Node(string key, T val)
    {
        this->key=key;
        this->val=val;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL)
        delete next;
    }
};

template<typename T>
class Hashtable{

    int current_size;
    int table_size;
    Node<T>**table;

    int Hashfn(string key)
    {
        int ind=0;
        int p=1;

        for(int i=0;i<key.length();i++)
        {
            ind = ind + (key[i]*p)%table_size;
            p = p*27%table_size;
            ind = ind%table_size;
        }
        return ind; 
    }

    void rehash()
    {
        // store the old table
        Node<T>**oldTable = table;
        int oldTableSize = table_size;
        // iniitialize the table data member to a new larger size table in order to be able to use defined functions like insert...
        table_size = 2*table_size;
        table = new Node<T>*[table_size];
        current_size = 0;
        
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }

        for(int i=0;i<oldTableSize;i++)
        {
            Node<T>*head = oldTable[i];
            while(head!=NULL)
            {
                insert(head->key, head->val);
                head = head->next;
            }
            if(oldTable[i]!=NULL)
                delete oldTable[i];
        }
        delete [] oldTable;
    }

    Node<T>* deleteAtHead(Node<T>*head)
    {
        if(head==NULL)
        return NULL;
        Node<T>*newHead = head->next;
        delete(head);
        // head = newHead;
        return newHead;
    }
    void deleteAtEnd(Node<T>*head)
    {
        // Node<T>*tail = head;

    }
    void deleteAtMid(Node<T>*head)
    {
        // Node<T>*tail = head;

    }

    public:
    Hashtable(int ts=7){
        this->table_size=ts;
        this->current_size=0;

        // creating dynamically an array of pointers
        // For example int*ptr=new int[10] is a pointer to array of size 10
        // then int**p=new int*[10] is a pointer to array of pointers
        table=new Node<T>*[table_size];

        // to prevent wild pointers, pointing all to NULL
        for(int i=0;i<ts;i++)
        {
            table[i]=NULL;
        }
    }

    void insert(string key, T value)
    {
        int ind = Hashfn(key);
        Node<T>*head = new Node<T>(key, value);

        head->next = table[ind];
        table[ind] = head;
        current_size++;

        // rehashing is done to prevent the overincreament in size of linked list at each index with time complexity O(n)
        // else the complexity of search function is gonna exceed O(1)
        // Rehashing reduces the collision frequency as well

        if(current_size/table_size>0.7)
            rehash();
    }

//  here the return type of function is taken as a pointer of T type because if key is not present in the Table, we can't return -1 or no or something else as T is not fixed....
// So we return a NULL in that case
    T*search(string key)
    {
        int ind = Hashfn(key);
        Node<T>*temp = table[ind];

        while(temp!=NULL)
        {
            if(temp->key == key)
            return &temp->val;
        }
        return NULL;
    }

    void print()
    {
        for (int i=0;i<table_size;i++)
        {
            cout<<"BUCKET "<<i<<" -> ";
            Node<T>*temp = table[i];

            while(temp!=NULL)
            {
                cout<<temp->key<<" "<<temp->val<<" , ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void erase(string key)
    {
        int ind = Hashfn(key);
        Node<T>*temp = table[ind];

        if(temp->key == key)
            {
                table[ind] = deleteAtHead(temp);
                return;
            }
        temp = temp->next;
        while(temp!=NULL)
        {
            if(temp->key == key && temp->next == NULL)
            {
                deleteAtEnd(temp);
                return;
            }
            else if(temp->key == key)
            {
                deleteAtMid(temp);
                return;
            }
        }
    }
};