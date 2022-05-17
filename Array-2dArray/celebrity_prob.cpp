#include <bits/stdc++.h>
using namespace std;

int celeb(vector<vector<int>>&M,int n)
{
    // condition for all row elements be zero
   vector<int>res;
   for(int i=0;i<n;i++)
   {
        int *p=new int;
     for(int j=0;j<n;j++)
     {
         *p+=M[i][j];
     }
     if(*p==0)
    res.push_back(i);
    *p=0;
   }
   
//    condition for column elements be 1
   for(int i=0;i<res.size();i++)
   { int *p=new int;
      for(int k=0;k<n;k++)
      {
         *p+=M[res[i]][k];
      }
      if(*p==2)
      return res[i];
   }
   return 0;
}
int main ()
{
   int r;
   cin>>r;
   vector<vector<int>>v(r);
   int y;
   for(int i=0;i<r;i++)
   {
       for (int j=0;j<r;j++)
       {
           cin>>y;
       v[i].push_back(y);
       }
   }
   int x=celeb(v,r);
   if(x==0){
   cout<<"celeb is "<<x+1;}
   else 
   cout<<"not found";
    return 0;
}