#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node*left;
    node*right;

    node(int d)
    {
        this->d=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree()
{
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

int child_sum(node*&root)
{
    // base case
    if(root==NULL)
    return 0;

    // recursive case
    if(root->left==NULL && root->right==NULL)
    return root->d;

    int temp=root->d;
    int x=child_sum(root->left);
    int y=child_sum(root->right);
    root->d=x+y;

    return root->d+temp;
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

    child_sum(root);
    bfs_ladder(root);
    return 0;
}