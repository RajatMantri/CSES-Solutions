#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define ll long long

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

void solve()
{
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    vector<vector<int>> dist1(n, vector<int>(m, 1e9));
    vector<vector<int>> dist2(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
            if (grid[i][j] == 'A')
            {
                q1.push({i, j});
                dist1[i][j] = 0;
            }
        }
    }

    while (!q1.empty())
    {
        auto it = q1.front();
        int i = it.first, j = it.second;
        q1.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = dirx[k] + i, y = diry[k] + j;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (dist1[x][y] != 1e9 || grid[x][y] == '#')
                continue;
            dist1[x][y] = dist1[i][j] + 1;
            q1.push({x, y});
        }
    }

    while (!q2.empty())
    {
        auto it = q2.front();
        int i = it.first, j = it.second;
        q2.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = dirx[k] + i, y = diry[k] + j;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (dist2[x][y] != 1e9 || grid[x][y] == '#')
                continue;
            dist2[x][y] = dist2[i][j] + 1;
            q2.push({x, y});
        }
    }

    bool ok = 0;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        if (dist2[i][0] > dist1[i][0])
        {
            ok = 1;
            x = i, y = 0;
            break;
        }
        if (dist2[i][m - 1] > dist1[i][m - 1])
        {
            ok = 1;
            x = i, y = m - 1;
            break;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (dist2[0][j] > dist1[0][j])
        {
            ok = 1;
            x = 0, y = j;
            break;
        }
        if (dist2[n - 1][j] > dist1[n - 1][j])
        {
            ok = 1;
            x = n - 1, y = j;
            break;
        }
    }

    if (!ok)
        cout << "NO";
    else
    {
        cout << "YES\n";
        string path;
        while (grid[x][y] != 'A')
        {
            for (int k = 0; k < 4; k++)
            {
                int i = dirx[k] + x, j = diry[k] + y;
                if (i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                if (dist1[i][j] != dist1[x][y] - 1 || grid[i][j] == '#')
                    continue;
                path.push_back(dir[k]);
                x = i, y = j;
            }
        }
        cout << path.length();
        reverse(path.begin(), path.end());
        cout << "\n"
             << path << endl;
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