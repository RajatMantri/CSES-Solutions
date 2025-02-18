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
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    dist[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &nbr : adj[node])
        {
            if (dist[nbr] == -1)
            {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << dist[n] << endl;
    int node = n;
    vector<int> ans;
    while (node != 1)
    {
        ans.push_back(node);
        for (auto &nbr : adj[node])
        {
            if (dist[nbr] == dist[node] - 1)
            {
                node = nbr;
                break;
            }
        }
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
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