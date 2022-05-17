#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    bool isCheck(int m,int n,int *arr,int B)
{
    int sum=0;
    int st=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        return false;

        sum+=arr[i];
        if(sum>m)
        {
            sum=arr[i];
            st++;
        }
        if(st>B)
        return false;
    }
    return true;
}
    //Function to find minimum number of pages.
    int findPages(int A[], int n, int B) 
    {
    int l=INT_MAX,h=0;
    for(int i=0;i<n;i++)
    {
       if(A[i]<l)
       l=A[i];
    }
    for(int i=0;i<n;i++)
    {
     h+=A[i]; 
    }

    // binary search in the space l-h;
    int ans=INT_MAX;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
       if(isCheck(mid,n,A,B))
       {
           if(mid<ans)
           ans=mid;
           h=mid-1;
       }
       else 
       {
           l=mid+1;
       }
    }

   return ans;
}
    
};