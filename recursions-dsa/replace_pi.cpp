#include<bits/stdc++.h>
using namespace std;

void replace_pi(string s,int i,vector<char>&v)
{
    //  base case
    if(i>=s.length())
    {
          for(auto x:v)
          cout<<x;
          return;
    }

    if(s[i]=='p' && s[i+1]=='i')
    {
        v.insert(v.end(), {'3','.','1','4'});
        i++;
    }
    else
    {
        v.push_back(s[i]);
    }
    // recursive case
    replace_pi(s,i+1,v);
}

int main ()
{
   string s;
   cin>>s;
   vector<char>v;
   replace_pi(s,0,v);
    return 0;
}