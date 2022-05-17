// this is a ladder up problem (can take at most 3 steps)
#include <bits/stdc++.h>
using namespace std;

vector<string>stairs(int n,int i)
{
    if(i==n)
    {vector<string>path;
    path.push_back("");
        return path;
    }
    if(i>n)
    {
        vector<string>crap;
        return crap;
    }
    vector<string>path1=stairs(n,i+1);
    vector<string>path2=stairs(n,i+2);
    vector<string>path3=stairs(n,i+3);
    vector<string>res;

    for(auto x:path1)
    {
        res.push_back(x+'1');
    }
    for(auto x:path2)
    {
        res.push_back(x+'2');
    }
    for(auto x:path3)
    {
        res.push_back(x+'3');
    }
    return res;
}


int main ()
{
   int n;
   cin>>n;
   int i=0;
  vector<string>res= stairs(n,i);
  for(auto x:res)
  {
      cout<<x<<" ";
  }
    return 0;
}