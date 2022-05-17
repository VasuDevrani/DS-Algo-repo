#include <bits/stdc++.h>
using namespace std;

void tower(int n,char a,char b,char c)
{
    if(n==0)
    return;
   tower(n-1,a,c,b);
   cout<<n<<"("<<a<<"->"<<b<<")"<<endl;
  tower(n-1,c,b,a);
   return;
}
int main ()
{ int n;
char a,b,c;
cin>>n>>a>>b>>c;
tower(n,a,b,c);

    return 0;
}