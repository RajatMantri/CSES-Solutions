#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

vector<int> col;
vector<int> vis;

bool ok = 1;

void dfs(int node, vector<int> adj[])
{
    vis[node] = 1;
    for (auto &nbr : adj[node])
    {
        if (!vis[nbr])
        {
            col[nbr] = !col[node];
            dfs(nbr, adj);
        }
        else
        {
            if (col[nbr] == col[node])
                ok = 0;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    col.resize(n + 1);
    vis.resize(n + 1);

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, adj);
    }

    if (!ok)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 1; i <= n; i++)
        cout << col[i] + 1 << " ";
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