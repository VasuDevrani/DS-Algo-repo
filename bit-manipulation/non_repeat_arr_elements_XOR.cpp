// repeat double only

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int arr[]={2,2,6,3,7,6,4,4,3};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    int res=0;
    for( int i=0;i<n;i++){
        cout<<arr[i]<<" ";
   res=res^arr[i];
    }
   cout<<endl<<res;
    return 0;
}