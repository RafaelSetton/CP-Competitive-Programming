#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010;

int n, m;
vector<string> mapa;
queue<pair<int, int>> fila;

vector<vector<pair<int, int>>> dis;
vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_val(pair<int, int> pos)
{
    if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m)
        return mapa[pos.first][pos.second] != '#';
    return false;
}

bool is_exit(pair<int, int> pos)
{
    if (pos.first == 0 || pos.second == 0 || pos.first == n - 1 || pos.second == m - 1)
        return mapa[pos.first][pos.second] == '.';
    return false;
}

pair<int, int> find_me()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mapa[i][j] == '@')
                return {i, j};
}

void bfs_multi()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mapa[i][j] == '*')
                fila.push({i, j}), dis[i][j].first = 0;

    while (fila.size() > 0)
    {
        pair<int, int> now = fila.front();
        // cout << "from " << now.first << " " << now.second << endl;
        for (auto next : movs)
        {
            next.first += now.first;
            next.second += now.second;
            if (is_val(next) && dis[next.first][next.second].first == -1)
            {
                dis[next.first][next.second].first = dis[now.first][now.second].first + 1;
                fila.push(next);
            }
        }
        fila.pop();
    }
}

int bfs_single()
{
    auto pos = find_me();
    fila.push(pos);
    dis[pos.first][pos.second].second = 0;
    while (fila.size() > 0)
    {
        auto now = fila.front();
        if (is_exit(now))
            return dis[now.first][now.second].second;
        for (auto next : movs)
        {
            next.first += now.first;
            next.second += now.second;
            if (is_val(next) && dis[next.first][next.second].second == -1)
            {
                dis[next.first][next.second].second = dis[now.first][now.second].second + 1;
                if (dis[next.first][next.second].second < dis[next.first][next.second].first)
                    fila.push(next);
            }
        }
        fila.pop();
    }
    return -1;
}

int main()
{
    int t;
    string temp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        mapa = vector<string>();
        dis = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>(MAX, {-1, -1}));
        fila = queue<pair<int, int>>();

        cin >> m >> n;
        cin.ignore();
        for (int j = 0; j < n; j++)
        {
            getline(cin, temp);
            mapa.push_back(temp);
        }

        bfs_multi();
        /*         for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < m; l++)
                        cout << dis[k][l].first << " ";
                    cout << endl;
                } */
        int d = bfs_single();

        if (d == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << d + 1 << endl;
    }

    return 0;
}
