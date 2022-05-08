#include <bits/stdc++.h>

using namespace std;

bool cmp(set<int> x, set<int> y) { return x.size() < y.size(); }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> vizinhos(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vizinhos[a].insert(b);
        vizinhos[b].insert(a);
    }

    int menor = min_element(vizinhos.begin() + 1, vizinhos.end(), cmp) - vizinhos.begin();

    vector<int> police(n + 1, 1);
    police[menor] = 0;
    for (int i : vizinhos[menor])
        police[i] = 0;
    for (int i = 1; i < n + 1; i++)
        cout << police[i] << " ";
    cout << endl;

    return 0;
}