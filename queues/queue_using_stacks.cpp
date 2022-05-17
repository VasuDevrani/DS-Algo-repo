#include <bits/stdc++.h>
using namespace std;

class Queue{
     int *arr;
     int r;
     int f;
     public:
     Queue(int *arr,int a,int b){
         this->arr=arr;
         r=a;
         f=b;
     }
     void push(int n){
          arr[r]=n;
          r++;
     }
     void pop()
     {
         if(!empty()){
       arr[f]=-1;
       f++;}
       else 
       cout<<"invalid";
     }
     void front()
     {
       cout<<arr[f]<<endl;
     }
     bool empty()
     {
         if(f==r)
         return true;
         else 
         return false;
     }
     int size()
     {
        return r-f;
     }
};

int main (){
    int size=1000,n;
    int *arr=new int[size];
    Queue q(arr,0,0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    q.front();
    q.pop();
     q.pop();
     q.front();
     cout<<q.size()<<endl;
     cout<<q.empty()<<endl;
     q.pop();
     q.pop();
     q.pop();
     q.pop();
    return 0;
}