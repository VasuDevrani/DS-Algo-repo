class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        
        deque<int>q;
        q.push_back(0);
        for(int i=1;i<k;i++)
        {
            while(!q.empty() && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        
        if(k==nums.size())
            return ans;
        
        int i=1;
        
        for(int j=k;j<nums.size();j++)
        {
            while(!q.empty() && nums[q.back()]<nums[j])
                q.pop_back();
            
            if(!q.empty() && q.front()<i)
                q.pop_front();
            
            q.push_back(j);
            ans.push_back(nums[q.front()]);
            i++;
        }
        
        return ans;
    }
};