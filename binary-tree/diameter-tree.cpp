// There are n nodes so for diameter function n nodes are traversed and each height involves n nodes traversal
// So time complexity is O(n^2)

// But the faster diameter method is O(n)

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

int diameter(node*root)
{
    // base case
    if(root==NULL)
    return 0;

    // recursive case
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left); //left part max diameter
    int op3=diameter(root->right); //right part max diameter

    return max(max(op1,op2),op3);
}

class heid{
    public:
    int h;
    int d;
};

heid diameter_better(node*root)
{
    // base case
    if(root==NULL)
    {
        heid p;
        p.h=0;
        p.d=0;
        return p;
    }

    // recursive case
    heid left=diameter_better(root->left);
    heid right=diameter_better(root->right);

    heid p;
    p.h=max(left.h,right.h)+1;
    p.d=max(max(left.h+right.h,left.d),right.d);

    return p;
}

int main ()
{
    node*root=buildTree();
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;

    heid ans=diameter_better(root);
    cout<<"diameter "<<ans.d<<" height "<<ans.h<<endl;

    return 0;
}