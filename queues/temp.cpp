// Use stl 

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class deq{
    T *arr;
    int ms;
    int cs;
    int f,r;

    public:
    deq(int ds=5)
    {
        arr=new T[ds];
        f=0;
        cs=0;
        ms=ds;
        r=ms-1;
    }
    bool full()
    {
        return cs==ms;
    }
    bool empty()
    {
        return cs==0;
    }
    void pop_front()
    {
        if(!empty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }
    void push_back(T d)
    {
        if(!full())
        {
            r=(r+1)%ms;
            arr[r]=d;
            cs++;
        }
    }
    void push_front(T d)
    {
        if(f!=0)
        {
            f=(f-1)%ms;
            arr[f]=d;
            cs++;
        }
        else
        {
            f=ms-1;
        }
    }
    void pop_back()
    {
        r=(r-1)%ms;
        cs--;
    }
    T front()
    {
        return arr[f];
    }
    T back()
    {
        return arr[r];
    }

    ~deq(){
        delete(arr);
        arr=NULL;
    }
};

int main ()
{
    deq<int>q;

    q.push_front(2);
    q.push_front(3);
    q.push_front(4);
    q.push_front(5);

    cout<<q.front()<<endl;

    q.pop_front();

    cout<<q.front()<<endl;

    q.push_back(9);

    cout<<q.back()<<endl;


    return 0;
}