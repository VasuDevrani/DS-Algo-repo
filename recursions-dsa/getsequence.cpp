#include<bits/stdc++.h>
using namespace std;
/* for gettting the subsequece and storing it 
vector<string>seq(string s)
{
    if(s.length()==0)
    {
        vector<string>slast;
        slast.push_back("");
        return slast;
    }
   char first=s[0];
   string left=s.substr(1);
   vector<string>str=seq(left);
  vector<string>snew;
   for(auto x:str){
       snew.push_back(x);}
   int n=snew.size();
   for (int i=0;i<n;i++)
   {
       string temp=first+snew[i];
       snew.push_back(temp);
   }
   return snew;
}*/
 
//  for printing the subsequence (as storing in stack is not feasible in case of large data)


void sbseq(string s,string a)
{
    if (s.length()==0) //at the end of recurion stack
    {
        cout<<a<<"  ";
        return;
    }

   char first=s[0];
   string left=s.substr(1);
   sbseq(left,a+first);
   sbseq(left,a+"");

}

int main()
{
   string s;
   cin>>s;
   sbseq(s,"");
    return 0;
}