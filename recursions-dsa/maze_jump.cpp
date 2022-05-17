
#include <bits/stdc++.h>
using namespace std;

vector<string>mazejump(int sc,int sr,int m,int n)
{
   if(sc==m &&sr==n)
   {
       vector<string>temp;
       temp.push_back("");
       return temp;
   }
   vector<string>paths;
    for(int i=0;i<=m;i++)
    {
        vector<string>hpath=mazejump(sc+i,sr,m,n);
       for(auto x:hpath)
       { 
            paths.push_back('h'+x);
       }
    }
     for(int i=0;i<=n;i++)
    {
        vector<string>vpath=mazejump(sc,sr+i,m,n);
       for(auto x:vpath)
       { 
            paths.push_back('v'+x);
       }
    }
     for(int i=0;i<=m && i<=n;i++)
    {
        vector<string>dpath=mazejump(sc+i,sr+i,m,n);
       for(auto x:dpath)
       { 
            paths.push_back('d'+x);
       }
    }
    return paths;
}
int main ()
{
    int sc,sr,m,n;
   cin>>sc>>sr>>m>>n;
   vector<string>res=mazejump(sc,sr,m-1,n-1);
   for(auto x:res)
   {
       cout<<x<<" ";
   }

    return 0;
}