#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>>g;

    public:
    
    void addEdge(T x, T y)
    {
        // bidirectional graph
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // here src is the source node
    void bfs(T src){
        // need to make a visited map for keeping the uniqueness and a queue for traversal

        queue<T>q;
        map<T, bool>visited;

        q.push_back(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            while(auto x:g[node])
            {
                if(visited[x] == false)
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};