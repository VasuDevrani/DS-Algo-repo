#include <bits/stdc++.h>
using namespace std;

int area(vector<int>a1,vector<int>a2,int i,int n,vector<int>v)
{
   return ((abs(a1[i]-a2[n-i-1])+1)*v[i]);
}

int largest_rectangle(vector<int>v,int n)
{
    vector<int>left_small;
    vector<int>right_small;
    stack<int>s;
   //  for left small
   for(int i=0;i<n;i++)
   {int k=i;
      while(!s.empty())
     {
        if(v[k]<s.top())
        {k--;
        s.pop();}
        else 
        {
           left_small.push_back(k);
           s.push(v[i]);
           break;
        }
     }
      if(s.empty()){
      left_small.push_back(0);
       s.push(v[i]);
      }
   }

   // for right small
   for(int i=n-1;i>=0;i--)
   {int k=i;
      while(!s.empty())
     {
        if(v[k]<s.top())
        {k++;
        s.pop();}
        else 
        {
           right_small.push_back(k);
           s.push(v[i]);
           break;
        }
     }
      if(s.empty()){
      right_small.push_back(n-1);
      s.push(v[i]);
      }
   }
   int ar,res=0;
   for(int i=0;i<n;i++)
   {
      int ar=area(left_small,right_small,i,n,v);
      if(ar>res)
      res=ar;
   }
   return res;
}



int main ()
{
   vector<int>rect;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      rect.push_back(x);
   }
   int res=largest_rectangle(rect,n);
   cout<<res;
   return 0;
}