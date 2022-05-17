// Anti- clockwise rotation by 90degree

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&arr,int r,int c)
{
    //  row reversal
    // can reverse using inbuilt reverse function in stl as, reverse(arr[i],arr[i]+n);
    for(int i=0;i<r;i++)
    {
        int sc=0,ec=c-1;
        while(sc<ec)
        {
            swap(arr[i][sc],arr[i][ec]);
            sc++;
            ec--;
        }
    }

    // transpose

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<j)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
}


int main ()
{
    int r,c;
    cin>>r>>c;
     vector<vector<int>>arr(r);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            arr[i].push_back(x);
        }
    }

    rotate(arr,r,c);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}