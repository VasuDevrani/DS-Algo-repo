#include <bits/stdc++.h>
using namespace std;

void sum_it(int n, int t, int arr[], int i, vector<stack<int>> &ans, stack<int> &temp, int sum)
{
    //    base case
    if (sum > t)
        return;
    if (sum == t)
    {
        ans.push_back(temp);
        return;
    }
    
    // recursive case
    for (int j = i; j < n; j++)
    {
        temp.push(arr[j]);
        sum_it(n, t, arr, j+1, ans, temp, sum + arr[j]);
        temp.pop();
    }
}

    int main()
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int target;
        cin >> target;

        sort(arr, arr + n);
        vector<stack<int>> ans;
        stack<int> temp;
        sum_it(n, target, arr, 0, ans, temp, 0);

        
        for(int i=0;i<ans.size()-1;i++)
        {
            for(int j=i+1;j<ans.size();j++)
            {
                if(ans[i]==ans[j])
                ans.erase(ans.begin()+j);
            }
        }

        for(int i=0;i<ans.size();i++)
        {
            while(!ans[i].empty())
            {
                cout<<ans[i].top()<<" ";
                ans[i].pop();
            }
            cout<<endl;
        }

        return 0;
    }