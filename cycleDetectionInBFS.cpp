#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, list<int>> mp;

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

    void bfs(vector<int> &vis, int start)
    {
        int flag = 0;
        queue<int> q;
        map<int, int> parent;
        parent[start] = -1;
        q.push(start);
        while (!q.empty())
        {
            int frontnode = q.front();
            vis[frontnode] = 1;
            q.pop();
            for (auto chl : mp[frontnode])
            {
                if (vis[chl] == 1 && chl != parent[frontnode])
                {
                    flag = 1;
                    break;
                }

                else if (!vis[chl])
                {
                    q.push(chl);
                    parent[chl] = frontnode;
                }
            }
            if (flag)
            {
                cout << "Yes there is a cycle " << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "No cycle " << endl;
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

    vector<int> vis(n, 0);
    g.bfs(vis, 0);
    g.printgraph();

    return 0;
}