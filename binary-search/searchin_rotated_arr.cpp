#include<bits/stdc++.h>
using namespace std;

int searchArray(int arr[],int n,int k)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;

        if(arr[mid]==k)
        return mid+1;

        // for duplicate elements
        if(arr[mid]==arr[l] && arr[mid]==arr[h])
        {
            l++;
            h--;
        }
        // check the part where the k could be present

        // left part
        if(arr[mid]<=arr[h])
        {
            // present in the space
            if(k<=arr[h] && k>=arr[mid])
            l=mid+1;

            // not present in the space
            else
            h=mid-1;
        }

        // right part
        else
        {
            if(k>=arr[l] && k<=arr[mid])
            h=mid-1;
            else
            l=mid+1;
        }
    }
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

    cout<<searchArray(arr,n,key);

    return 0;
}