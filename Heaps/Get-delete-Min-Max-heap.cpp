#include <iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;
    
    bool compare(int child,int parent){
        if(minHeap){
            return child<parent;
        }
        else{
             return child>parent;
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
    
    public:
    Heap(bool type=true){
        minHeap=type;
        v.push_back(-1);  //v[0]=-1(blocked)
    }
    
    //insert function
    void push(int data){
        v.push_back(data);
        
        int index=v.size()-1;
        int parent=index/2;
        
        while(index>1 && compare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
    //check if heap is empty or not
    bool empty(){
        return v.size()==1;
    }
    //to get the topmost element from heap: min.element in case of minHeap and max.element in case of maxHeap
    int top(){
        return v[1];
    }
    //to remove the topmost element from the heap
    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
};
int main() {
    Heap h1(true);
    
    int x;
    for(int i=0;i<10;i++)
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
