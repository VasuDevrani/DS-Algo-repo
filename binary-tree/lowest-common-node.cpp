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

node*find_lca(int a,int b,node*root)
{
    // base
    if(root==NULL)
    return NULL;

    if(root->d==a || root->d==b)
    return root;
    // recursive 
    node*lans=find_lca(a,b,root->left);
    node*rans=find_lca(a,b,root->right);

    if(lans!=NULL && rans!=NULL)
    return root;

    if(lans!=NULL)
    return lans;

    if(rans!=NULL)
    return rans;
}

int main ()
{
    node*root=buildTree();

    int a,b;
    cin>>a>>b;

    node*ans=find_lca(a,b,root);
    
    cout<<ans->d;

    return 0;
}
