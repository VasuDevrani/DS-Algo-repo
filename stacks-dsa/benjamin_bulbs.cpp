#include <bits/stdc++.h>
using namespace std;

bool change (bool x)
{
  if (x==true)
  return false;
  else 
  return true;

}
int main ()
{int n,rot,i,j;
cout<<"enter the n \n";
cin >>n;
   bool a[n];
   for (int k=0;k<n;k++)
   {
       a[k]=false;
   }
  cout<<"on bulbs"<<endl;
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if (j%i==0)
            a[j-1]=change(a[j-1]);
           
    }
    }
    for (i=0;i<n;i++)
    {
        if (a[i]==true )
        cout<<i+1<<" ";
    }
    return 0;
}