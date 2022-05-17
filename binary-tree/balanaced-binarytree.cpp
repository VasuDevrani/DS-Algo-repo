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

class tree
{
    public:
    bool a;
    int h;
};

tree check_balanced(node*root)
{
    // base case
    if(root==NULL)
    {
        tree t;
        t.a=true;
        t.h=0;
        return t;
    }

    // recursive case
    tree t1=check_balanced(root->left);
    tree t2=check_balanced(root->right);

    tree tans;
    tans.h=max(t1.h,t2.h)+1;

    if(abs(t2.h-t1.h)<=1 && t1.a==true && t2.a==true)
    tans.a=true;
    else
    tans.a=false;

    return tans;
}

int main ()
{
    node*root=buildTree();
    tree ans=check_balanced(root);

    cout<<ans.a<<endl;

    return 0;
}