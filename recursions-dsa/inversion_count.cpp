#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;

    int ct=0;
    int n1=mid-s+1;
    int n2=e-mid;

    int a[n1],b[n2];

     int j=0,k=0;
   for(int i=s;i<=mid;i++)
   {
       a[j++]=arr[i];
   }
   for(int i=mid+1;i<=e;i++)
   {
       b[k++]=arr[i];
   }

   int i=0; j=0; k=s;

   while(i<n1 && j<n2)
   {
       if(a[i]<=b[j])
       arr[k++]=a[i++];
       else{
        ct+=(n1-i);
       arr[k++]=b[j++];
       }
   }

   while(i<n1)
   {
    //    ct+=(n1-i-1); mistake overcounting
       arr[k++]=a[i++];
   }
   while(j<n2)
   {
       arr[k++]=b[j++];
   }
    return ct;
}

int count_inversions(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return 0;

    // recursive calls
    int mid = (s + e) / 2;

    int x = count_inversions(arr,s,mid);
    int y=count_inversions(arr,mid+1,e);
    
    // merging arrays
    int z=merge(arr,s,e);
   
    return x+y+z;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << count_inversions(arr, 0, n - 1);
    return 0;
}