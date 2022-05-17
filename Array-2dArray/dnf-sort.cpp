// for the case of 0 1 and 2 only this method is more suitable than count sort as it has only single iteration


#include<bits/stdc++.h>
using namespace std;

void dnf_sort(int arr[],int n)
{
    int i=0,j=0,k=n-1;

    while(j<=k)
    {
        if(arr[j]==0){
        swap(arr[i],arr[j]);
        i++;
        j++;
        }
        else if(arr[j]==1)
        {
            j++;
        }
        else if(arr[j]==2)
        {
            swap(arr[j],arr[k]);
            k--;
        }
    }
}

int main ()
{
   int n;
   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }
   
   dnf_sort(arr,n);

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";

    return 0;
}