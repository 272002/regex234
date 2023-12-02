#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> mp;

    void addedge(int u, int v, bool direction)
    {
        mp[u].push_back(v);

        // direction == 0 creating undirected graph
        // direction == 1 creating directed graph
        if (direction == 0)
        {
            mp[v].push_back(u);
        }
    }

    void printgraph()
    {
        for (auto i : mp)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(vector<int> &ans, vector<int> &vis, int start)
    {
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int frontnode = q.front();
            ans.push_back(frontnode);
            vis[frontnode] = 1;
            q.pop();
            for (auto chl : mp[frontnode])
            {
                if (!vis[chl])
                {
                    q.push(chl);
                    vis[chl] = 1;
                }
            }
        }
    }
};

int main()
{
    int n, m;
    graph g;
    cout << "Enter the number of node " << endl;
    cin >> n;
    cout << "Enter the number of edges " << endl;
    cin >> m;

    int u, v;
    for (int j = 0; j < m; j++)
    {
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    vector<int> ans;
    vector<int> vis(n, 0);
    g.bfs(ans, vis, u);
    g.printgraph();
    cout << endl
         << "Print bfs " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << " ";
    }

    return 0;
}