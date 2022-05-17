#include <bits/stdc++.h>
using namespace std;
// Method 1

int first_occ(int arr[],int n,int k)
{
    int l=0,h=n-1,ans;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            h=mid-1;
        }
        else if(arr[mid]<k)
        l=mid+1;
        else if(arr[mid]>k)
        h=mid-1;

    }
   return ans+1;
}

int last_occ(int arr[],int n,int k)
{
    int l=0,h=n-1,ans;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==k)
        {
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]<k)
        l=mid+1;
        else if(arr[mid]>k)
        h=mid-1;

    }
   return ans+1;

}


int main ()
{
    int arr[7]={1,2,3,3,3,3,4};
    int k=3;
    cout<<"first occurence is "<<first_occ(arr,7,k)<<endl;
    cout<<"last occurence is "<<last_occ(arr,7,k)<<endl;
    return 0;
}