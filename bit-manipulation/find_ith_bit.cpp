#include<bits/stdc++.h>
using namespace std;
void dec_bin(int x)
{
    while(x!=0)
    {if(x%2==1)
    cout<<x%2;
    x=x/2;
    }
}
int main ()
{
   int n,i;
   cin>>n>>i;
   int x=n & (1<<(i-1));
   dec_bin(x);
    return 0;
}