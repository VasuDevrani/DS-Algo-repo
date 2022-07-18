#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string s, string s1, int n, int m)
{
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    
    int ans = 0;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s[i-1] == s1[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
}