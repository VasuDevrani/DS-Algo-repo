// time complexity = O(n^2)
// space complexity = O(1)
// for small sized array

#include<bits/stdc++.h>
using namespace std;

void select_sort(int arr[],int n)
{
   for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<n;j++)
       {
            if(arr[j]<arr[i])
            swap(arr[j],arr[i]);
       }
       for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   }
}
int main()
{
   int arr[7]={2,44,35,654,2,4,3};
   int n=sizeof(arr)/sizeof(int);
    select_sort(arr,n);
    return 0;
}