//  Sample Input: 7
// 1 1 1 2 2 2 3
// Output Format: Output a single line containing the unique number
// Sample Output: 3


#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n=7;
    int arr[]={1,1,1,2,2,2,3};
    int sum[64]={0};

//    storing the sum of bits of different number
    int j=63;
    int ct;
    for(int i=0;i<n;i++)
    {
         int j=63;
        while(arr[i]>0)
        {
            sum[j]+=(arr[i]&1);
            arr[i]=arr[i]>>1;
            j--;
            ct=j;
        }
    }
    // for(int i=0;i<64;i++)
    // cout<<sum[i]<<" ";
    // cout<<endl;

// except the unique number all other number will contribute max of three units, hence their %3 would become 0;

    int ans=0;
    int p=1;
    for(int i=63;i>ct;i--)
    {
        ans=ans+(sum[i]%3)*p;
        p=p*10;
    }
   cout<<ans<<endl;
    // convert ans to binary

    int a=0;
    int q=1;
    while(ans>0)
    {
        a=a+(ans%10)*q;
        q=q*2;
        ans=ans/10;
    }
    cout<<a;

    return 0;
}