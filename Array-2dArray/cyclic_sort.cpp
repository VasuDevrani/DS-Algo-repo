// Time complexity O(n)
// space complexity O(n)

#include <bits/stdc++.h>
using namespace std;

void cyclic_sort(vector<int>&v)
{
    int i=0;
    while(i<v.size())
    {
        int pos=v[i]-1;
        if(i<pos)
        {
            swap(v[i],v[pos]);
        }
        else
        i++;
    }
}

int main ()
{
   vector<int>v={3,5,2,6,1,4};
   cyclic_sort(v);
   for(auto x:v)
   cout<<x<<" ";

    return 0;
}