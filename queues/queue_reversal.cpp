// can solve it by stacks as well by storing the elements in a stack;
// time compplexity O(n)
// space complexity O(n2)

#include<bits/stdc++.h>
using namespace std;

queue<int>reverse_queue(queue<int>&q)
{
    if(q.size()==0)
    {
        return q;
    }
    int temp=q.front();
    q.pop();
    reverse_queue(q);
    q.push(temp);
    return q;
}

int main ()
{
   queue<int>q;
   int n;
   cin>>n;
   for (int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       q.push(x);
   }
   reverse_queue(q);
   for(int i=0;i<n;i++)
   {
       cout<<q.front()<<endl;
       q.pop();

   }
    return 0;
}