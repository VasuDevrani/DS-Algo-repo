#include<bits/stdc++.h>
using namespace std;
int small_elm(int arr[],int n)
{
    int s=0,h=n-1;
    while(s<h)
    {
       int mid=s+(h-s)/2;
       if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
       return arr[mid];
       else if (arr[mid]>arr[0])
       s=mid+1;
       else
       h=mid;

    }

}

int main ()
{
  int arr[5]={7,9,1,2,3};
   cout<<small_elm(arr,5);

   return 0;
}