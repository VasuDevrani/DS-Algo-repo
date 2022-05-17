// question is to count number of strings of length N with no consnecutive ones

#include<bits/stdc++.h>
using namespace std;

int string_bin(int n )
{
    //  base
    if(n<=0)
    return 1;

    // recursive
       return string_bin(n-1)+string_bin(n-2);

    //    another method
    //   if(i!=1){
    //  int x=string_bin(n-1,0);
    //  int y=string_bin(n-1,1);
    //  return x+y;
    //   }
    //  else
    //  {
    //      return string_bin(n-1,0);
    //  }

}

int main ()
{
   int n;
   cin>>n;
//    cout<<string_bin(n,0)+string_bin(n,1);
   cout<<string_bin(n);

    return 0;
}