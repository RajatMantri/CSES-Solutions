#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e18));

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        d[u][v] = min(d[u][v], wt);
        d[v][u] = min(d[v][u], wt);
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int via = 1; via <= n; via++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][via] != 1e18 && d[via][j] != 1e18)
                    d[i][j] = min(d[i][j], d[i][via] + d[via][j]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (d[u][v] == 1e18)
            d[u][v] = -1;

        cout << d[u][v] << endl;
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