#include<bits/stdc++.h>
using namespace std;

class Graph
{
    // using key as the nodes and value in the form of list as the connections 
    unordered_map<string, list<pair<string,int>>>l; //here pair is of the next node i.e. string ans weight of edge

    public:
    void addEdge(string x, string y, bool bidirec, int w){
        l[x].push_back(make_pair(y,w));
        if(bidirec){
            l[y].push_back(make_pair(x,w));
        }
    }

    void printGraph(){
        for(auto v:l) //vertices
        {
            cout<<"vertices "<<v.first<<" -> ";
            for(auto e:v.second){ //edge
                cout<<'('<<e.first<<','<<e.second<<')'<<" ";
            }
            cout<<endl;
        }
    }
};

int main ()
{
    Graph g;

    g.addEdge("A","B",true,10);
    g.addEdge("B","C",false,20);
    g.addEdge("A","D",false,30);
    g.addEdge("D","E",true,50);

    g.printGraph();

    return 0;
}