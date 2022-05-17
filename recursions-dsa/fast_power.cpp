#include<bits/stdc++.h>
using namespace std;

int fast_pow(int a,int n)
{
    // base case
    if(n==0)
    return 1;

//  recursive case
    int later_mult=fast_pow(a,n/2);
    later_mult*=later_mult;

    if(n&1)
        return a*later_mult;
    else
        return later_mult;
}

int slow_pow(int a,int n)
{
    if(n==0)
    return 1;
    return a*slow_pow(a,n-1);
}

int main ()
{
    int a,n;
    cin>>a>>n;
    cout<<fast_pow(a,n)<<" is same as "<<slow_pow(a,n);
    return 0;
}