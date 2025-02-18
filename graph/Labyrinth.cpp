#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -4));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    string ans = "NO";

    while (!q.empty())
    {
        auto it = q.front();
        int i = it.first, j = it.second;
        q.pop();

        if (grid[i][j] == 'B')
        {
            ans = "YES";
            cout << ans << "\n";
            string path;
            while (grid[i][j] != 'A')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = dirx[k] + i, y = diry[k] + j;
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if (dist[x][y] != dist[i][j] - 1 || grid[x][y] == '#')
                        continue;
                    path.push_back(dir[k]);
                    i = x, j = y;
                }
            }
            cout << path.length();
            reverse(path.begin(), path.end());
            cout << "\n"
                 << path << endl;
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int x = dirx[k] + i, y = diry[k] + j;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (dist[x][y] != -4 || grid[x][y] == '#')
                continue;
            dist[x][y] = dist[i][j] + 1;
            q.push({x, y});
        }
    }

    cout << ans << "\n";
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