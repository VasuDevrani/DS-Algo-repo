#include<bits/stdc++.h>
using namespace std;

void print_maze(int sc,int sr,int r,int c,string path)
{
    if(sc==c &&sr==r)
    {
        cout<<path<<" ";
    }
    if(sc>c || sr>r)
    {
        return;
    }
    print_maze(sc,sr+1,r,c,path+"h");
    print_maze(sc+1,sr,r,c,path+"v");
}

int main ()
{
   int sr,sc,r,c;
   cin>>sc>>sr>>r>>c;
   string h;
   print_maze(sc,sr,r,c,h);

    return 0;
}