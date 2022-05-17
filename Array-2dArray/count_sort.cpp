// linear time complexity
// space complexity O(n) with extra space

#include <bits/stdc++.h>
using namespace std;

void count_sort(int arr[],int max,int n)
{
   int *ptr=new int[max+1];
   for(int i=0;i<max+1;i++)
   {
       ptr[i]=0;
   }
   for(int i=0;i<n;i++)
   {
       ptr[arr[i]]++;
   }
   int *p=new int[n];
   int k=0;
   for(int i=0;i<max+1;i++)
   { 
       while(ptr[i]>0)
       {
           ptr[i]--;
           p[k]=i;
           k++;
       }
   }
    for (int i=0;i<6;i++)
    {
        cout<<p[i]<<" ";
    }
    delete(ptr);
    delete(p);
}

int main ()
{
    int max=0;
    int arr[6]={2,4,5,3,1,2};
    for(int i=0;i<6;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    count_sort(arr,max,6);
    return 0;
}