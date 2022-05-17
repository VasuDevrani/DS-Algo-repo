#include<bits/stdc++.h>
using namespace std;

void generate_strings(string s,int n,int i,string ans)
{
    // base case
    if(i==n)
    {
        cout<<ans<<endl;
        return;
    }
    if(i>n)
    return;


    // recursive case
      int one=s[i]-'0';
      
      generate_strings(s,n,i+1,ans+(char)(one+64));
      if(i<n-1){
          string t="";
      int two=stoi(t+s[i]+s[i+1]);

      if(two<=26)
      {
          generate_strings(s,n,i+2,ans+(char)(two+64));
      }
      }
      return;
}


int main ()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   generate_strings(s,n,0,"");

    return 0;
}