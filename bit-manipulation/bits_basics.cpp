#include<bits/stdc++.h>
using namespace std;

int find_ith_bit(int n,int i)
{
    int x=(1<<(i)) & n;
    if(x>0)
     return 1;
     else 
     return 0;
}

int clear_ith_bits(int n,int i)
{
     return (((~0)<<(i+1)) & n);
}

int clear_i_to_j_bits(int n,int i,int j)
{
     //this will need two parts a and b
    //  a can be 1000
    int a=1<<(j+1);

    // b can be 0001
    int b=(1<<i)-1;

    return a|b;
}

int count_bits(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans+=(n&1);  
        n=n>>1;
    }
    return ans;
}

int count_bits_fast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n& (n-1);
        ans++;
    }
    return ans;
}

int decimal_to_bin(int n)
{
    int ans=0,p=1;
    while(n>0)
    {
        ans+=p*(n%2);
        p*=10;
        n/=2;
    }
    return ans;
}

int dec_to_bin_fast(int n)
{
    int ans=0,p=1;
    while(n>0)
    {
        ans=ans+p*(n&1);
        n=n>>1;
        p=p*10;
    }
    return ans;
}

int main ()
{
    int n;
    cin>>n;
    cout<<find_ith_bit(n,1)<<endl;   // 1010 converts gives 1 at position 1st;

    cout<<clear_ith_bits(n,2)<<endl;    // this will clear the bit 1 at 2nd position of 10 i.e. 1010;

     cout<<clear_i_to_j_bits(15,1,2)<<endl;         // 1111 will get converted to 1001;

     cout<<count_bits(n)<<endl;  // sums up all bits or count number of 1s in 1010; time complexity being o(logn);

     cout<<count_bits_fast(n)<<endl;  //faster as time complexity being equal to number of bits in 1010;

    //  cout<<__builtin_popcount(n)<<endl;  inbuilt function for counting bits

     cout<<decimal_to_bin(n)<<endl;

     cout<<dec_to_bin_fast(n)<<endl;

    return 0;
}