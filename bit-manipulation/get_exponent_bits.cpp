#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int b,p;
    cin>>b>>p;
    int ans=1;

    while(p!=0)
    {
        if((p&1)==1)
        ans*=b;
        b=b*b;
        p=p>>1;
    }
    cout<<ans;

    return 0;
}