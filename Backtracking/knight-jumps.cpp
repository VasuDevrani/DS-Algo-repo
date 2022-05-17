#include<bits/stdc++.h>
using namespace std;

void knightMoves(int n,int a,int b,int i,vector<vector<int>>&chess){
// base case
   if(a<0 || b<0 || a>=n || b>=n || i>n*n || chess[a][b]>0)
   return;

   if(i==n*n)
   {
       chess[a][b]=i;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               cout<<chess[i][j]<<" ";
           }
           cout<<endl;
       }
       chess[a][b]=0;
       cout<<endl;
       return;
   }

// recursive case
   chess[a][b]=i;
   knightMoves(n,a-2,b+1,i+1,chess);
    knightMoves(n,a-1,b+2,i+1,chess);
    knightMoves(n,a+1,b+2,i+1,chess);
    knightMoves(n,a+2,b+1,i+1,chess);
    knightMoves(n,a+2,b-1,i+1,chess);
    knightMoves(n,a+1,b-2,i+1,chess);
    knightMoves(n,a-1,b-2,i+1,chess);
    knightMoves(n,a-2,b-1,i+1,chess);
   chess[a][b]=0;
}

int main ()
{
   int n,a,b;
   cin>>n>>a>>b;
   vector<vector<int>>chess(n,vector<int>(n,0));
   knightMoves(n,a,b,1,chess);

    return 0;
}


  