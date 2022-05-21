#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>v;
    bool minHeap;

    bool compare(int child,int parent)
    {
        if(minHeap)
        return parent>child;
        else
        return parent<child;
    }

    public:

    Heap(int default_size=10,bool minHeap=false){
        v.reserve(default_size);
        v.push_back(-1);
        this->minHeap=minHeap;
    }

    void push(int d)
    {
        v.push_back(d);
        int child=v.size()-1;
        int parent=child/2;

        while(parent>1 && compare(child,parent))
        {
            swap(v[parent],v[child]);
            child=parent;
            parent=child/2;
        }
    }

    int get()
    {
        return v[1];
    }
    void pop()
    {
        // first take the top binary tree element to end of the vector and pop it
        swap(v[1],v[v.size()-1]);
        v.pop_back();

        // Now reposition the top element to maintain the min or max validation
        

    }
};

int main ()
{


    return 0;
}