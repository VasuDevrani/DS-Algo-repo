#include <bits/stdc++.h>
using namespace std;
void stock(int n,int arr[])
{
   stack<int>s;
   int c=1,p;
  int arr1[n];
   s.push(arr[0]);
   arr1[0]=1;
   cout<<"for "<<arr[0]<<" span is "<<arr1[0]<<endl;
   for(int i=1;i<n;i++)
   { p=i;
       while (s.size()>0 && arr[i]>s.top())
       {
           s.pop();
           c=arr1[p-1]+c;
           p--;
          
       }
       s.push(arr[i]);
       arr1[i]=c;
       cout<<"for "<<arr[i]<<" span is "<<arr1[i]<<endl;
       c=1;
   }

}

int main ()
{
  int size;
  cout<<"enter the size of array \n";
  cin>>size;
  int arr[size];
  cout<<"enter the elements of array \n";
  for (int i=0;i<size;i++)
  {
      cin>> arr[i];
  }
  stock(size,arr);
    return 0;
}