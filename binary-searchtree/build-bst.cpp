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

node*insertAtNode(node*root,int a)
{
    if(root==NULL){
    return new node(a);
    }

    if(root->d<a)
    {
        root->right=insertAtNode(root->right,a);
    }
    if(root->d>=a)
    {
        root->left=insertAtNode(root->left,a);
    }
    return root;
}

node*build_bst()
{
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1)
    {
        root=insertAtNode(root,d);
        cin>>d;
    }
    return root;
}

int main ()
{
    node*root=build_bst();
    bfs_ladder(root);

    return 0;
}