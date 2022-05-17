// finding the target sum in sorted array

#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int arr[8]={1,3,5,7,10,11,12,13};
    int t=16;   //target
    int i=0,j=7;
    while(i<j)
    {  
        int num=arr[i]+arr[j];
        if(num==t){
        cout<<arr[i]<<" "<<arr[j]<<endl;
        j--;
        i++;
        }
        else if(num<t)
        i++;
        else if(num>t)
        j--;
    }
    
    return 0;
}