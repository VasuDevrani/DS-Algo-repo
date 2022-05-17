// time complexity of the function O(n)
// space complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int circular_tour( vector<pair<int,int>>v)
{int i=0,r=0;
int j=0;
   while(i<v.size())
   {
        r=v[i].first+r-v[i].second;
       if(r>=0)
       {
          i++;
       }
       else {
       j=i+1;
       i++;}
       if(i==j)
       return i+1;
   }
}

int main()
{
  vector<pair<int,int>>v;
  int n;
  cin>>n;
  for (int i=0;i<n;i++)
  {
      pair<int,int>p;
      cin>>p.first>>p.second;
      v.push_back(p);
  }
  cout<<circular_tour(v);

    return 0;
}