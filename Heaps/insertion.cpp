// Heap is a datastructure that is visualised using a binary tree but uses a vector for implementation

#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    vector<int>v; //for storing the values
    bool minHeap; //for checking min or max type of heap

    Heap(int default_size=10,bool minHeap=false){
        v.reserve(default_size);
        v.push_back(-1); //blocks the zeroth position as tree nodes are visualised from very first position

        this->minHeap=minHeap;
    }
    
    bool compare(int parent,int child)
    {
        if(minHeap)
        return parent>child;
        else
        return parent<child;
    }

    void push(int d)
    {
        v.push_back(d);

        int childInd=v.size()-1;
        int parent=childInd/2;
        while(childInd>1 && compare(v[childInd],v[parent]))
        {
            swap(v[childInd],v[parent]);
            childInd=parent;
            parent=childInd/2;
        }
    }
};
int main ()
{
    Heap h1(4,true);

    return 0;
}