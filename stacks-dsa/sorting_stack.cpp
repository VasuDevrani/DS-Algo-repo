#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>&s,int d)
{
// base case
    if(s.empty())
    {
        s.push(d);
        return;
    }
    if(s.top()<=d)
    {
        s.push(d);
        return;
    }
// recursive case
    int temp;
    if(s.top()>d)
    {
        temp=s.top();
        s.pop();
        sortedInsert(s,d);
        s.push(temp);
    }


}

void sort(stack<int>&s)
{
// base case
    if(s.size()==1)
    return;

// recursive case
    int temp=s.top();
    s.pop();
    sort(s);
    sortedInsert(s,temp);

}

int main ()
{
   stack<int>s;
   int n;
   cin>>n;
   while(n--)
   {
       int t;
       cin>>t;
       s.push(t);
   }
   sort(s);
   while(!s.empty())
   {
       cout<<s.top()<<" ";
       s.pop();
   }
   cout<<endl;

    return 0;
}








// void sort_(stack<int>&s,int n)
// { 
//     if(s.empty()||n>s.top()){
//        s.push(n);
//    }
//    else
//    { 
//        int temp=s.top();
//        s.pop();
//        sort_(s,n);
//        s.push(temp);
//    }
// }

// void extract(stack<int>&s)
// {   if(s.empty())
//     return;
//     int temp=s.top();
//     s.pop();
//     extract(s);
//     sort_(s,temp);
// }

// int main ()
// {
//     stack<int>s;
//     s.push(2);
//     s.push(5);
//     s.push(1);
//     s.push(4);
//     extract(s);
//    while(!s.empty())
//    {
//        int top=s.top();
//        cout<<top<<endl;
//        s.pop();
//    }
//     return 0;
// }
