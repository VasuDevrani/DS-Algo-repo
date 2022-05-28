// In order to get min sum of connecting ropes each time the min sized ropes should be connected
// if this ques was to done using array then first we need to insert a sum and then sort the array and continue the same until single element is left in array


#include <bits/stdc++.h>
using namespace std;

int getSum(vector<int>v)
{
    // initializing the queue with array elements
    priority_queue<int,vector<int>,greater<int>>q(v.begin(),v.end());
    int sum=0;
    while(q.size()>1)
    {
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();

        int temp=a+b;
        sum+=temp;
        q.push(temp);
    }
    return sum;
}

int main ()
{
    vector<int>v={4,3,2,6};
    cout<<getSum(v)<<endl;

    return 0;
}