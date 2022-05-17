#include<bits/stdc++.h>
using namespace std;

int ladder(int n,int i)
{
    // base
    if(i>n)
    return 0;
    else if(i==n)
    return 1;

    // recursion
    int x=ladder(n,i+1);
    int y=ladder(n,i+2);
    int z=ladder(n,i+3);

    // return
    return x+y+z;

}

int main ()
{
   int n;
   cin>>n;
   cout<<ladder(n,0);
    return 0;
}