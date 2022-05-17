// Time complexity is O(n^2);

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

void print_kth_level(node*root,int k)
{
    // base case
    if(root==NULL)
    return;
    if(k==1)
    {
        cout<<root->d<<" ";
        return;
    }
    // recursive case
    print_kth_level(root->left,k-1);
    print_kth_level(root->right,k-1);
    return;
}


int main ()
{
    node*root=buildTree();
    int h=height(root);
    cout<<h;
    cout<<endl;

    print_kth_level(root,3);

    for(int i=1;i<=h;i++)
    {
        cout<<endl;
        print_kth_level(root,i);
    }

    return 0;
}