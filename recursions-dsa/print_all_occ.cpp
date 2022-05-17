#include<bits/stdc++.h>
using namespace std;
void all_occ(int arr[],int i,int n,int key)
{
    if(i==n)
    return;
    if(arr[i]==key)
    cout<<i<<" ";
    all_occ(arr,i+1,n,key);
}


int main ()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   cin>>arr[i];

   int key;
   cin>>key;

   all_occ(arr,0,n,key);
    return 0;
}