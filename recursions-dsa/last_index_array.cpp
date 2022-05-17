#include<bits/stdc++.h>
using namespace std;
int size;
int last_ind(int arr[],int i,int key)
{
  if(i>size-1)
  return -1;
  if(arr[i]==key)
  return i;
  else 
  {
      int num=last_ind(arr,i-1,key);
      return num;
  }

}
int main()
{
cin>>size;
int arr[size];
for (int i=0;i<size;i++)
{
    cin>>arr[i];
}
cout<<"enter the key \n";
int key;
cin>>key;
int ind=last_ind(arr,size-1,key);
cout<<ind+1;


    return 0;
}