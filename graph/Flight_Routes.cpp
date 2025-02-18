#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<vector<int>> d(n + 1, vector<int>(k, 1e15));
    d[1][0] = 0;

    multiset<pair<int, int>> ss; // dist,node
    ss.insert({0, 1});

    while (!ss.empty())
    {
        auto it = ss.begin();
        int node = it->second, dist = it->first;
        ss.erase(it);

        if (d[node][k - 1] < dist)
            continue;

        for (auto &i : adj[node])
        {
            int nbr = i.first, wt = i.second;
            if (d[nbr][k - 1] > dist + wt)
            {
                d[nbr][k - 1] = dist + wt;
                sort(d[nbr].begin(), d[nbr].end());
                ss.insert({dist + wt, nbr});
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << d[n][i] << " ";
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