#include<bits/stdc++.h>
using namespace std;

bool dfs(bool visited[], bool got_dfs[], int node, vector<int>adj[])
    {
        visited[node] = true;
        got_dfs[node] = true;
        
        for(auto x:adj[node])
        {
            if(!visited[x]){
                if(dfs(visited, got_dfs, x, adj))
                    return true; 
            }
            else if(got_dfs[x])
                return true;
        }
        
        got_dfs[node] = false;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        
        bool* visited = new bool[v];
        bool* got_dfs = new bool[v];
        
        for(int i=0;i<v;i++)
        {
            got_dfs[i] = false;
            visited[i] = false;
        }
        
        for(int src=0;src<v;src++)
        {
            if(dfs(visited, got_dfs, src, adj))
                return true;
        }
        return false;
    }