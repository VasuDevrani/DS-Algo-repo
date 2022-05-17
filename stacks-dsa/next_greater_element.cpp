#include <bits/stdc++.h>
using namespace std;

void check(int s,int arr[],int a[])
{
    for (int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     a[s-1]=-1;
    stack<int>s1;
    s1.push(arr[s-1]);

    for (int i=s-2;i>=0;i--)
    {
       
        while(!s1.empty() && arr[i]>s1.top())
        {
            s1.pop();
        }
        
        if (s1.empty()==false){
       a[i]=s1.top();
        s1.push(arr[i]);}
        else 
        {a[i]=-1;
        s1.push(arr[i]);}

    }
    for(int i=0;i<s;i++)
    cout<<a[i]<<" ";
}


int main ()
{
    int size;
   cout<<"size of array \n";
   cin>>size;
   int arr[size];
   int arr1[size];
   for (int i=0;i<size;i++)
   {
       cin>>arr[i];
   }
  check(size,arr,arr1);
    return 0;
}