#include<bits/stdc++.h>
using namespace std;

int string_to_int(char arr[],int n)
{
    if(n==0)
    return 0;
    
    int num=arr[n-1]-'0';
    return string_to_int(arr,n-1)*10+num;
}

int main ()
{
    int n;
    cin>>n;
    char str[n];
    cin>>str;
 
    cout<<string_to_int(str,n)<<endl<<sizeof(string_to_int(str,n));
    return 0;
}