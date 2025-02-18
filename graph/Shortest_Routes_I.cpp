#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, int> mp;

    vector<int> d(n + 1, 1e18);
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        pair<int, int> mm = {u, v};
        if (mp.count(mm) == 0)
            mp[mm] = wt;
        mp[mm] = min(mp[mm], wt);
    }

    for (auto &i : mp)
        adj[i.first.first].push_back({i.first.second, i.second});

    d[1] = 0;
    set<pair<int, int>> s;
    s.insert({0, 1});

    while (!s.empty())
    {
        auto it = s.begin();
        int node = it->second;
        s.erase(it);

        for (auto &i : adj[node])
        {
            int wt = i.second, nbr = i.first;
            if (d[nbr] > d[node] + wt)
            {
                if (d[nbr] != 1e18)
                    s.erase({d[nbr], nbr});
                s.insert({d[node] + wt, nbr});
                d[nbr] = d[node] + wt;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
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