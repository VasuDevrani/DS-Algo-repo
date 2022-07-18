#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>>g;

    public:
    void addEdge(T x, T y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void dfs_helper(int src, map<T, bool>&visited){
        cout<<src<<" ";
        visited[src] = true;

        for(auto x:g[src])
        {
            if(!visited[x])
            {
                dfs_helper(x, visited);
            }
        }
        return ;
    }

    void dfs(T src){
        // keeping a visited array
        map<T, bool>visited;

        // marking all as false
        for(auto x : g)
        {
            visited[x.first] = false;
        }

        // call for recursive dfs traversal
        dfs_helper(src, visited);
    }

};

int main ()
{
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,4);

    g.dfs(0);

    return 0;
}