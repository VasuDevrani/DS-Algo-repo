#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), hash(n);
        
        sort(nums.begin(), nums.end());
        
//         here dp array stores the length of longest chain that ends at it
//         hash stores the previous node in chain and will be used a backtrack for printing
        
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
        }
        
        int mx_ind = max_element(dp.begin(), dp.end()) - dp.begin();
        
        vector<int>ans;
        ans.push_back(nums[mx_ind]);
            
        while(hash[mx_ind] != mx_ind)
        {
            mx_ind = hash[mx_ind];
            ans.push_back(nums[mx_ind]);
        }
        
        return ans;
    }
};