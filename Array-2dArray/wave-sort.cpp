// Sorting the given array in wave form 
// like Big-small-big-small...


#include<bits/stdc++.h>
using namespace std;

void wave_sort(int arr[],int n)
{
    int i=0,j=1;

    while(i<n && j<n)
    {
        if(arr[i]<arr[j])
         {
             swap(arr[i],arr[j]);
         }

         if(i>j)
         j+=2;
         else
         i+=2;
    }
}

int main ()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   cin>>arr[i];

   wave_sort(arr,n);

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

    return 0;
}