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

        // rehashing is done to prevent the overincreament in size of linked list at each index
        // else the complexity of search function is gonna exceed O(1)

    }

    // T search(string key)
    // {

    // }

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
};