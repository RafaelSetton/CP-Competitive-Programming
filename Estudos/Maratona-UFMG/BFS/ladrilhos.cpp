#include <bits/stdc++.h>

using namespace std;

int MAX = 210;

int H, L;
vector<vector<int>> mapa(MAX, vector<int>(MAX, -1));
vector<vector<bool>> visitados(MAX, vector<bool>(MAX, false));
vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int x, int y)
{
    if ((x >= 0) && (y >= 0) && (x < H) && (y < L))
        return !visitados[x][y];
    return false;
}

int bfs(int x, int y)
{
    visitados[x][y] = true;

    int area = 0;

    for (auto next : movs)
    {
        int x2 = x + next.first, y2 = y + next.second;
        if (val(x2, y2) && (mapa[x][y] == mapa[x2][y2]))
            area += bfs(x2, y2);
    }

    return (area > 0) ? area + 1 : 1;
}

int main()
{
    int temp;
    cin >> H >> L;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < L; j++)
            cin >> mapa[i][j];

    int min_size = H * L;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < L; j++)
            if (!visitados[i][j])
                min_size = min(min_size, bfs(i, j));

    cout << min_size << endl;

    return 0;
}