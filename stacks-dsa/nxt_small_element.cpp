// time complexity O(n)
// space complexity O(n) 

#include <bits/stdc++.h>
using namespace std;

void nxt_small(int v[], int n)
{ stack<int>s;
   s.push(v[n-1]);
   int c=0;
  for (int i=n-2;i>=0;i--)
  { while(c==0){
    if(s.empty())
    {
       cout<<"next smallest element is "<<-1<<endl;
       s.push(v[i]);
       c++;
    }
     else if(v[i]>s.top()){
     cout<<"next smallest element is "<<s.top()<<endl;
     s.push(v[i]);
     c++;
     }
     else
     s.pop();
  }
  c=0;
  }
  
}

int main ()
{
   int n;
   cin>>n;
   int arr[n];
    for (int i=0;i<n;i++)
    { cin>>arr[i];
    }
    cout<<"next smallest element is "<<-1<<endl;
    nxt_small(arr,n);

  return 0;
}