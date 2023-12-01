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

    void print()
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

    g.print();
    return 0;
}