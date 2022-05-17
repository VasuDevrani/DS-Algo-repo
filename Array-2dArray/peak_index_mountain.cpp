#include<bits/stdc++.h>
using namespace std;

int peak(int arr[],int n)
{
    int s=0,h=n-1;
   
    while(s<=h)
    {
        int mid=s+(h-s)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return arr[mid];
        else if (arr[mid]<arr[mid+1])
        s=mid+1;
        else 
        h=mid-1;
    }
   // wrong approach, tends to linear search
   /*int mid=n/2,c=0;
int max;
    while(c==0)
    {
        if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1])
        {c++; 
        max=arr[mid];}
        if(arr[mid]<arr[mid+1])
        mid=mid+1;
        if(arr[mid]<arr[mid-1])
        mid=mid-1;
    }
    return max;*/
}

int main ()
{
    int arr[8]={1,2,3,4,5,6,3,1};
     cout<< peak(arr,8);
    return 0;
}