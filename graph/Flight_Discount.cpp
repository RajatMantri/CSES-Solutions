#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<vector<int>> d(n + 1, vector<int>(2, 1e18));
    set<pair<int, pair<int, int>>> ss;
    ss.insert({0, {1, 1}});
    d[1][0] = 0;
    // d[1][1]=0;

    while (!ss.empty())
    {
        auto it = ss.begin();
        int node = it->second.first;
        int p = it->second.second;
        ss.erase(it);

        for (auto &i : adj[node])
        {
            int nbr = i.first, wt = i.second;
            if (p)
            {
                if (d[nbr][1] > d[node][0] + wt / 2)
                {
                    ss.erase({d[nbr][1], {nbr, 0}});
                    d[nbr][1] = d[node][0] + wt / 2;
                    ss.insert({d[nbr][1], {nbr, 0}});
                }
                if (d[nbr][0] > d[node][0] + wt)
                {
                    ss.erase({d[nbr][0], {nbr, 1}});
                    d[nbr][0] = d[node][0] + wt;
                    ss.insert({d[nbr][0], {nbr, 1}});
                }
            }
            else
            {
                if (d[nbr][1] > d[node][1] + wt)
                {
                    ss.erase({d[nbr][1], {nbr, 0}});
                    d[nbr][1] = d[node][1] + wt;
                    ss.insert({d[nbr][1], {nbr, 0}});
                }
            }
        }
    }

    cout << d[n][1] << endl;
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