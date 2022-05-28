#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    int age;
    string name;

    Person(int age,string name)
    {
        this->age=age;
        this->name=name;
    }
};

// The comparators should be made via class and they must contain function operator overloaders
class Compare
{
public:

bool operator()(Person a, Person b)
{
    return a.age<b.age;
}
};

int main()
{
    priority_queue<Person,vector<Person>,Compare>q;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        string name;
        cin>>x>>name;

        Person p(x,name);
        q.push(p);

    }

    while(!q.empty())
    {
        cout<<q.top().name<<" "<<q.top().age<<endl;
        q.pop();
    }
    return 0;
}