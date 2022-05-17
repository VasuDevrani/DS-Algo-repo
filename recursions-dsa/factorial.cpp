#include<bits/stdc++.h>
using namespace std;
 
 int func(int n)
{
   if (n==1)
   return 1;
   int f1=func(n-1);
   int c=n*f1;
   return c;
}
int main ()
{
    int n;
    cin>>n;
   cout<<func(n);
    
    return 0;
}