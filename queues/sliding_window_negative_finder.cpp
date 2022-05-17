#include <bits/stdc++.h>
using namespace std;
int check_negative(int a,int b)
{
    if (a<0)
    return a;
    else if(b<0)
    return b;
    else 
    return 0;
    
}
void window(queue<int>q, int n)
{
    for(int i=1;i<n;i++)
    {
        int a=q.front();
        q.pop();
        int b=q.front();
        cout<<check_negative(a,b)<<endl;
    }
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
    window(q,n);

    return 0;
}