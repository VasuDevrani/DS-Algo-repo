// solve for an example for better understanding

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        //Bottom-up dp approach
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
//         calculating the prefix sum
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int r1=max(0,i-k)+1; //begin row of the block
                int c1=max(0,j-k)+1; //begin column of the block
                int r2= min(i+k+1,m); //ending row of the block
                int c2= min(j+k+1,n); // ending column of the block
                
                //value of the block
                ans[i][j]=dp[r2][c2]+dp[r1-1][c1-1]-dp[r1-1][c2]-dp[r2][c1-1]; 
                
                //explanation for above formula
                
                // +(r2, c2) is like adding the sum of all elements of upto the last edge of req block
                // -(r2, c1-1) is like removing the sum of elements before first horizontal edge
                // -(r1-1, c2) is like removing the sum of elements before first vertical edge
                // +(r1-1, c1-1) is for adding the part which has been removed twice during last two operations
            }
        }
      return ans;  
    }
};