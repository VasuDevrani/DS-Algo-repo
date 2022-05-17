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
        left=NULL;
        right=NULL;
    }
};

node*buildTree()
{
    // Taking the input of node
    int d;
    cin>>d;

    // base case
    if(d==-1)
    return NULL;

    // recursive case
    node*root=new node(d);
    root->left=buildTree();  //call to left node
    root->right=buildTree();   //call to right node
    return root;
}

void print_preorder_Tree(node*root)
{
    // base case
    if(root==NULL)
    return;

    // recursive case
    cout<<root->d<<" ";
    print_preorder_Tree(root->left);
    print_preorder_Tree(root->right);    
}

void print_inorder_Tree(node*root)
{
    // base case
    if(root==NULL)
    return;

    // recursive case
    print_inorder_Tree(root->left);
    cout<<root->d<<" ";
    print_inorder_Tree(root->right);    
}

void print_postorder_Tree(node*root)
{
    // base case
    if(root==NULL)
    return;

    // recursive case
    print_postorder_Tree(root->left);
    print_postorder_Tree(root->right);    
    cout<<root->d<<" ";
}

int main ()
{
    node*root=buildTree();
    print_preorder_Tree(root);
    cout<<endl;
    print_inorder_Tree(root);
    cout<<endl;
    print_postorder_Tree(root);

    return 0;
}