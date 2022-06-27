#include<bits/stdc++.h>
using namespace std;

// basic method tc: O(2^n), sc: O(n)
int fibo_original(int n)
{
    if(n == 0 || n == 1)
    return n;

    return fibo_original(n-1) + fibo_original(n-2);
}
// top-bottom approach i.e. Recursion + Memoisation tc: O(n), sc:O(n)
int fibo_tb(int n, int dp[])
{
    if(n == 0 || n == 1)
    return n;

    if(dp[n-1] != 0)
    return dp[n-1];

    return dp[n-1] = fibo_tb(n-1, dp) + fibo_tb(n-2, dp);
}
// Bottom-Up approach tc: O(n), sc:O(n)
int fibo_bu(int n)
{
    int a = 0, b = 1;
    n -= 1;
    while(n--)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main ()
{
    int n;
    cin>>n;

    cout<<fibo_original(n)<<endl;

    int dp[n] = {0};
    cout<<fibo_tb(n, dp)<<endl;

    cout<<fibo_bu(n)<<endl;

    return 0;
}