#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>chk={4,7,47,74,44,77,444,447,474,744,747,777,477};
    int n;
    cin >> n;
    for(int i=0;i<chk.size();i++)
    {
        if(n%chk[i]==0)
        {
            cout<<"yes"<<endl;     
            return 0;   
        }
    }
    int rem=0;
    while(n>0)
    {
        rem=n%10;
        n=n/10;
        if(rem!=4 || rem!=7)
        {
            cout<<"no"<<endl;
            break;
        }
    }

    return 0;
}