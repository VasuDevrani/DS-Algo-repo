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

void print_right_view(node*root,int level,int &maxl)
{
    // base case
    if(root==NULL)
    return;

    // recursive case
    if(maxl<level){
    cout<<root->d<<" ";
    maxl=level;
    }

    print_right_view(root->right,level+1,maxl);
    print_right_view(root->left,level+1,maxl);
}

int main ()
{
    node*root=buildTree();
    int maxl=0;
    cout<<root->d<<" ";
    print_right_view(root,0,maxl);
    return 0;
}