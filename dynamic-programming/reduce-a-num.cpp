#include<bits/stdc++.h>
using namespace std;

// top bottom approach
int getCount_one(int n, int dp[])
{
    if(n == 1)
    return 0;

    if(dp[n-1] != 0)
        return dp[n-1];

    int x = INT_MAX, y = INT_MAX, z;
    if(n%2 == 0)
    {
        x = getCount_one(n/2, dp);
    }
    else if(n%3 == 0){
        y = getCount_one(n/3, dp);
    }
    z = getCount_one(n-1, dp);

    return dp[n-1] = min(min(x,y), z) + 1;
}


// bottom up approach
int getCount_two(int n)
{
    int dp[n+1] = {0};
    for(int i=1;i<=n;i++)
    {
        if(i == 1)
            dp[i] = 0;
        else{
            int x = INT_MAX, y = INT_MAX, z = INT_MAX;
            if(i%3 == 0)
                y = dp[i/3];
            if(i%2 == 0)
                x = dp[i/2];
            z = dp[i-1];

            dp[i] = min(min(x,y), z) +1;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    int dp[n] = {0};
    cout<<getCount_one(n, dp)<<endl;
    cout<<getCount_two(n)<<endl;

    return 0;
}