#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string firstName;
    string secondName;
    int rollNo;

    Student(string firstName,
            string secondName,
            int rollNo)
            {
                this->firstName=firstName;
                this->secondName=secondName;
                this->rollNo=rollNo;
            }
// in case of collision
    bool operator == (const Student &s)
    const {
        return rollNo == s.rollNo;
    }
};

class Hashfun
{
    public:
    size_t operator()(const Student &s)
    const {
        return s.firstName.length() + s.secondName.length(); 
    }
};

int main()
{

    unordered_map<Student, int, Hashfun>m;

    Student s1("vasu", "devrani", 1);
    Student s2("vasu", "devrani", 1);
    Student s3("prateek", "narang", 10);
    Student s4("anshaj", "deval", 13);
    Student s5("toqueer", "khan", 25);
    Student s6("super", "man", 100);

    // in order to store the keys as the customm class object we need to define the Hasfun and also a == operator


    m[s1]=1;
    m[s2]=2;
    m[s3]=3;
    m[s4]=4;

    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first.firstName<<" "<<(*it).first.secondName<<" "<<(*it).first.rollNo<<" "<<(*it).second<<endl;
    }

    return 0;
}