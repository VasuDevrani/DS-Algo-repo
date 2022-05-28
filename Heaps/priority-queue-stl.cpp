#include<bits/stdc++.h>
using namespace std;
int main ()
{
    // initially the heap is max heap but we can pass a comparator to convert it into a minHeap
    // maxHeap
    priority_queue<int>q;
    // minHeap
    priority_queue<int,vector<int>,greater<int>>q1;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        // logn insertion
        q.push(x);
        q1.push(x);
    }

    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    while(!q1.empty())
    {
        cout<<q1.top()<<" ";
        q1.pop();
    }

    return 0;
}