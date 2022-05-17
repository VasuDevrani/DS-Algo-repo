#include <bits/stdc++.h>
using namespace std;
int main ()
{

//    using KADANE's algorithm (single loop)
     
      int arr[9]={-4,1,3,-2,6,2,-8,-9,4};
      int ans=arr[0];
      int sum=0;
      for(int i=0;i<9;i++)
      {
          sum+=arr[i];
           if(sum>ans)
          ans=sum;
          if(sum<0)  //condition for removing the possibility of sum decreament;
          sum=0;
      }
      cout<<ans;








    // using cumulative sum O(n2)
    // int arr[9]={-4,1,3,-2,6,2,-8,-9,4};
    // int csum[9]={0};
    // int sum=0; int c=INT_MIN;
    // for(int i=0;i<9;i++)
    // {sum+=arr[i];
    //   csum[i]=sum;
    // }

    // for(int i=0;i<9;i++)
    // {
    //     for(int j=i;j<9;j++)
    //     {
    //         if(csum[j]-arr[i]>c)
    //         c=csum[j]-arr[i];
    //     }
    // }
    // cout<<c;





    // using triple loops O(n3)
    // int c=INT_MIN;
    // for(i=0->i<n)
    // {
    //     for(j=i->j<n)
    //     {int sum=0;
    //         for(k=i->k<=j)
    //         sum+=arr[k];
    //         if(sum>c)
    //         c=sum;
    //     }
    // }

    return 0;
}