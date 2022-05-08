#include <bits/stdc++.h>

using namespace std;

int MAX = 1010;

int n, m;
vector<vector<int>> mapa(MAX, vector<int>(MAX, 0));

vector<vector<int>> dist(MAX, vector<int>(MAX, -1));
vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int x, int y)
{
    if ((x >= 0) && (y >= 0) && (x < n) && (y < m))
        return (dist[x][y] == -1) && (mapa[x][y] != 0);
    return false;
}

int bfs(pair<int, int> start)
{
    queue<pair<int, int>> fila;
    fila.push(start);
    dist[start.first][start.second] = 1;
    while (fila.size() > 0)
    {
        pair<int, int> from = fila.front();
        for (auto next : movs)
        {
            int x2 = from.first + next.first, y2 = from.second + next.second;
            if (val(x2, y2))
            {
                fila.push({x2, y2});
                dist[x2][y2] = dist[from.first][from.second] + 1;
                if (mapa[x2][y2] == 3)
                    return dist[x2][y2];
            }
        }
        fila.pop();
    }
}

int main()
{
    int temp;
    cin >> n >> m;
    pair<int, int> start;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mapa[i][j];
            if (mapa[i][j] == 2)
                start = {i, j};
        }

    cout << bfs(start) << endl;

    return 0;
}