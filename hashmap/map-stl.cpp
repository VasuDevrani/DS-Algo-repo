// map is implemented using balanced BST
// time complexity because of bst is O(logn) on average

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;

    // Insertion in the map
    m.insert(make_pair("mango", 120));

    pair<string, int> p;
    p.first = "apple";
    p.second = 40;
    m.insert(p);

    m["litchi"]=20;
    m["papaya"]=30;
    m["kiwi"]=200;

    // find or search operation
    // here it is map<string,itn>::iterator it;
    auto it = m.find("apple");
    if(it!=m.end())
    cout<<m["apple"]<<endl;
    else
    cout<<"Not present"<<endl;

    // map stores unique keys so count function either returns 1 or 0
    if(m.count("apple"))
    cout<<m["apple"]<<endl;
    else
    cout<<"No"<<endl;

    // erase operations
    m.erase("apple");
    if(m.count("apple"))
    cout<<m["apple"]<<endl;
    else
    cout<<"No"<<endl;

//   iteration and traversal
    // the traversal is sorted as inorder bst traversal
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
        // or cout<<*it->first<<" "<<*it->second<<endl;
    }


    // updation operation
    m["papaya"]+=500;



    return 0;
}