
// maze problem, can only move either forward or downward...

#include <bits/stdc++.h>
using namespace std;

vector<string>maze(int i,int j,int m,int n)
{
    if(i==m && j==n)
    {
        vector<string>ans;
        ans.push_back(""); //vector with size of 1 byte
        return ans;
    }
    if(i>m || j>n)
    {
        vector<string>ans; //empty vector
        return ans;
    }
    vector<string>path1=maze(i,j+1,m,n);
    vector<string>path2=maze(i+1,j,m,n);
    vector<string>paths;
    for(auto x:path1)
    {paths.push_back(x+'h'); }
     for(auto x:path2)
    {paths.push_back(x+'v'); }
   return paths;

}

int main ()
{ int sr,sc,r,c;
cin>>sr>>sc>>r>>c;
   vector<string>res=maze(sr,sc,r-1,c-1);
   for(auto x:res)
   {
       cout<<x<<endl;
   }
   cout<<res.size()<<" ways are there in total \n";

    return 0;
}