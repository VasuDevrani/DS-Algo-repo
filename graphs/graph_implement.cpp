// Graph implementation based on adjency list

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v; //number of vertices
    list<int>*l; //collection/array of list that will contain the data of edges

    public:
    Graph(int v){
        this->v = v;
        // creating a list for each vertices that's gonna contain connection of vertices
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printList(){
        for(int i=0;i<v;i++)
        {
            cout<<"Vertices "<<i<<" -> ";
            for(auto x: l[i])
            {
                cout<<x<<" ";;
            }
            cout<<endl;
        }
    }
};

int main ()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.printList();

    return 0;
}