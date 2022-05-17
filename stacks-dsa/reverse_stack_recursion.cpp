// time complexity O(n2);
// space complexity O(n2) that is max height of recursive tree;

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s,int d)
{
    // base case
   if(s.empty())
   {
       s.push(d);
       return;
   }

//    recursive case
    int temp=s.top();
    s.pop();
    insertAtBottom(s,d);
    s.push(temp);

}

stack<int>reverse_stack(stack<int>&s)
{
    // base case
     if(s.empty())
     return s;

    // recursive case
    int temp=s.top();
    s.pop();

    reverse_stack(s);
    insertAtBottom(s,temp);
    return s;

}
int main () 
{
   stack<int>s; int num;
   cin>>num;
   for (int i=0;i<num;i++)
   {int t;
       cin>>t;
       s.push(t);
   }
   stack<int>s1=s;
   while(!s1.empty())
   {
       cout<<s1.top()<<" ";
       s1.pop();
   }
   cout<<endl;
   reverse_stack(s);

   while(!s.empty())
   {
       cout<<s.top()<<" ";
       s.pop();
   }


    return 0;
}