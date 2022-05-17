#include <bits/stdc++.h>
using namespace std;
int max(int arr[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if (arr[i]>c)
        c=arr[i];
    }
    return c;
}
int min (int arr[], int n)
{
    int c=30;
    for(int i=0;i<n;i++)
    {if (arr[i]<c)
    c=arr[i];}
    cout<<c<<"c"<<endl;
    return c;
}

int main ()
{
    int n;
   cout<<"enter the no of bars \n";
   cin>>n;
   int arr[n];
   for (int i=0;i<n;i++)
   {
       cin>>arr[i];
}
  int mx=max(arr,n);
  int mn =min(arr,n);
 cout<<mx<<mn<<endl;
  for (int i=mx;i>mn;i--)
  {
      for (int j=0;j<n;j++)
      {
          if (arr[j]>=i)
          cout<<"*";
          else 
          cout<<" ";
      }
      cout<<endl;
  }

    return 0;
}