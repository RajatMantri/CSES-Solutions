#include <bits/stdc++.h>
using namespace std;
#define endi "\n"
#define yo printf("YES\n")
#define na printf("NO\n");

#define f first
#define s second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>

#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];

typedef long long ll;
const ll mod = 1e9 + 7;

const int N = 200005;
vector<int> g[N];

const static auto initialize = []
{ std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

vector<int> dp(N);
vector<int> order;
vector<int> o;
vector<int> vis(N);
int ans = 0;

void dfs(int cur)
{
    vis[cur] = 1;
    for (auto &i : g[cur])
    {
        if (!vis[i])
            dfs(i);
    }
    order.push_back(cur);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    dfs(1);
    reverse(order.begin(), order.end());

    dp[1] = 1;

    for (auto &i : order)
    {
        for (auto &j : g[i])
            dp[j] = (dp[j] + dp[i]) % mod;
    }

    cout << dp[n];
}

// rbegin() rend()
int32_t main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}