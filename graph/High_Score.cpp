#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> e(m);
    bool check = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        e[i] = {{u, v}, -wt};
        if (u == v && u == 1)
        {
            if (wt > 0)
                check = 1;
        }
    }

    vector<int> d(n + 1, 1e18);
    d[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &j : e)
        {
            int u = j.first.first, v = j.first.second, wt = j.second;
            if (d[u] != 1e18)
                d[v] = min(d[u] + wt, d[v]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &j : e)
        {
            int u = j.first.first, v = j.first.second, wt = j.second;
            if (d[u] != 1e18 && d[u] + wt < d[v])
            {
                d[v] = -1e18;
            }
        }
    }

    if (d[n] == -1e18 || check)
        d[n] = 1;

    cout << -d[n] << endl;
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