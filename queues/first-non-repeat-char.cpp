#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin>>s;

    int arr[26]={0};  //for keeping the frequency of characters
    queue<char>q;   //for holding the front non repeated element which is removed if repeated at any later time
    vector<char>ans;

    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-'a']++;
        if(arr[s[i]-'a']<=1){
         q.push(s[i]);
         ans.push_back(q.front());
        }
        else 
        {
            while(!q.empty() && arr[q.front()-'a']>1)
            {
                q.pop();
            }
            if(q.empty())
            ans.push_back('0');
            else
            ans.push_back(q.front());
        }
    }

    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}