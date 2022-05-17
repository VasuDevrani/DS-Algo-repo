#include<bits/stdc++.h>
using namespace std;
int get_num(int n)
{
     int s=0,h=n-1;
   while(1)
   {
      int mid=s+(h-s)/2;
      if(mid*mid==n)
      return mid;
      else if (mid*mid<n &&(mid+1)*(mid+1)>n)
      return mid;
      else if (mid*mid>n)
      h=mid;
      else if (mid*mid<n)
      s=mid+1;
   }
}
int main ()
{
   int n;
   cin>>n;
   cout<<get_num(n);

    return 0;
}