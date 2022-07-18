#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int, list<int>>g;

    public:

    void addEdge(int x, int y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void count_Dist_from_src(int src)
    {
        // create a distance array with all nodes are marked at infinite dist from src
        map<int, int>dist;
        queue<int>q;

        for(auto x:g)
        {
            int node = x.first;
            dist[node] = INT_MAX;
        }

        dist[src] = 0;
        q.push(src);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto x:g[node])
            {
                if(dist[x] == INT_MAX)
                {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
            }
        }

        for(auto x:g)
        {
            cout<<"shortest dist of "<<x.first<<" from src node is "<<dist[x.first]<<endl;
        }
    }
};

int main ()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,4);

    g.count_Dist_from_src(0);

    return 0;
}
