#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long
const int N = 1002;
int vis[N][N];

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};

void dfs(int i, int j, char grid[N][N], int vis[N][N], int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int x = dirx[k] + i, y = diry[k] + j;
        if (!vis[x][y] && grid[x][y] == '.')
            dfs(x, y, grid, vis, n, m);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    char grid[N][N];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                count++;
                dfs(i, j, grid, vis, n, m);
            }
        }
    }

    cout << count;
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