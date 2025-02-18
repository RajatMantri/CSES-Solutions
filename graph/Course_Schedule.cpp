#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

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

    vector<int> in(n + 1, 0);

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            in[x]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> o;

    while (!q.empty())
    {
        int node = q.front();
        o.push_back(node);
        q.pop();

        for (auto &nbr : adj[node])
        {
            in[nbr]--;
            if (in[nbr] == 0)
                q.push(nbr);
        }
    }

    if (o.size() == n)
    {
        for (auto &i : o)
            cout << i << " ";
    }
    else
        cout << "IMPOSSIBLE";
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