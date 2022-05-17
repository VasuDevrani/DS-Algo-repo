#include <bits/stdc++.h>
using namespace std;
void knights(int i,int j,int r, int c,vector<vector<int>>chess,int d)
{
  if(i<0||j<0||i>r||j>c||chess[i][j]!=0)
  {
    return;
  }
  if (d==25)
  {
    chess[i][j]=d;
     for(int k=0;k<r;k++)
  {
    for(int s=0;s<c;s++)
    {
      cout<<chess[k][s]<<" ";
    }
    cout<<endl;
  }
    return;
  }
  chess[i][j]=d;
   knights(i-2,j-1,r,c,chess,d+1);
   knights(i-1,j-1,r,c,chess,d+1);
   knights(i-1,j+2,r,c,chess,d+1);
   knights(i+2,j+1,r,c,chess,d+1);
   knights(i+2,j-1,r,c,chess,d+1);
   knights(i+1,j-2,r,c,chess,d+1);
   knights(i-1,j-2,r,c,chess,d+1);
   knights(i-2,j-1,r,c,chess,d+1);
   chess[i][j]=0;
}

int main ()
{
   int r,c,sc,sr;
   cin>>r>>c>>sc>>sr;
   vector<vector<int>>chess;
   for(int i=0;i<r;i++)
   {
     for(int j=0;j<c;j++)
     chess[i][j]=0;
   }
   knights(sr,sc,r,c,chess,1);

  return 0;
}