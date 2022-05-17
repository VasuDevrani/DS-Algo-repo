#include<bits/stdc++.h>
using namespace std;

int binSearch(vector<int>arr,int l,int h,int k)
{
    int mid=l+(h-l)/2;
    
    if(l>h)
    return -1;

    if(arr[mid]==k)
    return mid+1;
     else if(arr[mid]<k)
     return binSearch(arr,mid+1,h,k);   //without return the whole program displays a garbage value
     else
     return binSearch(arr,l,mid-1,k);
}

int main ()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cin>>key;

    cout<<binSearch(arr,0,n-1,key);
    return 0;
}