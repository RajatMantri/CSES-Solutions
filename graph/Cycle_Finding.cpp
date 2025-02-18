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
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        e[i] = {{u, v}, wt};
    }

    vector<int> d(n + 1, 0);
    vector<int> par(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        for (auto &j : e)
        {
            int u = j.first.first, v = j.first.second, wt = j.second;
            if (d[u] + wt < d[v])
            {
                d[v] = d[u] + wt;
                par[v] = u;
            }
        }
    }

    int node = -1;

    for (auto &j : e)
    {
        int u = j.first.first, v = j.first.second, wt = j.second;
        if (d[u] + wt < d[v])
        {
            node = v;
            d[v] = d[u] + wt;
            par[v] = u;
        }
    }

    if (node == -1)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        node = par[node];
    }

    int curr = node;
    vector<int> ans;
    ans.push_back(curr);
    curr = par[curr];

    while (curr != node)
    {
        ans.push_back(curr);
        curr = par[curr];
    }

    ans.push_back(curr);

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
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