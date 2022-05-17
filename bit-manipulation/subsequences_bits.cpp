// time complexity is O(n)


#include<bits/stdc++.h>
using namespace std;

void print_sub(int i,char str[],int n)
{
    if(i==0)
    cout<<" ";
    int j=0;
    while(i>0)
    {
       if(i&1==1)
       cout<<str[j];
       else 
       cout<<"_";
       j++;
       i=i>>1;
    }
}

int main ()
{
    char str[100];
    int n;
    cin>>n;
    cin>>str;
    int h=pow(2,n);
    
    for(int i=0;i<h;i++)
    {
        print_sub(i,str,n);
        cout<<endl;
    }


    return 0;
}