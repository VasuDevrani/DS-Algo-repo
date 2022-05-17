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

void count_sum_nodes(node*root,int &ct,int &sum) //O(n) time complexity 
{
    // recursive case
    sum+=root->d;
    if(root->left)
    count_sum_nodes(root->left,ct+=1,sum);
    if(root->right)
    count_sum_nodes(root->right,ct+=1,sum);
}

int count_node1(node*root)
{
    // base case
    if(root==NULL)
    return 0;

    // recursive case
    return 1+count_node1(root->left)+count_node1(root->right);
}

int main ()
{
    node*root=buildTree();
    int ct=1;
    int sum=0;
    count_sum_nodes(root,ct,sum);

    cout<<ct<<" "<<sum<<endl;

    cout<<"using another method "<<count_node1(root)<<endl;
    return 0;
}