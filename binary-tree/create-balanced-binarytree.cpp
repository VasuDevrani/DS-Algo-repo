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

node*balancedTree(int arr[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2;
    node*root=new node(arr[mid]);

    root->left=balancedTree(arr,s,mid-1);
    root->right=balancedTree(arr,mid+1,e);
    return root;
}

void bfs(node*root)
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

int main ()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    node*root=balancedTree(arr,0,n-1);

    bfs(root);

    return 0;
}