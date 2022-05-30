#include<bits/stdc++.h>
using namespace std;

vector<int> getSubsequence(vector<int>req, int i)
{
    int j=req.size()-1;
    vector<int>ans;
    while(i>0 && j>=0)
    {
        if((i&1)==1)
        ans.push_back(req[j]);
        
        i=i>>1;
        j--;
    }

    return ans;
}

int main()
{
    int primes[]={ 2,3,5,7,11,13,17,19 };

    int t;
    cin>>t;

    while(t--){
    int n;
    cin>>n;

    vector<int>req;
    for(int i=0;i<8;i++)
    {
        if(primes[i]<=n)
        req.push_back(primes[i]);
        else
        break;
    }

    long long tot = pow(2,req.size())-1;
    int ans=0;
    for(long long i=1;i<=tot;i++)
    {
        vector<int>temp=getSubsequence(req,i);
        long long mult=1;
        for(int i=0;i<temp.size();i++)
        {
            mult=mult*temp[i];
        }

        if(temp.size()%2==0)
            ans=ans-n/mult;
        else
            ans = ans + n/mult;
    }

    cout<<ans<<endl;
    }


    return 0; 
}