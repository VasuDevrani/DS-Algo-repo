#include <bits/stdc++.h>
using namespace std;
void reverse_string(string s)
{
   stack<char>l;
   for(int i=0;i<s.length();i++)
   l.push(s[i]);
   while(s.empty()!=true)
   {
       cout<<l.top();
       l.pop();
   }
}
int main ()
{
  string type;
  getline(cin,type);
  reverse_string(type);

    return 0;
}