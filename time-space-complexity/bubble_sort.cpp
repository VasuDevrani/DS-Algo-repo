//time complexity O(n2)
// space complexity O(1);

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    bool swapped =false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped=true;}
        }
        if(swapped==false) // for checking the already sorted array in O(n) time....else it would have checked the sorted array in O(n2) time complexity....
        return;
    }
    
     for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
         cout<<endl;
}

int main ()
{
    int arr[7]={2,44,35,654,2,4,3};
   int n=sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);
    return 0;
}