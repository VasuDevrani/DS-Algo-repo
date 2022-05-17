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

int height(node*root)
{
    // base case
    if(root==NULL)
    return 0;
    
    // recursive case
    int x=height(root->left);
    int y=height(root->right);

    return max(x,y)+1;
}


int main ()
{
    node*root=buildTree();
    cout<<height(root);
    return 0;
}