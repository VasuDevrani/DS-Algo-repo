#include <bits/stdc++.h>
using namespace std;
void check_rotated(vector<int>v,int r)
{
   vector<int>temp(v.size());
   for(int i=0;i<v.size();i++)
   {
       temp[(i+r)%v.size()]=v[i];
   }
   for(auto x:temp)
   {cout<<x<<" ";}
}
int main ()
{
   vector<int>v;
   int s;
   cin>>s;
   for(int i=0;i<s;i++)
   {
       int x;
       cin>>x;
       v.push_back(x);
   }
   int r;
   cin>>r;
   check_rotated(v,r);

    return 0;
}