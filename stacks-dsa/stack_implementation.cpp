// The stack can be implemented using linked list as well be inserting the elements in front

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class stacke{
   vector<T>v;

   public:
   void push(T data)
   {
       v.push_back(data);
   }
   void pop()
   {
       if(v.size()!=0)
       v.pop_back();
   }
   T top()
   {
       return v[v.size()-1];
   }
   bool isempty()
   {
       return v.size()==0;
   }
};

int main ()
{
    stacke<int>s1;
    stacke<char>s2;
     
    for(int i=65;i<80;i++)
    {
        s1.push(i);
        s2.push(i);
    }
    while(!s1.isempty() && !s2.isempty())
    {
        cout<<s1.top()<<" "<<s2.top()<<endl;
        s1.pop();
        s2.pop();
    }


    return 0;
}