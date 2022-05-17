#include<bits/stdc++.h>
using namespace std;

void lad(int n,string i)
{
    if(n==0)
    {
        cout<<i<<" ";
    }
    if(n<0)
    {
        return;
    }
   lad(n-1,i+"1");
   lad(n-2,i+"2");
   lad(n-3,i+"3");
}

int main ()
{
   int n;
   string i={};
   cin>>n;
   lad(n,i);

    return 0;
}