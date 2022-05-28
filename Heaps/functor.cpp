// Functors are operators overloaded as function
// These are also called function class objects

#include<bits/stdc++.h>
using namespace std;

class Func{
    public:
    void operator()(string s){
        cout<<"hello "<<s<<endl;
    }
    void function(string s)
    {
        cout<<"another hello "<<s<<endl;
    }
};

int main ()
{
    Func f;
    f("vasu");
    f.function("vasu");
    f.operator()("vasu");
    
    return 0;
}