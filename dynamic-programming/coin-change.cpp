#include<bits/stdc++.h>
using namespace std;

// top_bottom
int getChange_one(int n, int dp[], int coin[], int s)
{
    if(n == 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];

    int ans = INT_MAX;

    for(int i=0;i<s;i++)
    {
        if(coin[i] <= n)
        ans = min (ans, getChange_one(n-coin[i], dp, coin, s)+1);
    }
    return dp[n] = ans;
}

// bottom_up
int getChange_two(int n, int coin[],int s)
{
    int dp[n+1] = {0};

    for(int i=1;i<=n;i++)
    {
        int ans = INT_MAX;
        for(int j=0;j<s;j++)
        {
            if(coin[j] <= i)
                ans = min(ans, dp[i - coin[j]]+1);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main ()
{
    int n;
    cin>>n;

    int size;
    cin>>size;
    int coin[size];
    for(int i=0;i<size;i++){
        cin>>coin[i];
    }
    
    int dp[n+1] = {0};
    cout<<getChange_one(n, dp, coin, size)<<endl;
    cout<<getChange_two(n, coin, size);

    return 0;
}