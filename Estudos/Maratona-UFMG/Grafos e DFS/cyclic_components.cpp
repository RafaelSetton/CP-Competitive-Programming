#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<set<int>> vizinhos;
vector<bool> visitados;

void DFS(int x)
{
    visitados[x] = true;

    if (vizinhos[x].size() != 2)
        visitados[0] = false;

    for (auto y : vizinhos[x])
    {
        if (!visitados[y])
            DFS(y);
    }
}

int main()
{
    cin >> n >> m;
    vizinhos = vector<set<int>>(n + 1);
    visitados = vector<bool>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vizinhos[a].insert(b);
        vizinhos[b].insert(a);
    }
    int cycles = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (!visitados[i])
        {
            visitados[0] = true;
            DFS(i);
            if (visitados[0])
                cycles++;
        }
    }
    cout << cycles << endl;

    return 0;
}