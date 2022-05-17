#include<bits/stdc++.h>
using namespace std;
void permo(string s, string b)
{
   if (s.length()==0)
   {
       cout<<b<<" ";
   }
    for(int i=0;i<s.length();i++)
    {
   char temp=s[i];
   string new_s;
   new_s=s.substr(0,i)+s.substr(i+1);
   permo(new_s,b+s[i]);
    }
}
int main ()
{
    string s;
    cin >>s;
    permo(s,"");
    return 0;
}

























/*#include<bits/stdc++.h>
using namespace std;

void permo(string s,string base)
{
    if (s.length()==0 )
    {
        cout<<base<<" ";
    }
    for (int i=0;i<s.length();i++)
    {
        char first=s[i];
    string last=s.substr(i+1)+s.substr(0,i);
    permo(last,base+first);
    }
}

int main ()
{
    string str;
    cin>>str;
    permo(str,"");
    return 0;
}*/