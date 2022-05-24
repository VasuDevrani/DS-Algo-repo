// time complexity being o(nlogn)

#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>v;
    bool minHeap;

    bool compare(int parent, int child)
    {
        if(minHeap)
        return parent>child;
        else
        return parent<child;
    }

    public:

    Heap(bool type=true)
    {
        v.push_back(-1);
        this->minHeap=type;
    }

    void push(int d)
    {
        v.push_back(d);
        int i=v.size()-1;
        int parent=i/2;

        while(i>1 && compare(v[parent],v[i]))
        {
            swap(v[parent],v[i]);
            i=parent;
            parent=parent/2;
        }
    }

    void heapify(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        if(left<v.size() && compare(v[i],v[left])){
            minIndex=left;
        }
        if(right<v.size() && compare(v[minIndex],v[right])){   
            minIndex=right;
        }
        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }

    bool empty(){
        return v.size()==1;
    }
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }

    int top()
    {
        return v[1];
    }

    void heapifyNew(vector<int>&vec,int i)
    {
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        if(left<vec.size() && compare(vec[i],vec[left])){
            minIndex=left;
        }
        if(right<vec.size() && compare(vec[minIndex],vec[right])){   
            minIndex=right;
        }
        if(minIndex!=i){
            swap(vec[i],vec[minIndex]);
            heapifyNew(vec,minIndex);
        }
    }

    void buildHeap_better(vector<int>&vec)
    {
        for(int i=(vec.size()-1)/2;i>=1;i--)
        {
            heapifyNew(vec,i);
        }
    }
};

int main ()
{
    Heap h1(false);
    
    int x;
    for(int i=0;i<9;i++)
    {
        cin>>x;
        h1.push(x);
    }

    cout<<h1.top()<<endl;
    while(!h1.empty())
    {
        cout<<h1.top()<<" ";
        h1.pop();
    }

   
    return 0;
}