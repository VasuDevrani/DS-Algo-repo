#include<bits/stdc++.h>
using namespace std;

void merge_arr(int a[],int a1[],int n,int m)
{
    int arr[n+m];
   int i=0,j=0,k=0;
   while(i<n && j<m)
   {
      if(a[i]<a1[j])
      {
          arr[k]=a[i];
          i++;
      }
      else if(a[i]>a1[j])
      {
          arr[k]=arr[j];
          j++;
      }
      k++;
   }
   while(i<n)
   {
       arr[k]=a[i];
       i++;
       k++;
   }
    while(j<m)
   {
       arr[k]=a1[j];
       j++;
       k++;
   }

   for(int k=0;k<n+m;k++)
   cout<<arr[k]<<" ";
}

int main()
{
    int arr[5]={2,5,12,18,20};
    int arr1[8]={7,9,11,15,25,28,30,35};
   merge_arr(arr,arr1,5,8);

    return 0;
}