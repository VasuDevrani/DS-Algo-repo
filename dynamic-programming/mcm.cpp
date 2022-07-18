#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int ansRecur(int n, int arr[], int i, int j, vector<vector<int>>&dp)
    {
        // base case
            if(i == j)
                return 0;
        
        // recursive case
        
            if(dp[i][j] != -1)
                return dp[i][j];
        
            int steps = INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                steps = min(steps, arr[i-1]*arr[k]*arr[j] + ansRecur(n, arr, i, k, dp) + ansRecur(n, arr, k+1, j, dp));
            }
            
            return dp[i][j] = steps;
    }
    
    int BotUp(int arr[], int n)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int steps = INT_MAX;
                for(int k=i;k<=j-1;k++)
                {
                    steps = min(steps, arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
                }
                
                dp[i][j] = steps;
            }
        }
        
        return dp[1][n-1];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // vector<vector<int>>dp(N, vector<int>(N, -1));
        // return ansRecur(N, arr, 1, N-1, dp);
        
        return BotUp(arr, N);
    }
};