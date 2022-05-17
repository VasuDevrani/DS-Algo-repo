#include<bits/stdc++.h>
using namespace std;

template<typename T>
class queuee{
    T *arr;
    int ms;
    int cs;
    int f,r;

    public:
    queuee(int ds=5)
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
    void pop()
    {
        if(!empty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }
    void push(T d)
    {
        if(!full())
        {
            r=(r+1)%ms;
            arr[r]=d;
            cs++;
        }
    }
    T front()
    {
        return arr[f];
    }

    ~queuee(){
        delete(arr);
        arr=NULL;
    }
};

int main ()
{
    queuee<int>q1;

    q1.push(2);
    q1.push(3);
    q1.push(6);
    q1.push(4);
    q1.push(5);

    cout<<q1.front()<<endl;

    q1.pop();
    q1.pop();

    cout<<q1.front()<<endl;


    return 0;
}