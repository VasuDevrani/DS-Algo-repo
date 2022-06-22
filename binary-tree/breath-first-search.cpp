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

void bfs(node*root)
{
    if(root==NULL)
    return;

    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        cout<<temp->d<<" ";
        if(temp->left)  //if temp->left is not NULL
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }

    }
    return;
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

int main ()
{
    node*root=buildTree();
    bfs(root);
    cout<<endl;
    bfs_ladder(root);

    return 0;
}

