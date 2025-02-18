#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

vector<int> cycle;
vector<int> par;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;
    par[node] = parent;

    for (auto &nbr : adj[node])
    {
        if (!vis[nbr])
            dfs(nbr, node, adj, vis, pathVis);
        else
        {
            if (pathVis[nbr] && cycle.empty())
            {
                int curr = node;
                cycle.push_back(nbr);
                while (curr != nbr)
                {
                    cycle.push_back(curr);
                    curr = par[curr];
                }
                cycle.push_back(nbr);
                reverse(cycle.begin(), cycle.end());
            }
        }
    }

    pathVis[node] = 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    par.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0, adj, vis, pathVis);
    }

    if (cycle.empty())
        cout << "IMPOSSIBLE";
    else
    {
        cout << cycle.size() << endl;
        for (auto &i : cycle)
            cout << i << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}