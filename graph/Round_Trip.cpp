#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

vector<int> vis;
vector<int> par;

bool ok = 0;
int u, v;

void dfs(int node, int parent, vector<int> adj[])
{
    vis[node] = 1;
    par[node] = parent;
    for (auto &nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, node, adj);
        }
        else
        {
            if (parent != nbr)
            {
                if (ok)
                    return;
                ok = 1;
                u = node, v = nbr;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vis.resize(n + 1);
    par.resize(n + 1);

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
            dfs(i, i, adj);
    }

    if (!ok)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> ans;
    int init = u;

    while (u != v)
    {
        ans.push_back(u);
        u = par[u];
    }
    ans.push_back(v);
    ans.push_back(init);

    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << " ";
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