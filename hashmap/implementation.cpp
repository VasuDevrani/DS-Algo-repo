#include<bits/stdc++.h>
#include"Hashtable.h"
using namespace std;

int main ()
{
    Hashtable<int>h;
    h.insert("vasu",11);
    h.insert("amsn",13);
    h.insert("anshaj",100);
    h.insert("nikhil",26);
    h.insert("srishti",44);
    h.insert("monu",12);
    h.insert("gazala",56);

    h.print();

    return 0;
}