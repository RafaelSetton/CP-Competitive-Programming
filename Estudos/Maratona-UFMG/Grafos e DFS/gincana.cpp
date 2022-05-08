#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vizinhos;
vector<bool> visitados;

void DFS(int v)
{
    visitados[v] = true;
    for (int w : vizinhos[v])
        if (!visitados[w])
            DFS(w);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vizinhos = vector<vector<int>>(n + 1);
    visitados = vector<bool>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vizinhos[a].push_back(b);
        vizinhos[b].push_back(a);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visitados[i])
        {
            DFS(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}