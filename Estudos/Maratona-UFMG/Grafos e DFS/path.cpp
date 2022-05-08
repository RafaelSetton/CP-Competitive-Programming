#include <bits/stdc++.h>

using namespace std;

vector<bool> visitados;
vector<vector<int>> vizinhos;

int DFS(int path, int node)
{
    visitados[node] = true;
    vector<int> poss;
    for (int next : vizinhos[node])
    {
        if (!visitados[next])
            poss.push_back(DFS(path + 1, next));
    }
    if (poss.size() > 0)
        return *max_element(poss.begin(), poss.end());
    else
        return path;
}

int main()
{
    int n;
    cin >> n;
    vizinhos = vector<vector<int>>(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        vizinhos[a].push_back(b);
        vizinhos[b].push_back(a);
    }
    int MAX = 0;
    for (int i = 1; i < n + 1; i++)
    {
        visitados = vector<bool>(n);
        MAX = max(MAX, DFS(0, i));
    }

    cout << MAX << endl;
    return 0;
}