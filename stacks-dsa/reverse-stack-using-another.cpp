#include<bits/stdc++.h>
using namespace std;

int main ()
{
    stack<int>s;
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        s.push(i);
    }

    stack<int>temp;
    int a;

    for(int i=n-2;i>=1;i--)
    {
       a=s.top();
       s.pop();
       int j=i;
       while(j--)
       {
           temp.push(s.top());
           s.pop();
       }
       s.push(a);
       while(!temp.empty())
       {
           s.push(temp.top());
           temp.pop();
       }
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}