// time complexity O(nlogn)
// space complexity O(n)
// Since the vectors uses more time, a more efficient solution is present on LEETCODE as 'sort an array' problem

#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int>v,int s,int e)
{
    // base case
    if((e-s)==0)
    {
        vector<int>ans;
        ans.push_back(v[s]);
        return ans;
    }
    // recursive calls
    int mid=(e-s)/2;
    vector<int>left=merge_sort(v,s,mid+s);
    vector<int>right=merge_sort(v,mid+s+1,e);

    // merging of arrays
     vector<int>ans;

     int i=0,j=0;
     while(i<left.size() && j<right.size())
     {
         if(left[i]<=right[j])
         {
             ans.push_back(left[i]);
             i++;
         }
         else if(left[i]>right[j])
         {
             ans.push_back(right[j]);
             j++;
         }
     }

     while(j<right.size())
     {
         ans.push_back(right[j]);
         j++;
     }
     while(i<left.size())
     {
         ans.push_back(left[i]);
         i++;
     }
     return ans;
}



int main()
{
   int n;
   cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       v.push_back(x);
      }
      vector<int>ans=merge_sort(v,0,n-1);

      for(int i=0;i<n;i++)
      cout<<ans[i]<<" ";

    return 0;
}

