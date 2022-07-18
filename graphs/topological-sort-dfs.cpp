#include <bits/stdc++.h>
using namespace std;

void dfs(bool visited[], stack<int> &stk, vector<int> adj[], int node)
{
    visited[node] = true;

    for (auto x : adj[node])
    {
        if (!visited[x])
            dfs(visited, stk, adj, x);
    }

    stk.push(node);
}

vector<int> topoSort(int v, vector<int> adj[])
{
    stack<int> stk;
    bool *visited = new bool[v];

    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int src = 0; src < v; src++)
    {
        if (visited[src] == false)
            dfs(visited, stk, adj, src);
    }

    vector<int> ans;

    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}