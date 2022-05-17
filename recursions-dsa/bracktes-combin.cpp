#include<bits/stdc++.h>
using namespace std;

void print_brackets(int n,int i,int j,string s)
{
    // base
    if(i==n/2 && j==n/2)
    {
        cout<<s<<endl;
        return;
    }

    // recursive
    if(i<=n/2){
    print_brackets(n,i+1,j,s+"( ");
    }
    if(j<=n/2 && (j+1)<=i){
    print_brackets(n,i,j+1,s+") ");
    }
     
}

int main ()
{
    int n;
    cin>>n;
    print_brackets(n,0,0,"");

    return 0;
}