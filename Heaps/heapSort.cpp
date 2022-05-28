// time complexity being O(n) + (nlogn) one due to build heap method and nlogn due to heapify for each element 
// Heap sort
// this sorting technique involves heapification of array and then sending the top max or min element to the end via swap

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

    void heapifySort(vector<int>&arr,int i,int n)
    {
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        if(left<n && compare(arr[i],arr[left])){
            minIndex=left;
        }
        if(right<n && compare(arr[minIndex],arr[right])){   
            minIndex=right;
        }
        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
            heapifySort(arr,minIndex,n);
        }
    }

    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        if(left<v.size() && compare(v[left],v[i])){
            minIndex=left;
        }
        if(right<v.size() && compare(v[right],v[minIndex])){   
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

    void heapSort(vector<int>&arr)
    {
        int n=arr.size();
        buildHeap_better(arr);

        while(n>1)
        {
            swap(arr[1],arr[n-1]);
            n--;
            heapifySort(arr,1,n);
        }
    }
};

int main ()
{
    // true gives decreasing order of elements
    // false gives increasing order of elements
    Heap h1(true);
    
    int x;
    for(int i=0;i<9;i++)
    {
        cin>>x;
        h1.push(x);
    }

    vector<int>arr={-1,10,20,5,6,1,2,3,4};
    h1.heapSort(arr);

    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
   
    return 0;
}