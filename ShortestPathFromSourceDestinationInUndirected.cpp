#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int src, int dst)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    parent[src] = -1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                parent[neighbour] = node;
                visited[neighbour] = 1;
            }
        }
    }

    vector<int> ans;
    ans.push_back(dst);
    int Current_Node = dst;
    while (Current_Node != src)
    {
        Current_Node = parent[Current_Node];
        ans.push_back(Current_Node);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int edges;
    cin >> edges;

    cout << endl
         << "Enter graph nodes " << endl;
    unordered_map<int, list<int>> adj;
    int el1, el2;
    for (int i = 0; i < edges; i++)
    {
        cin >> el1 >> el2;
        adj[el1].push_back(el2);
        adj[el2].push_back(el1);
    }
    int src, dst;
    cout << endl
         << "Enter source and destination node " << endl;
    cin >> src >> dst;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    bfs(adj, visited, parent, src, dst);

    return 0;
}
