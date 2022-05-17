#include<bits/stdc++.h>
using namespace std;


void stock(int n,int arr[])
{
    stack<int>temp;
    vector<int>ans;

    temp.push(0);
    ans.push_back(0);  //Stores the previous greater element

    for(int i=1;i<n;i++)  
    {
        while(!temp.empty() && arr[i]>=arr[temp.top()])
        {
            temp.pop();
        }
        if(temp.empty()){
        ans.push_back(0);
        continue;
        }
        if(arr[i]<arr[temp.top()])
        {
            ans.push_back(temp.top());
            temp.push(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i-ans[i]<<" ";
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