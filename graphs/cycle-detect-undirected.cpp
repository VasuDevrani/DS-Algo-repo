#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs_check(unordered_map<int, list<int>>l, unordered_map<int, bool>&visited, unordered_map<int, int>&parent, int src)
    {
        queue<int>q;
        
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto x:l[node])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    parent[x] = node;
                }
                else if (visited[x] && parent[node] != x)
                    return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int v, vector<int> adj[]) {
        unordered_map<int, list<int>>l;
        
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                l[i].push_back(adj[i][j]);
        }
        
        unordered_map<int, bool>visited;
        
        for(int i=0;i<v;i++)
            visited[i] = false;
            
        unordered_map<int, int>parent;
        
        for(int src=0;src<v;src++)
        {
            if(!visited[src]){
                if(bfs_check(l, visited, parent, src))
                return true;   
            }
        }
        return false;
    }
    
// _________________________________________________________________________________________________
// _________________________________________________________________________________________________

    bool dfs_check(vector<int> adj[], bool visited[], int parent, int node)
    {
        visited[node] = true;
        
        for(auto nbr: adj[node])
        {
            if(!visited[nbr])
            {
                if(dfs_check(adj, visited, node, nbr))
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }
    
    
    bool isCycle(int v, vector<int> adj[]) {
        
        bool* visited = new bool[v];
        
        for(int i=0;i<v;i++)
            visited[i] = false;
        
        for(int src=0;src<v;src++)
        {
            if(!visited[src]){
                if(dfs_check(adj, visited, -1, src))
                    return true;   
            }
        }
        return false;
    }
};