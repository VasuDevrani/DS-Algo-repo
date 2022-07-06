#include<bits/stdc++.h>
using namespace std;

int check_Recur(vector<int>v, int n, int t)
{
    // base case
    if(t == 0)
    return true;

    if(n == 0)
    {
        if(v[0] == t)
        return true;
        else
        return false;
    }
    // recursive case

    bool not_take = check_Recur(v, n-1, t);
    bool take = false;
    if(v[n] <= t){
        take = check_Recur(v, n-1, t-v[n]);
    }

    return take | not_take;
}

int check_TopBot(vector<int>v, int n, int t, vector<vector<int>>&dp)
{
    // base case
    if(t == 0)
    return true;

    if(n == 0)
    {
        if(v[0] == t)
        return true;
        else
        return false;
    }
    // recursive case

    if(dp[n][t] != -1)
    return dp[n][t];

    bool not_take = check_TopBot(v, n-1, t, dp);
    bool take = false;
    if(v[n] <= t){
        take = check_TopBot(v, n-1, t-v[n], dp);
    }

    return dp[n][t] = (take | not_take);
}

int check_Bottop(vector<int>v, int n, int t)
{
    vector<vector<int>>dp(n, vector<int>(t+1, 0));

    for(int i=0;i<n;i++)
        dp[i][0] = true;
    
    dp[0][v[0]] = true;

    for(int i=1;i<n;i++) //index
    {
        for(int j=1;j<=t;j++) //target
        {
            bool not_take = dp[i-1][j];
            bool take = false;
            if(v[i] <= t){
                take = dp[i-1][j-v[i]]; 
            }
            dp[i][j] = (take | not_take);
        }
    }
    return dp[n-1][t];
}

int Bot_Up_space(vector<int>v, int n, int t)
{
    vector<bool>prev(t+1, 0), cur(t+1, 0);

    prev[0] = 1, cur[0] = 1;

    prev[v[0]] = 1;

    for(int i=1;i<n;i++) //index
    {
        for(int j=1;j<=t;j++) //target
        {
            bool not_take = prev[j];
            bool take = false;
            if(v[i] <= j){
                take = prev[j-v[i]]; 
            }
            cur[j] = (take | not_take);
        }
        prev = cur;
    }

    return prev[t];
}

int main ()
{
    vector<int>arr = {1,2,3,4};

    int n = 4;
    int target = 88;

    cout<< check_Recur(arr, n-1, target)<<endl;

    // a 2d vector with coordinates of index, target;
    vector<vector<int>>dp(n, vector<int>(target + 1, -1));

    cout<<check_TopBot(arr, n-1, target, dp)<<endl;

    cout<<check_Bottop(arr, n, target)<<endl;

    cout<<Bot_Up_space(arr, n, target)<<endl;

    return 0;
}