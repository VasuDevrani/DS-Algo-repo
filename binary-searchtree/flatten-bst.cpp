// This particular algo prints the tree in levelled manner

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node*left;
    node*right;

    node(int d){
        this->d=d;
        left=NULL;
        right=NULL;
    }
};

node*buildTree()
{
    // Input
    int d;
    cin>>d;

    // base case
    if(d==-1)
    return NULL;

    // recursive case
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void bfs_ladder(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        if(q.front()!=NULL){
        node*temp=q.front();
        q.pop();

        cout<<temp->d<<" ";

        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);
        }
        else{
            cout<<endl;
            q.pop();
            if(!q.empty())
            q.push(NULL);
        }
    }
}

void insertAtEnd(node*&list,int d)
{
    if(list==NULL)
    {
        list=new node(d);
        return;
    }
    node*tail=list;
    while(tail->right!=NULL)
    tail=tail->right;

    node*temp=new node(d);
    tail->right=temp;
}

void flatten_tree(node*root,node*&list)
{
    // base case
    if(root==NULL)
    return;
    // recursive case
    flatten_tree(root->left,list);
    insertAtEnd(list,root->d);
    flatten_tree(root->right,list);
}

int main ()
{
    node*root=buildTree();
    bfs_ladder(root);
    cout<<endl;

    node*list=NULL;
    flatten_tree(root,list);
    bfs_ladder(list);

    return 0;
}