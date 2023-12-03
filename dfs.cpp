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

    void dfs(vector<int> &ans, vector<int> &vis, int start)
    {
        stack<int> s;
        s.push(start);
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            ans.push_back(curr);
            vis[curr] = 1;
            for (auto depth : mp[curr])
            {
                if (!vis[depth])
                {
                    s.push(depth);
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
    g.dfs(ans, vis, 0);
    g.printgraph();
    cout << endl
         << "Print dfs " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}