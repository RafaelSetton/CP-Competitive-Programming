#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vizinhos(2e5 + 10);
vector<bool> visitados(1e5 + 10);
queue<int> fila;
vector<int> pai(1e5 + 10, -1);

void bfs(int x)
{
    visitados[x] = true;
    for (int y : vizinhos[x])
        if (!visitados[y])
        {
            fila.push(y);
            visitados[y] = true;
            pai[y] = x;
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vizinhos[a].push_back(b);
        vizinhos[b].push_back(a);
    }
    fila.push(1);
    while (fila.size() > 0)
    {
        bfs(fila.front());
        fila.pop();
    }
    if (visitados[n])
    {
        vector<int> path = {n};
        int x = n;
        do
            x = pai[x], path.push_back(x);
        while (pai[x] != -1);

        cout << path.size() << endl;
        while (path.size() > 0)
            cout << path.back() << " ", path.pop_back();

        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}