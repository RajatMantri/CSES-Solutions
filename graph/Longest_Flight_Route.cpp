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

    vector<int> par(n + 1, 0);
    vector<int> in(n + 1, 0);
    vector<int> ans(n + 1, -1e9);
    // vector<int> check(n + 1, 0);
    // check[1]=1;

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
            par[i] = i;
            // ans[i]=1;
        }
    }

    ans[1] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &nbr : adj[node])
        {
            if (ans[node] + 1 > ans[nbr])
            {
                ans[nbr] = ans[node] + 1;
                par[nbr] = node;
            }

            in[nbr]--;
            if (in[nbr] == 0)
                q.push(nbr);
        }
    }

    vector<int> order;
    order.push_back(n);
    int node = n;

    while (node != par[node] && node != 1)
    {
        node = par[node];
        order.push_back(node);
    }
    reverse(order.begin(), order.end());

    if (node != 1)
        cout << "IMPOSSIBLE";
    else
    {
        cout << ans[n] << endl;
        for (int i = 0; i < order.size(); i++)
            cout << order[i] << " ";
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