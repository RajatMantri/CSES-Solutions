#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find_U_parent(int node)
    {
        if (node == parent[node])
            return node;
        parent[node] = find_U_parent(parent[node]);
        return parent[node];
    }
    void reset(int n)
    {
        parent[n] = n;
        size[n] = 1;
    }
    void unionBySize(int u, int v)
    {
        int Ult_u = find_U_parent(u);
        int Ult_v = find_U_parent(v);
        if (Ult_u == Ult_v)
            return;
        if (size[Ult_u] > size[Ult_v])
        {
            parent[Ult_v] = Ult_u;
            size[Ult_u] += size[Ult_v];
        }
        else
        {
            parent[Ult_u] = Ult_v;
            size[Ult_v] += size[Ult_u];
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = -1;

    DisjointSet d(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        d.unionBySize(u, v);
    }

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        if (d.find_U_parent(i) == i)
        {
            ans++;
            res.push_back(i);
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] << " " << res[i + 1] << endl;
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