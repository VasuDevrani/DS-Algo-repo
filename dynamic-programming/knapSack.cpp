#include<bits/stdc++.h>
using namespace std;

class knapSack_solution{
    public:
    
    int knapSackRecur(int w, int n, int wt[], int val[])
    {
        // base case
        if(n == 0)
        {
            if(w >= wt[0])
                return val[0];
            else
                return 0;
        }
        // recursive case
        
        int not_take = knapSackRecur(w, n-1, wt, val);
        int take = INT_MIN;
        
        if(wt[n] <= w)
            take = val[n] + knapSackRecur(w-wt[n], n-1, wt, val);
            
        return max(take, not_take);
    }
    
    int TopBot(int w, int n, int wt[], int val[], vector<vector<int>>&dp)
    {
        // base case
        if(n == 0)
        {
            if(w >= wt[0])
                return val[0];
            else
                return 0;
        }
        // recursive case
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        
        int not_take = knapSackRecur(w, n-1, wt, val);
        int take = INT_MIN;
        
        if(wt[n] <= w)
            take = val[n] + knapSackRecur(w-wt[n], n-1, wt, val);
            
        return dp[n][w] = max(take, not_take);
    }
    
    int BotTop(int w, int n, int wt[], int val[])
    {
        vector<vector<int>>dp(n, vector<int>(w+1, 0));
        
        for(int i=wt[0];i<=w;i++)
            dp[0][i] = val[0];
            
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                int not_take = dp[i-1][j];
                int take = INT_MIN;
                
                if(wt[i] <= j)
                    take = val[i] + dp[i-1][j-wt[i]];
                    
                dp[i][j] = max(take, not_take);
            }
        }
        return dp[n-1][w];
    }
    
    int BotTop_space(int w, int n, int wt[], int val[])
    {
        vector<int>prev(w+1, 0), cur(w+1, 0);
        
        for(int j=wt[0];j<=w;j++)
            prev[j] = val[0];
            
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                int not_take = prev[j];
                int take = INT_MIN;
                
                if(wt[i] <= j)
                    take = val[i] + prev[j-wt[i]];
                    
                cur[j] = max(take, not_take);
            }
            prev = cur;
        }
        return prev[w];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // vector<vector<int>>dp(n, vector<int>(W+1, -1));
        
       return BotTop_space(W, n, wt, val);
    }
};