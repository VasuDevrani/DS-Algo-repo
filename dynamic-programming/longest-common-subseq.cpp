#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int lcsRecur(string s1, string s2, int n, int m)
    {
//         base case
        if(n < 0 || m < 0)
            return 0;
        
//         recursive case
        if(s1[n] == s2[m])
            return 1 + lcsRecur(s1, s2, n-1, m-1); //when the chars are equal
        else
            return max(lcsRecur(s1, s2, n-1, m), lcsRecur(s1, s2, n, m-1)); 
            //when not equal there are two possibilities
    }
    
    int TopBot(string s1, string s2, int n, int m, vector<vector<int>>&dp)
    {
//         base case
        if(n < 0 || m < 0)
            return 0;
        
//         recursive case
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m])
            return dp[n][m] = 1 + lcsRecur(s1, s2, n-1, m-1); 
            //when the chars are equal
        else
            return dp[n][m] = max(lcsRecur(s1, s2, n-1, m), lcsRecur(s1, s2, n, m-1)); 
            //when not equal there are two possibilities
    }
    
    int BotUp(string s1, string s2, int n, int m)
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<m+1;i++)
            dp[0][i] = 0;
        
        for(int i=0;i<n+1;i++)
            dp[i][0] = 0;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        cout<<get_string_from_dp_array(s1, s2, dp)<<endl;

        return dp[n][m];
    }

    string get_string_from_dp_array(string s1, string s2, vector<vector<int>>dp)
    {
        // start from the end of strings i.e 5,5
        string ans = "";

        int i = s1.length(), j = s2.length();
        while(i >= 1 && j >= 1)
        {
            if(s1[i-1] == s2[j-1]){
                ans = s1[i-1] + ans;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    i--;
                else
                    j--;
            }
        } 

        return ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        
//       as there are two variables m, n in the argument of recur function, dp array must be 2D
        
//         vector<vector<int>>dp(n, vector<int>(m, -1));
        
//         return TopBot(text1, text2, n-1, m-1, dp);
        
        return BotUp(text1, text2, n, m);
    }
};