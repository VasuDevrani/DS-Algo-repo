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

bool search_bst(node*root,int k)
{
    if(root==NULL)
    return false;

    if(root->d==k)
    {
        return true;
    }

    if(root->d<k)
    return search_bst(root->right,k);
    else
    return search_bst(root->left,k);
}

node*deleteNode(node*root,int k)
{
    // base case
    if(root==NULL)
    return root;

    if(root->d==k)
    {
        // delete node in three different case
        
        // case 1 : When the root node is leaf node
        if(root->left==NULL && root->right==NULL){
        delete(root);
        return NULL;
        }

        // case 2 : When the root has single child
        else if(root->left==NULL && root->right!=NULL)
        {
            node*temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            node*temp=root->left;
            delete(root);
            return temp;
        }

        // case 3 : When the root has two children
        else if(root->left!=NULL && root->right!=NULL)
        {
            node*replace=root->right;
            // finding the smallest node in right subtree to replace the value of root node 
            while(replace->left!=NULL)
            {
                replace=replace->left;
            }
            root->d=replace->d;

            root->right=deleteNode(root->right,replace->d);
            return root;
        }

    }
    if(root->d<k)
    root->right=deleteNode(root->right,k);
    else
    root->left=deleteNode(root->left,k);

    return root;
}

int main ()
{
    node*root=build_bst();
    int k;
    cin>>k;

    cout<<search_bst(root,k)<<endl;

    bfs_ladder(root);
    cout<<endl;

    cin>>k;
    root=deleteNode(root,k);

    bfs_ladder(root);

    return 0;
}