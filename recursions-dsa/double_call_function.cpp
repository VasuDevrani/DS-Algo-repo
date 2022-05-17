#include <bits/stdc++.h>
using namespace std;
 void doub(int n)
 {
     if(n==0)
     return;
    cout<<"Pre"<<n<<endl;
    doub(n-1);
    cout<<"In"<<n<<endl;
    doub(n-1);
    cout<<"Post"<<n<<endl;

 }
 int main ()
 {int n;
 cin>>n;
 doub(n);

     return 0;
 }