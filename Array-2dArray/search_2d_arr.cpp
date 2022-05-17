#include<iostream>
using namespace std;
int main ()
{
    int m,n;
    cin>>m>>n;

    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    
    int key;
    cin>>key;

    // searching via linear search takes O(n2)
    // searching each row via binary search takes O(nlogn)

    // pointer or seeker method takes O(n)
    int i=0,j=n-1;
    while(1)
    {
        if(arr[i][j]==key)
        break;
        else if(arr[i][j]<key)
        i++;
        else if(arr[i][j]>key)
        j--;
        
    }

    cout<<i<<" "<<j<<endl;

    return 0;
}