#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int s,int e)
{
   int pivot=arr[s];
   int ct=0;
   for(int i=s+1;i<=e;i++)
   {
       if(arr[i]<=pivot)
       ct++;
   }
   int pi=s+ct;
   swap(arr[pi],arr[s]);
   int i=s,j=e;
   while(i<pi && j>pi)
   {
       while(arr[i]<=pivot)
       i++;
       while(arr[j]>pivot)
       j--;
       if(i<pi && j>pi)
       swap(arr[i++],arr[j--]);
       
   }
   return pi;
   
}
void quick_sort(int arr[],int s,int e)
{
    // base case
    if(s>=e)
    return;
    // partition
    int p=partition(arr,s,e);
    
    // left call
    if(p>0){
    quick_sort(arr,s,p-1);}
    quick_sort(arr,p+1,e);

}

int main ()
{
    int arr[8]={2,4,1,9,9,9,6,9};
    quick_sort(arr,0,7);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}