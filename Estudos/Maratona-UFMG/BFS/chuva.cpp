#include <bits/stdc++.h>

using namespace std;

int MAX = 510;

int n, m;
vector<string> parede(MAX);
vector<vector<bool>> visitados(MAX, vector<bool>(MAX, false));

int find_o()
{
    for (int j = 0; j < m; j++)
        if (parede[0][j] == 'o')
            return j;
}

void dfs(int x, int y)
{
    visitados[x][y] = true;
    if (x == n - 1)
        return;
    if (parede[x + 1][y] == '#')
    {
        if (!visitados[x][y - 1])
            dfs(x, y - 1), parede[x][y - 1] = 'o';
        if (!visitados[x][y + 1])
            dfs(x, y + 1), parede[x][y + 1] = 'o';
    }
    else
        dfs(x + 1, y), parede[x + 1][y] = 'o';
}

int main()
{
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
        getline(cin, parede[i]);

    int y_goteira = find_o();
    visitados[0][y_goteira] = true;
    dfs(0, y_goteira);

    for (int i = 0; i < n; i++)
        cout << parede[i] << endl;

    return 0;
}