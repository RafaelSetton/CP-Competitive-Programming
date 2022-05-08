#include <bits/stdc++.h>

using namespace std;
int L, C;
vector<string> mapa;
vector<bool> visitados(1e4 + 10);
pair<int, int> pos;

vector<pair<int, int>> vizinhos(pair<int, int> cell)
{
    vector<pair<int, int>> res;
    int x = cell.first, y = cell.second;
    if (x > 0)
        res.push_back({x - 1, y});
    if (y > 0)
        res.push_back({x, y - 1});
    if (x < L - 1)
        res.push_back({x + 1, y});
    if (y < C - 1)
        res.push_back({x, y + 1});
    return res;
}

pair<int, int> find_o()
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            if (mapa[i][j] == 'o')
                return {i, j};
}

void dfs(pair<int, int> cell)
{
    int x = cell.first, y = cell.second;
    visitados[x * C + y] = true;
    for (auto next : vizinhos(cell))
    {
        int x2 = next.first, y2 = next.second;
        if ((mapa[x2][y2] == 'H') && !visitados[x2 * C + y2])
        {
            pos = next;
            dfs(next);
            return;
        }
    }
}

int main()
{
    string temp;
    cin >> L >> C;
    cin.ignore();
    for (int i = 0; i < L; i++)
    {
        getline(cin, temp);
        mapa.push_back(temp);
    }
    pair<int, int> start = find_o();
    dfs(start);
    cout << pos.first + 1 << " " << pos.second + 1 << endl;
}