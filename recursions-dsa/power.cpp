#include<bits/stdc++.h>
using namespace std;
 
 int power(int n,int x)
{
   if (x==0)
   return 1;
//    int p=power(n,x-1);
//    int res=p*n;
//    return res;

   return n*power(n,x-1);
}
int main ()
{
    int n,x;
    cin>>n>>x;
   cout<<power(n,x);
    
    return 0;
}